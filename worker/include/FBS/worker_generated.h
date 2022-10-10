// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_WORKER_FBS_WORKER_H_
#define FLATBUFFERS_GENERATED_WORKER_FBS_WORKER_H_

#include "flatbuffers/flatbuffers.h"

namespace FBS {
namespace Worker {

struct ChannelMessageHandlers;
struct ChannelMessageHandlersBuilder;

struct Dump;
struct DumpBuilder;

inline const flatbuffers::TypeTable *ChannelMessageHandlersTypeTable();

inline const flatbuffers::TypeTable *DumpTypeTable();

struct ChannelMessageHandlers FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ChannelMessageHandlersBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ChannelMessageHandlersTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CHANNEL_REQUEST_HANDLERS = 4,
    VT_PAYLOADCHANNEL_REQUEST_HANDLERS = 6,
    VT_PAYLOADCHANNEL_NOTIFICATION_HANDLERS = 8
  };
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *channel_request_handlers() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_CHANNEL_REQUEST_HANDLERS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *payloadchannel_request_handlers() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_PAYLOADCHANNEL_REQUEST_HANDLERS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *payloadchannel_notification_handlers() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_PAYLOADCHANNEL_NOTIFICATION_HANDLERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CHANNEL_REQUEST_HANDLERS) &&
           verifier.VerifyVector(channel_request_handlers()) &&
           verifier.VerifyVectorOfStrings(channel_request_handlers()) &&
           VerifyOffset(verifier, VT_PAYLOADCHANNEL_REQUEST_HANDLERS) &&
           verifier.VerifyVector(payloadchannel_request_handlers()) &&
           verifier.VerifyVectorOfStrings(payloadchannel_request_handlers()) &&
           VerifyOffset(verifier, VT_PAYLOADCHANNEL_NOTIFICATION_HANDLERS) &&
           verifier.VerifyVector(payloadchannel_notification_handlers()) &&
           verifier.VerifyVectorOfStrings(payloadchannel_notification_handlers()) &&
           verifier.EndTable();
  }
};

struct ChannelMessageHandlersBuilder {
  typedef ChannelMessageHandlers Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_channel_request_handlers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> channel_request_handlers) {
    fbb_.AddOffset(ChannelMessageHandlers::VT_CHANNEL_REQUEST_HANDLERS, channel_request_handlers);
  }
  void add_payloadchannel_request_handlers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> payloadchannel_request_handlers) {
    fbb_.AddOffset(ChannelMessageHandlers::VT_PAYLOADCHANNEL_REQUEST_HANDLERS, payloadchannel_request_handlers);
  }
  void add_payloadchannel_notification_handlers(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> payloadchannel_notification_handlers) {
    fbb_.AddOffset(ChannelMessageHandlers::VT_PAYLOADCHANNEL_NOTIFICATION_HANDLERS, payloadchannel_notification_handlers);
  }
  explicit ChannelMessageHandlersBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<ChannelMessageHandlers> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ChannelMessageHandlers>(end);
    return o;
  }
};

inline flatbuffers::Offset<ChannelMessageHandlers> CreateChannelMessageHandlers(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> channel_request_handlers = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> payloadchannel_request_handlers = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> payloadchannel_notification_handlers = 0) {
  ChannelMessageHandlersBuilder builder_(_fbb);
  builder_.add_payloadchannel_notification_handlers(payloadchannel_notification_handlers);
  builder_.add_payloadchannel_request_handlers(payloadchannel_request_handlers);
  builder_.add_channel_request_handlers(channel_request_handlers);
  return builder_.Finish();
}

inline flatbuffers::Offset<ChannelMessageHandlers> CreateChannelMessageHandlersDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *channel_request_handlers = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *payloadchannel_request_handlers = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *payloadchannel_notification_handlers = nullptr) {
  auto channel_request_handlers__ = channel_request_handlers ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*channel_request_handlers) : 0;
  auto payloadchannel_request_handlers__ = payloadchannel_request_handlers ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*payloadchannel_request_handlers) : 0;
  auto payloadchannel_notification_handlers__ = payloadchannel_notification_handlers ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*payloadchannel_notification_handlers) : 0;
  return FBS::Worker::CreateChannelMessageHandlers(
      _fbb,
      channel_request_handlers__,
      payloadchannel_request_handlers__,
      payloadchannel_notification_handlers__);
}

struct Dump FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef DumpBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DumpTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_PID = 4,
    VT_WEBRTC_SERVER_IDS = 6,
    VT_ROUTER_IDS = 8,
    VT_CHANNEL_MESSAGE_HANDLERS = 10
  };
  uint64_t pid() const {
    return GetField<uint64_t>(VT_PID, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *webrtc_server_ids() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_WEBRTC_SERVER_IDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *router_ids() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_ROUTER_IDS);
  }
  const FBS::Worker::ChannelMessageHandlers *channel_message_handlers() const {
    return GetPointer<const FBS::Worker::ChannelMessageHandlers *>(VT_CHANNEL_MESSAGE_HANDLERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_PID, 8) &&
           VerifyOffset(verifier, VT_WEBRTC_SERVER_IDS) &&
           verifier.VerifyVector(webrtc_server_ids()) &&
           verifier.VerifyVectorOfStrings(webrtc_server_ids()) &&
           VerifyOffset(verifier, VT_ROUTER_IDS) &&
           verifier.VerifyVector(router_ids()) &&
           verifier.VerifyVectorOfStrings(router_ids()) &&
           VerifyOffset(verifier, VT_CHANNEL_MESSAGE_HANDLERS) &&
           verifier.VerifyTable(channel_message_handlers()) &&
           verifier.EndTable();
  }
};

struct DumpBuilder {
  typedef Dump Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_pid(uint64_t pid) {
    fbb_.AddElement<uint64_t>(Dump::VT_PID, pid, 0);
  }
  void add_webrtc_server_ids(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> webrtc_server_ids) {
    fbb_.AddOffset(Dump::VT_WEBRTC_SERVER_IDS, webrtc_server_ids);
  }
  void add_router_ids(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> router_ids) {
    fbb_.AddOffset(Dump::VT_ROUTER_IDS, router_ids);
  }
  void add_channel_message_handlers(flatbuffers::Offset<FBS::Worker::ChannelMessageHandlers> channel_message_handlers) {
    fbb_.AddOffset(Dump::VT_CHANNEL_MESSAGE_HANDLERS, channel_message_handlers);
  }
  explicit DumpBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<Dump> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Dump>(end);
    return o;
  }
};

inline flatbuffers::Offset<Dump> CreateDump(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t pid = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> webrtc_server_ids = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> router_ids = 0,
    flatbuffers::Offset<FBS::Worker::ChannelMessageHandlers> channel_message_handlers = 0) {
  DumpBuilder builder_(_fbb);
  builder_.add_pid(pid);
  builder_.add_channel_message_handlers(channel_message_handlers);
  builder_.add_router_ids(router_ids);
  builder_.add_webrtc_server_ids(webrtc_server_ids);
  return builder_.Finish();
}

inline flatbuffers::Offset<Dump> CreateDumpDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t pid = 0,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *webrtc_server_ids = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *router_ids = nullptr,
    flatbuffers::Offset<FBS::Worker::ChannelMessageHandlers> channel_message_handlers = 0) {
  auto webrtc_server_ids__ = webrtc_server_ids ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*webrtc_server_ids) : 0;
  auto router_ids__ = router_ids ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*router_ids) : 0;
  return FBS::Worker::CreateDump(
      _fbb,
      pid,
      webrtc_server_ids__,
      router_ids__,
      channel_message_handlers);
}

inline const flatbuffers::TypeTable *ChannelMessageHandlersTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_STRING, 1, -1 }
  };
  static const char * const names[] = {
    "channel_request_handlers",
    "payloadchannel_request_handlers",
    "payloadchannel_notification_handlers"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 3, type_codes, nullptr, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *DumpTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_ULONG, 0, -1 },
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    FBS::Worker::ChannelMessageHandlersTypeTable
  };
  static const char * const names[] = {
    "pid",
    "webrtc_server_ids",
    "router_ids",
    "channel_message_handlers"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 4, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const FBS::Worker::Dump *GetDump(const void *buf) {
  return flatbuffers::GetRoot<FBS::Worker::Dump>(buf);
}

inline const FBS::Worker::Dump *GetSizePrefixedDump(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<FBS::Worker::Dump>(buf);
}

inline bool VerifyDumpBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<FBS::Worker::Dump>(nullptr);
}

inline bool VerifySizePrefixedDumpBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<FBS::Worker::Dump>(nullptr);
}

inline void FinishDumpBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<FBS::Worker::Dump> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedDumpBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<FBS::Worker::Dump> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace Worker
}  // namespace FBS

#endif  // FLATBUFFERS_GENERATED_WORKER_FBS_WORKER_H_