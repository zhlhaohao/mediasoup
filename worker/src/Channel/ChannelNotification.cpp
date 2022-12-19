#define MS_CLASS "Channel::ChannelNotification"
// #define MS_LOG_DEV_LEVEL 3

#include "Channel/ChannelNotification.hpp"
#include "Logger.hpp"
#include "MediaSoupErrors.hpp"
#include "Utils.hpp"

namespace Channel
{
	/* Class variables. */

	// clang-format off
	absl::flat_hash_map<FBS::Notification::Event, const char*> ChannelNotification::event2String =
	{
		{ FBS::Notification::Event::TRANSPORT_SEND_RTCP, "transport.sendRtcp" },
		{ FBS::Notification::Event::PRODUCER_SEND,       "producer.send" },
		{ FBS::Notification::Event::DATA_PRODUCER_SEND,  "dataProducer.send" },
	};
	// clang-format on

	flatbuffers::FlatBufferBuilder ChannelNotification::bufferBuilder;

	/* Instance methods. */

	ChannelNotification::ChannelNotification(const FBS::Notification::Notification* notification)
	{
		MS_TRACE();

		this->data      = notification;
		this->event     = notification->event();
		this->eventCStr = event2String[this->event];

		// Handler ID is optional.
		if (flatbuffers::IsFieldPresent(this->data, FBS::Notification::Notification::VT_HANDLERID))
			this->handlerId = this->data->handlerId()->str();
	}

	ChannelNotification::~ChannelNotification()
	{
		MS_TRACE();
	}
} // namespace Channel
