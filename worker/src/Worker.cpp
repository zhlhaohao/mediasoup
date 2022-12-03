#define MS_CLASS "Worker"
// #define MS_LOG_DEV_LEVEL 3

#include "Worker.hpp"
#include "ChannelMessageRegistrator.hpp"
#include "DepLibUV.hpp"
#include "DepUsrSCTP.hpp"
#include "FBS/response_generated.h"
#include "FBS/worker_generated.h"
#include "Logger.hpp"
#include "MediaSoupErrors.hpp"
#include "Settings.hpp"
#include "Channel/ChannelNotifier.hpp"

/* Instance methods. */

Worker::Worker(::Channel::ChannelSocket* channel) : channel(channel)
{
	MS_TRACE();

	// Set us as Channel's listener.
	this->channel->SetListener(this);

	// Set the SignalHandler.
	this->signalsHandler = new SignalsHandler(this);

	// Set up the RTC::Shared singleton.
	this->shared = new RTC::Shared(
	  /*channelMessageRegistrator*/ new ChannelMessageRegistrator(),
	  /*channelNotifier*/ new Channel::ChannelNotifier(this->channel));

#ifdef MS_EXECUTABLE
	{
		// Add signals to handle.
		this->signalsHandler->AddSignal(SIGINT, "INT");
		this->signalsHandler->AddSignal(SIGTERM, "TERM");
	}
#endif

	// Create the Checker instance in DepUsrSCTP.
	DepUsrSCTP::CreateChecker();

	// Tell the Node process that we are running.
	this->shared->channelNotifier->Emit(
	  std::to_string(Logger::pid), FBS::Notification::Event::WORKER_RUNNING);

	MS_DEBUG_DEV("starting libuv loop");
	DepLibUV::RunLoop();
	MS_DEBUG_DEV("libuv loop ended");
}

Worker::~Worker()
{
	MS_TRACE();

	if (!this->closed)
		Close();
}

void Worker::Close()
{
	MS_TRACE();

	if (this->closed)
		return;

	this->closed = true;

	// Delete the SignalsHandler.
	delete this->signalsHandler;

	// Delete all Routers.
	for (auto& kv : this->mapRouters)
	{
		auto* router = kv.second;

		delete router;
	}
	this->mapRouters.clear();

	// Delete all WebRtcServers.
	for (auto& kv : this->mapWebRtcServers)
	{
		auto* webRtcServer = kv.second;

		delete webRtcServer;
	}
	this->mapWebRtcServers.clear();

	// Delete the RTC::Shared singleton.
	delete this->shared;

	// Close the Checker instance in DepUsrSCTP.
	DepUsrSCTP::CloseChecker();

	// Close the Channel.
	this->channel->Close();
}

flatbuffers::Offset<FBS::Worker::DumpResponse> Worker::FillBuffer(
  flatbuffers::FlatBufferBuilder& builder) const
{
	// Add webRtcServerIds.
	std::vector<flatbuffers::Offset<flatbuffers::String>> webRtcServerIds;
	for (const auto& kv : this->mapWebRtcServers)
	{
		auto& webRtcServerId = kv.first;

		webRtcServerIds.push_back(builder.CreateString(webRtcServerId));
	}

	// Add routerIds.
	std::vector<flatbuffers::Offset<flatbuffers::String>> routerIds;
	for (const auto& kv : this->mapRouters)
	{
		auto& routerId = kv.first;

		routerIds.push_back(builder.CreateString(routerId));
	}

	auto channelMessageHandlers = this->shared->channelMessageRegistrator->FillBuffer(builder);

	return FBS::Worker::CreateDumpResponseDirect(
	  builder, Logger::pid, &webRtcServerIds, &routerIds, channelMessageHandlers);
}

flatbuffers::Offset<FBS::Worker::ResourceUsageResponse> Worker::FillBufferResourceUsage(
  flatbuffers::FlatBufferBuilder& builder) const
{
	MS_TRACE();

	int err;
	uv_rusage_t uvRusage; // NOLINT(cppcoreguidelines-pro-type-member-init)

	err = uv_getrusage(std::addressof(uvRusage));

	if (err != 0)
		MS_THROW_ERROR("uv_getrusagerequest() failed: %s", uv_strerror(err));

	return FBS::Worker::CreateResourceUsageResponse(
	  builder,
	  // Add ru_utime (uv_timeval_t, user CPU time used, converted to ms).
	  (uvRusage.ru_utime.tv_sec * static_cast<uint64_t>(1000)) + (uvRusage.ru_utime.tv_usec / 1000),
	  // Add ru_stime (uv_timeval_t, system CPU time used, converted to ms).
	  (uvRusage.ru_stime.tv_sec * static_cast<uint64_t>(1000)) + (uvRusage.ru_stime.tv_usec / 1000),
	  // Add ru_maxrss (uint64_t, maximum resident set size).
	  uvRusage.ru_maxrss,

	  // Add ru_ixrss (uint64_t, integral shared memory size).
	  uvRusage.ru_ixrss,

	  // Add ru_idrss (uint64_t, integral unshared data size).
	  uvRusage.ru_idrss,

	  // Add ru_isrss (uint64_t, integral unshared stack size).
	  uvRusage.ru_isrss,

	  // Add ru_minflt (uint64_t, page reclaims, soft page faults).
	  uvRusage.ru_minflt,

	  // Add ru_majflt (uint64_t, page faults, hard page faults).
	  uvRusage.ru_majflt,

	  // Add ru_nswap (uint64_t, swaps).
	  uvRusage.ru_nswap,

	  // Add ru_inblock (uint64_t, block input operations).
	  uvRusage.ru_inblock,

	  // Add ru_oublock (uint64_t, block output operations).
	  uvRusage.ru_oublock,

	  // Add ru_msgsnd (uint64_t, IPC messages sent).
	  uvRusage.ru_msgsnd,

	  // Add ru_msgrcv (uint64_t, IPC messages received).
	  uvRusage.ru_msgrcv,

	  // Add ru_nsignals (uint64_t, signals received).
	  uvRusage.ru_nsignals,
	  // Add ru_nvcsw (uint64_t, voluntary context switches).
	  uvRusage.ru_nvcsw,
	  // Add ru_nivcsw (uint64_t, involuntary context switches).
	  uvRusage.ru_nivcsw);
}

RTC::Router* Worker::GetRouter(const std::string& routerId) const
{
	MS_TRACE();

	auto it = this->mapRouters.find(routerId);

	if (it == this->mapRouters.end())
		MS_THROW_ERROR("Router not found");

	return it->second;
}

void Worker::CheckNoWebRtcServer(const std::string& webRtcServerId) const
{
	if (this->mapWebRtcServers.find(webRtcServerId) != this->mapWebRtcServers.end())
		MS_THROW_ERROR("a WebRtcServer with same webRtcServerId already exists");
}

void Worker::CheckNoRouter(const std::string& routerId) const
{
	if (this->mapRouters.find(routerId) != this->mapRouters.end())
		MS_THROW_ERROR("a Router with same routerId already exists");
}

RTC::WebRtcServer* Worker::GetWebRtcServer(const std::string& webRtcServerId) const
{
	auto it = this->mapWebRtcServers.find(webRtcServerId);

	if (it == this->mapWebRtcServers.end())
		MS_THROW_ERROR("WebRtcServer not found");

	return it->second;
}

inline void Worker::HandleRequest(Channel::ChannelRequest* request)
{
	MS_TRACE();

	// TODO: Remove when every request is ported to flatbuffers.
	MS_ERROR(
	  "Channel request received [method:%s, id:%" PRIu32 "]", request->methodStr.c_str(), request->id);

	switch (request->method)
	{
		case Channel::ChannelRequest::Method::WORKER_CLOSE:
		{
			if (this->closed)
				return;

			MS_DEBUG_DEV("Worker close request, stopping");

			Close();

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_DUMP:
		{
			auto dumpOffset = FillBuffer(request->GetBufferBuilder());

			request->Accept(FBS::Response::Body::FBS_Worker_DumpResponse, dumpOffset);

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_GET_RESOURCE_USAGE:
		{
			auto resourceUsageOffset = FillBufferResourceUsage(request->GetBufferBuilder());

			request->Accept(FBS::Response::Body::FBS_Worker_ResourceUsageResponse, resourceUsageOffset);

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_UPDATE_SETTINGS:
		{
			Settings::HandleRequest(request);

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_CREATE_WEBRTC_SERVER:
		{
			try
			{
				auto body = request->data->body_as<FBS::Worker::CreateWebRtcServerRequest>();

				std::string webRtcServerId = body->webRtcServerId()->str();

				CheckNoWebRtcServer(webRtcServerId);

				auto* webRtcServer = new RTC::WebRtcServer(this->shared, webRtcServerId, body->listenInfos());

				this->mapWebRtcServers[webRtcServerId] = webRtcServer;

				MS_DEBUG_DEV("WebRtcServer created [webRtcServerId:%s]", webRtcServerId.c_str());

				request->Accept();
			}
			catch (const MediaSoupTypeError& error)
			{
				MS_THROW_TYPE_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}
			catch (const MediaSoupError& error)
			{
				MS_THROW_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_WEBRTC_SERVER_CLOSE:
		{
			RTC::WebRtcServer* webRtcServer{ nullptr };

			auto body = request->data->body_as<FBS::Worker::CloseWebRtcServerRequest>();

			auto webRtcServerId = body->webRtcServerId()->str();

			try
			{
				webRtcServer = GetWebRtcServer(webRtcServerId);
			}
			catch (const MediaSoupError& error)
			{
				MS_THROW_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}

			// Remove it from the map and delete it.
			this->mapWebRtcServers.erase(webRtcServer->id);

			delete webRtcServer;

			MS_DEBUG_DEV("WebRtcServer closed [id:%s]", webRtcServer->id.c_str());

			request->Accept();

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_CREATE_ROUTER:
		{
			auto body = request->data->body_as<FBS::Worker::CreateRouterRequest>();

			auto routerId = body->routerId()->str();

			try
			{
				CheckNoRouter(routerId);
			}
			catch (const MediaSoupError& error)
			{
				MS_THROW_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}

			auto* router = new RTC::Router(this->shared, routerId, this);

			this->mapRouters[routerId] = router;

			MS_DEBUG_DEV("Router created [routerId:%s]", routerId.c_str());

			request->Accept();

			break;
		}

		case Channel::ChannelRequest::Method::WORKER_CLOSE_ROUTER:
		{
			RTC::Router* router{ nullptr };

			auto body = request->data->body_as<FBS::Worker::CloseRouterRequest>();

			auto routerId = body->routerId()->str();

			try
			{
				router = GetRouter(routerId);
			}
			catch (const MediaSoupError& error)
			{
				MS_THROW_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}

			// Remove it from the map and delete it.
			this->mapRouters.erase(router->id);

			delete router;

			MS_DEBUG_DEV("Router closed [id:%s]", router->id.c_str());

			request->Accept();

			break;
		}

		// Any other request must be delivered to the corresponding Router.
		default:
		{
			try
			{
				auto* handler =
				  this->shared->channelMessageRegistrator->GetChannelRequestHandler(request->handlerId);

				if (handler == nullptr)
				{
					MS_THROW_ERROR("Channel request handler with ID %s not found", request->handlerId.c_str());
				}

				handler->HandleRequest(request);
			}
			catch (const MediaSoupTypeError& error)
			{
				MS_THROW_TYPE_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}
			catch (const MediaSoupError& error)
			{
				MS_THROW_ERROR("%s [method:%s]", error.what(), request->methodStr.c_str());
			}

			break;
		}
	}
}

inline void Worker::HandleNotification(Channel::ChannelNotification* notification)
{
	MS_TRACE();

	MS_DEBUG_DEV("Channel notification received [event:%s]", notification->event.c_str());

	try
	{
		auto* handler =
		  this->shared->channelMessageRegistrator->GetChannelNotificationHandler(notification->handlerId);

		if (handler == nullptr)
		{
			MS_THROW_ERROR(
			  "Channel notification handler with ID %s not found", notification->handlerId.c_str());
		}

		handler->HandleNotification(notification);
	}
	catch (const MediaSoupTypeError& error)
	{
		MS_THROW_TYPE_ERROR("%s [event:%s]", error.what(), notification->eventStr.c_str());
	}
	catch (const MediaSoupError& error)
	{
		MS_THROW_ERROR("%s [method:%s]", error.what(), notification->eventStr.c_str());
	}
}

inline void Worker::OnChannelClosed(Channel::ChannelSocket* /*socket*/)
{
	MS_TRACE_STD();

	// Only needed for executable, library user can close channel earlier and it is fine.
#ifdef MS_EXECUTABLE
	// If the pipe is remotely closed it may mean that mediasoup Node process
	// abruptly died (SIGKILL?) so we must die.
	MS_ERROR_STD("channel remotely closed, closing myself");
#endif

	Close();
}

inline void Worker::OnSignal(SignalsHandler* /*signalsHandler*/, int signum)
{
	MS_TRACE();

	if (this->closed)
		return;

	switch (signum)
	{
		case SIGINT:
		{
			if (this->closed)
				return;

			MS_DEBUG_DEV("INT signal received, closing myself");

			Close();

			break;
		}

		case SIGTERM:
		{
			if (this->closed)
				return;

			MS_DEBUG_DEV("TERM signal received, closing myself");

			Close();

			break;
		}

		default:
		{
			MS_WARN_DEV("received a non handled signal [signum:%d]", signum);
		}
	}
}

inline RTC::WebRtcServer* Worker::OnRouterNeedWebRtcServer(
  RTC::Router* /*router*/, std::string& webRtcServerId)
{
	MS_TRACE();

	RTC::WebRtcServer* webRtcServer{ nullptr };

	auto it = this->mapWebRtcServers.find(webRtcServerId);

	if (it != this->mapWebRtcServers.end())
	{
		webRtcServer = it->second;
	}

	return webRtcServer;
}
