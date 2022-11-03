// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ROUTER_FBS_ROUTER_H_
#define FLATBUFFERS_GENERATED_ROUTER_FBS_ROUTER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 2 &&
              FLATBUFFERS_VERSION_MINOR == 0 &&
              FLATBUFFERS_VERSION_REVISION == 8,
             "Non-compatible flatbuffers version included");

#include "common_generated.h"
#include "pipeTransport_generated.h"
#include "plainTransport_generated.h"
#include "transport_generated.h"
#include "webRtcTransport_generated.h"

namespace FBS {
namespace Router {

struct DumpResponse;
struct DumpResponseBuilder;

struct CreatePipeTransportRequest;
struct CreatePipeTransportRequestBuilder;

struct CreatePlainTransportRequest;
struct CreatePlainTransportRequestBuilder;

struct CreateWebRtcTransportRequest;
struct CreateWebRtcTransportRequestBuilder;

inline const flatbuffers::TypeTable *DumpResponseTypeTable();

inline const flatbuffers::TypeTable *CreatePipeTransportRequestTypeTable();

inline const flatbuffers::TypeTable *CreatePlainTransportRequestTypeTable();

inline const flatbuffers::TypeTable *CreateWebRtcTransportRequestTypeTable();

struct DumpResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef DumpResponseBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return DumpResponseTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_TRANSPORTIDS = 6,
    VT_RTPOBSERVERIDS = 8,
    VT_MAPPRODUCERIDCONSUMERIDS = 10,
    VT_MAPCONSUMERIDPRODUCERID = 12,
    VT_MAPPRODUCERIDOBSERVERIDS = 14,
    VT_MAPDATAPRODUCERIDDATACONSUMERIDS = 16,
    VT_MAPDATACONSUMERIDDATAPRODUCERID = 18
  };
  const flatbuffers::String *id() const {
    return GetPointer<const flatbuffers::String *>(VT_ID);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *transportIds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_TRANSPORTIDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *rtpObserverIds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_RTPOBSERVERIDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapProducerIdConsumerIds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *>(VT_MAPPRODUCERIDCONSUMERIDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>> *mapConsumerIdProducerId() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>> *>(VT_MAPCONSUMERIDPRODUCERID);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapProducerIdObserverIds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *>(VT_MAPPRODUCERIDOBSERVERIDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapDataProducerIdDataConsumerIds() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *>(VT_MAPDATAPRODUCERIDDATACONSUMERIDS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>> *mapDataConsumerIdDataProducerId() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>> *>(VT_MAPDATACONSUMERIDDATAPRODUCERID);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_ID) &&
           verifier.VerifyString(id()) &&
           VerifyOffset(verifier, VT_TRANSPORTIDS) &&
           verifier.VerifyVector(transportIds()) &&
           verifier.VerifyVectorOfStrings(transportIds()) &&
           VerifyOffset(verifier, VT_RTPOBSERVERIDS) &&
           verifier.VerifyVector(rtpObserverIds()) &&
           verifier.VerifyVectorOfStrings(rtpObserverIds()) &&
           VerifyOffset(verifier, VT_MAPPRODUCERIDCONSUMERIDS) &&
           verifier.VerifyVector(mapProducerIdConsumerIds()) &&
           verifier.VerifyVectorOfTables(mapProducerIdConsumerIds()) &&
           VerifyOffset(verifier, VT_MAPCONSUMERIDPRODUCERID) &&
           verifier.VerifyVector(mapConsumerIdProducerId()) &&
           verifier.VerifyVectorOfTables(mapConsumerIdProducerId()) &&
           VerifyOffset(verifier, VT_MAPPRODUCERIDOBSERVERIDS) &&
           verifier.VerifyVector(mapProducerIdObserverIds()) &&
           verifier.VerifyVectorOfTables(mapProducerIdObserverIds()) &&
           VerifyOffset(verifier, VT_MAPDATAPRODUCERIDDATACONSUMERIDS) &&
           verifier.VerifyVector(mapDataProducerIdDataConsumerIds()) &&
           verifier.VerifyVectorOfTables(mapDataProducerIdDataConsumerIds()) &&
           VerifyOffset(verifier, VT_MAPDATACONSUMERIDDATAPRODUCERID) &&
           verifier.VerifyVector(mapDataConsumerIdDataProducerId()) &&
           verifier.VerifyVectorOfTables(mapDataConsumerIdDataProducerId()) &&
           verifier.EndTable();
  }
};

struct DumpResponseBuilder {
  typedef DumpResponse Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(flatbuffers::Offset<flatbuffers::String> id) {
    fbb_.AddOffset(DumpResponse::VT_ID, id);
  }
  void add_transportIds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> transportIds) {
    fbb_.AddOffset(DumpResponse::VT_TRANSPORTIDS, transportIds);
  }
  void add_rtpObserverIds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> rtpObserverIds) {
    fbb_.AddOffset(DumpResponse::VT_RTPOBSERVERIDS, rtpObserverIds);
  }
  void add_mapProducerIdConsumerIds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapProducerIdConsumerIds) {
    fbb_.AddOffset(DumpResponse::VT_MAPPRODUCERIDCONSUMERIDS, mapProducerIdConsumerIds);
  }
  void add_mapConsumerIdProducerId(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>>> mapConsumerIdProducerId) {
    fbb_.AddOffset(DumpResponse::VT_MAPCONSUMERIDPRODUCERID, mapConsumerIdProducerId);
  }
  void add_mapProducerIdObserverIds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapProducerIdObserverIds) {
    fbb_.AddOffset(DumpResponse::VT_MAPPRODUCERIDOBSERVERIDS, mapProducerIdObserverIds);
  }
  void add_mapDataProducerIdDataConsumerIds(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapDataProducerIdDataConsumerIds) {
    fbb_.AddOffset(DumpResponse::VT_MAPDATAPRODUCERIDDATACONSUMERIDS, mapDataProducerIdDataConsumerIds);
  }
  void add_mapDataConsumerIdDataProducerId(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>>> mapDataConsumerIdDataProducerId) {
    fbb_.AddOffset(DumpResponse::VT_MAPDATACONSUMERIDDATAPRODUCERID, mapDataConsumerIdDataProducerId);
  }
  explicit DumpResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<DumpResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<DumpResponse>(end);
    fbb_.Required(o, DumpResponse::VT_ID);
    return o;
  }
};

inline flatbuffers::Offset<DumpResponse> CreateDumpResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> id = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> transportIds = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> rtpObserverIds = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapProducerIdConsumerIds = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>>> mapConsumerIdProducerId = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapProducerIdObserverIds = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringStringArray>>> mapDataProducerIdDataConsumerIds = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FBS::Common::StringString>>> mapDataConsumerIdDataProducerId = 0) {
  DumpResponseBuilder builder_(_fbb);
  builder_.add_mapDataConsumerIdDataProducerId(mapDataConsumerIdDataProducerId);
  builder_.add_mapDataProducerIdDataConsumerIds(mapDataProducerIdDataConsumerIds);
  builder_.add_mapProducerIdObserverIds(mapProducerIdObserverIds);
  builder_.add_mapConsumerIdProducerId(mapConsumerIdProducerId);
  builder_.add_mapProducerIdConsumerIds(mapProducerIdConsumerIds);
  builder_.add_rtpObserverIds(rtpObserverIds);
  builder_.add_transportIds(transportIds);
  builder_.add_id(id);
  return builder_.Finish();
}

inline flatbuffers::Offset<DumpResponse> CreateDumpResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *id = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *transportIds = nullptr,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *rtpObserverIds = nullptr,
    const std::vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapProducerIdConsumerIds = nullptr,
    const std::vector<flatbuffers::Offset<FBS::Common::StringString>> *mapConsumerIdProducerId = nullptr,
    const std::vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapProducerIdObserverIds = nullptr,
    const std::vector<flatbuffers::Offset<FBS::Common::StringStringArray>> *mapDataProducerIdDataConsumerIds = nullptr,
    const std::vector<flatbuffers::Offset<FBS::Common::StringString>> *mapDataConsumerIdDataProducerId = nullptr) {
  auto id__ = id ? _fbb.CreateString(id) : 0;
  auto transportIds__ = transportIds ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*transportIds) : 0;
  auto rtpObserverIds__ = rtpObserverIds ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*rtpObserverIds) : 0;
  auto mapProducerIdConsumerIds__ = mapProducerIdConsumerIds ? _fbb.CreateVector<flatbuffers::Offset<FBS::Common::StringStringArray>>(*mapProducerIdConsumerIds) : 0;
  auto mapConsumerIdProducerId__ = mapConsumerIdProducerId ? _fbb.CreateVector<flatbuffers::Offset<FBS::Common::StringString>>(*mapConsumerIdProducerId) : 0;
  auto mapProducerIdObserverIds__ = mapProducerIdObserverIds ? _fbb.CreateVector<flatbuffers::Offset<FBS::Common::StringStringArray>>(*mapProducerIdObserverIds) : 0;
  auto mapDataProducerIdDataConsumerIds__ = mapDataProducerIdDataConsumerIds ? _fbb.CreateVector<flatbuffers::Offset<FBS::Common::StringStringArray>>(*mapDataProducerIdDataConsumerIds) : 0;
  auto mapDataConsumerIdDataProducerId__ = mapDataConsumerIdDataProducerId ? _fbb.CreateVector<flatbuffers::Offset<FBS::Common::StringString>>(*mapDataConsumerIdDataProducerId) : 0;
  return FBS::Router::CreateDumpResponse(
      _fbb,
      id__,
      transportIds__,
      rtpObserverIds__,
      mapProducerIdConsumerIds__,
      mapConsumerIdProducerId__,
      mapProducerIdObserverIds__,
      mapDataProducerIdDataConsumerIds__,
      mapDataConsumerIdDataProducerId__);
}

struct CreatePipeTransportRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CreatePipeTransportRequestBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return CreatePipeTransportRequestTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TRANSPORTID = 4,
    VT_OPTIONS = 6
  };
  const flatbuffers::String *transportId() const {
    return GetPointer<const flatbuffers::String *>(VT_TRANSPORTID);
  }
  const FBS::PipeTransport::PipeTransportOptions *options() const {
    return GetPointer<const FBS::PipeTransport::PipeTransportOptions *>(VT_OPTIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TRANSPORTID) &&
           verifier.VerifyString(transportId()) &&
           VerifyOffset(verifier, VT_OPTIONS) &&
           verifier.VerifyTable(options()) &&
           verifier.EndTable();
  }
};

struct CreatePipeTransportRequestBuilder {
  typedef CreatePipeTransportRequest Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_transportId(flatbuffers::Offset<flatbuffers::String> transportId) {
    fbb_.AddOffset(CreatePipeTransportRequest::VT_TRANSPORTID, transportId);
  }
  void add_options(flatbuffers::Offset<FBS::PipeTransport::PipeTransportOptions> options) {
    fbb_.AddOffset(CreatePipeTransportRequest::VT_OPTIONS, options);
  }
  explicit CreatePipeTransportRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<CreatePipeTransportRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CreatePipeTransportRequest>(end);
    fbb_.Required(o, CreatePipeTransportRequest::VT_TRANSPORTID);
    return o;
  }
};

inline flatbuffers::Offset<CreatePipeTransportRequest> CreateCreatePipeTransportRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> transportId = 0,
    flatbuffers::Offset<FBS::PipeTransport::PipeTransportOptions> options = 0) {
  CreatePipeTransportRequestBuilder builder_(_fbb);
  builder_.add_options(options);
  builder_.add_transportId(transportId);
  return builder_.Finish();
}

inline flatbuffers::Offset<CreatePipeTransportRequest> CreateCreatePipeTransportRequestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *transportId = nullptr,
    flatbuffers::Offset<FBS::PipeTransport::PipeTransportOptions> options = 0) {
  auto transportId__ = transportId ? _fbb.CreateString(transportId) : 0;
  return FBS::Router::CreateCreatePipeTransportRequest(
      _fbb,
      transportId__,
      options);
}

struct CreatePlainTransportRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CreatePlainTransportRequestBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return CreatePlainTransportRequestTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TRANSPORTID = 4,
    VT_OPTIONS = 6
  };
  const flatbuffers::String *transportId() const {
    return GetPointer<const flatbuffers::String *>(VT_TRANSPORTID);
  }
  const FBS::PlainTransport::PlainTransportOptions *options() const {
    return GetPointer<const FBS::PlainTransport::PlainTransportOptions *>(VT_OPTIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TRANSPORTID) &&
           verifier.VerifyString(transportId()) &&
           VerifyOffset(verifier, VT_OPTIONS) &&
           verifier.VerifyTable(options()) &&
           verifier.EndTable();
  }
};

struct CreatePlainTransportRequestBuilder {
  typedef CreatePlainTransportRequest Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_transportId(flatbuffers::Offset<flatbuffers::String> transportId) {
    fbb_.AddOffset(CreatePlainTransportRequest::VT_TRANSPORTID, transportId);
  }
  void add_options(flatbuffers::Offset<FBS::PlainTransport::PlainTransportOptions> options) {
    fbb_.AddOffset(CreatePlainTransportRequest::VT_OPTIONS, options);
  }
  explicit CreatePlainTransportRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<CreatePlainTransportRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CreatePlainTransportRequest>(end);
    fbb_.Required(o, CreatePlainTransportRequest::VT_TRANSPORTID);
    return o;
  }
};

inline flatbuffers::Offset<CreatePlainTransportRequest> CreateCreatePlainTransportRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> transportId = 0,
    flatbuffers::Offset<FBS::PlainTransport::PlainTransportOptions> options = 0) {
  CreatePlainTransportRequestBuilder builder_(_fbb);
  builder_.add_options(options);
  builder_.add_transportId(transportId);
  return builder_.Finish();
}

inline flatbuffers::Offset<CreatePlainTransportRequest> CreateCreatePlainTransportRequestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *transportId = nullptr,
    flatbuffers::Offset<FBS::PlainTransport::PlainTransportOptions> options = 0) {
  auto transportId__ = transportId ? _fbb.CreateString(transportId) : 0;
  return FBS::Router::CreateCreatePlainTransportRequest(
      _fbb,
      transportId__,
      options);
}

struct CreateWebRtcTransportRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef CreateWebRtcTransportRequestBuilder Builder;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return CreateWebRtcTransportRequestTypeTable();
  }
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_TRANSPORTID = 4,
    VT_OPTIONS = 6
  };
  const flatbuffers::String *transportId() const {
    return GetPointer<const flatbuffers::String *>(VT_TRANSPORTID);
  }
  const FBS::WebRtcTransport::WebRtcTransportOptions *options() const {
    return GetPointer<const FBS::WebRtcTransport::WebRtcTransportOptions *>(VT_OPTIONS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_TRANSPORTID) &&
           verifier.VerifyString(transportId()) &&
           VerifyOffset(verifier, VT_OPTIONS) &&
           verifier.VerifyTable(options()) &&
           verifier.EndTable();
  }
};

struct CreateWebRtcTransportRequestBuilder {
  typedef CreateWebRtcTransportRequest Table;
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_transportId(flatbuffers::Offset<flatbuffers::String> transportId) {
    fbb_.AddOffset(CreateWebRtcTransportRequest::VT_TRANSPORTID, transportId);
  }
  void add_options(flatbuffers::Offset<FBS::WebRtcTransport::WebRtcTransportOptions> options) {
    fbb_.AddOffset(CreateWebRtcTransportRequest::VT_OPTIONS, options);
  }
  explicit CreateWebRtcTransportRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  flatbuffers::Offset<CreateWebRtcTransportRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CreateWebRtcTransportRequest>(end);
    fbb_.Required(o, CreateWebRtcTransportRequest::VT_TRANSPORTID);
    return o;
  }
};

inline flatbuffers::Offset<CreateWebRtcTransportRequest> CreateCreateWebRtcTransportRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> transportId = 0,
    flatbuffers::Offset<FBS::WebRtcTransport::WebRtcTransportOptions> options = 0) {
  CreateWebRtcTransportRequestBuilder builder_(_fbb);
  builder_.add_options(options);
  builder_.add_transportId(transportId);
  return builder_.Finish();
}

inline flatbuffers::Offset<CreateWebRtcTransportRequest> CreateCreateWebRtcTransportRequestDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *transportId = nullptr,
    flatbuffers::Offset<FBS::WebRtcTransport::WebRtcTransportOptions> options = 0) {
  auto transportId__ = transportId ? _fbb.CreateString(transportId) : 0;
  return FBS::Router::CreateCreateWebRtcTransportRequest(
      _fbb,
      transportId__,
      options);
}

inline const flatbuffers::TypeTable *DumpResponseTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_STRING, 1, -1 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 1 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 0 },
    { flatbuffers::ET_SEQUENCE, 1, 1 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    FBS::Common::StringStringArrayTypeTable,
    FBS::Common::StringStringTypeTable
  };
  static const char * const names[] = {
    "id",
    "transportIds",
    "rtpObserverIds",
    "mapProducerIdConsumerIds",
    "mapConsumerIdProducerId",
    "mapProducerIdObserverIds",
    "mapDataProducerIdDataConsumerIds",
    "mapDataConsumerIdDataProducerId"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 8, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *CreatePipeTransportRequestTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    FBS::PipeTransport::PipeTransportOptionsTypeTable
  };
  static const char * const names[] = {
    "transportId",
    "options"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *CreatePlainTransportRequestTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    FBS::PlainTransport::PlainTransportOptionsTypeTable
  };
  static const char * const names[] = {
    "transportId",
    "options"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

inline const flatbuffers::TypeTable *CreateWebRtcTransportRequestTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 },
    { flatbuffers::ET_SEQUENCE, 0, 0 }
  };
  static const flatbuffers::TypeFunction type_refs[] = {
    FBS::WebRtcTransport::WebRtcTransportOptionsTypeTable
  };
  static const char * const names[] = {
    "transportId",
    "options"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 2, type_codes, type_refs, nullptr, nullptr, names
  };
  return &tt;
}

}  // namespace Router
}  // namespace FBS

#endif  // FLATBUFFERS_GENERATED_ROUTER_FBS_ROUTER_H_
