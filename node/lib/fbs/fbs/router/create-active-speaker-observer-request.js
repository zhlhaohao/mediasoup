"use strict";
// automatically generated by the FlatBuffers compiler, do not modify
Object.defineProperty(exports, "__esModule", { value: true });
exports.CreateActiveSpeakerObserverRequestT = exports.CreateActiveSpeakerObserverRequest = void 0;
const flatbuffers = require("flatbuffers");
const active_speaker_observer_options_1 = require("../../fbs/router/active-speaker-observer-options");
class CreateActiveSpeakerObserverRequest {
    bb = null;
    bb_pos = 0;
    __init(i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    }
    static getRootAsCreateActiveSpeakerObserverRequest(bb, obj) {
        return (obj || new CreateActiveSpeakerObserverRequest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    static getSizePrefixedRootAsCreateActiveSpeakerObserverRequest(bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new CreateActiveSpeakerObserverRequest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    activeSpeakerObserverId(optionalEncoding) {
        const offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
    }
    options(obj) {
        const offset = this.bb.__offset(this.bb_pos, 6);
        return offset ? (obj || new active_speaker_observer_options_1.ActiveSpeakerObserverOptions()).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
    }
    static startCreateActiveSpeakerObserverRequest(builder) {
        builder.startObject(2);
    }
    static addActiveSpeakerObserverId(builder, activeSpeakerObserverIdOffset) {
        builder.addFieldOffset(0, activeSpeakerObserverIdOffset, 0);
    }
    static addOptions(builder, optionsOffset) {
        builder.addFieldOffset(1, optionsOffset, 0);
    }
    static endCreateActiveSpeakerObserverRequest(builder) {
        const offset = builder.endObject();
        builder.requiredField(offset, 4); // active_speaker_observer_id
        builder.requiredField(offset, 6); // options
        return offset;
    }
    unpack() {
        return new CreateActiveSpeakerObserverRequestT(this.activeSpeakerObserverId(), (this.options() !== null ? this.options().unpack() : null));
    }
    unpackTo(_o) {
        _o.activeSpeakerObserverId = this.activeSpeakerObserverId();
        _o.options = (this.options() !== null ? this.options().unpack() : null);
    }
}
exports.CreateActiveSpeakerObserverRequest = CreateActiveSpeakerObserverRequest;
class CreateActiveSpeakerObserverRequestT {
    activeSpeakerObserverId;
    options;
    constructor(activeSpeakerObserverId = null, options = null) {
        this.activeSpeakerObserverId = activeSpeakerObserverId;
        this.options = options;
    }
    pack(builder) {
        const activeSpeakerObserverId = (this.activeSpeakerObserverId !== null ? builder.createString(this.activeSpeakerObserverId) : 0);
        const options = (this.options !== null ? this.options.pack(builder) : 0);
        CreateActiveSpeakerObserverRequest.startCreateActiveSpeakerObserverRequest(builder);
        CreateActiveSpeakerObserverRequest.addActiveSpeakerObserverId(builder, activeSpeakerObserverId);
        CreateActiveSpeakerObserverRequest.addOptions(builder, options);
        return CreateActiveSpeakerObserverRequest.endCreateActiveSpeakerObserverRequest(builder);
    }
}
exports.CreateActiveSpeakerObserverRequestT = CreateActiveSpeakerObserverRequestT;