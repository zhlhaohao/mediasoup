"use strict";
// automatically generated by the FlatBuffers compiler, do not modify
Object.defineProperty(exports, "__esModule", { value: true });
exports.RtpCodecParametersT = exports.RtpCodecParameters = void 0;
const flatbuffers = require("flatbuffers");
const parameter_1 = require("../../fbs/rtp-parameters/parameter");
const rtcp_feedback_1 = require("../../fbs/rtp-parameters/rtcp-feedback");
class RtpCodecParameters {
    bb = null;
    bb_pos = 0;
    __init(i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    }
    static getRootAsRtpCodecParameters(bb, obj) {
        return (obj || new RtpCodecParameters()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    static getSizePrefixedRootAsRtpCodecParameters(bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new RtpCodecParameters()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    mimeType(optionalEncoding) {
        const offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? this.bb.__string(this.bb_pos + offset, optionalEncoding) : null;
    }
    payloadType() {
        const offset = this.bb.__offset(this.bb_pos, 6);
        return offset ? this.bb.readUint8(this.bb_pos + offset) : 0;
    }
    clockRate() {
        const offset = this.bb.__offset(this.bb_pos, 8);
        return offset ? this.bb.readUint32(this.bb_pos + offset) : 0;
    }
    channels() {
        const offset = this.bb.__offset(this.bb_pos, 10);
        return offset ? this.bb.readUint8(this.bb_pos + offset) : null;
    }
    parameters(index, obj) {
        const offset = this.bb.__offset(this.bb_pos, 12);
        return offset ? (obj || new parameter_1.Parameter()).__init(this.bb.__indirect(this.bb.__vector(this.bb_pos + offset) + index * 4), this.bb) : null;
    }
    parametersLength() {
        const offset = this.bb.__offset(this.bb_pos, 12);
        return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
    }
    rtcpFeedback(index, obj) {
        const offset = this.bb.__offset(this.bb_pos, 14);
        return offset ? (obj || new rtcp_feedback_1.RtcpFeedback()).__init(this.bb.__indirect(this.bb.__vector(this.bb_pos + offset) + index * 4), this.bb) : null;
    }
    rtcpFeedbackLength() {
        const offset = this.bb.__offset(this.bb_pos, 14);
        return offset ? this.bb.__vector_len(this.bb_pos + offset) : 0;
    }
    static startRtpCodecParameters(builder) {
        builder.startObject(6);
    }
    static addMimeType(builder, mimeTypeOffset) {
        builder.addFieldOffset(0, mimeTypeOffset, 0);
    }
    static addPayloadType(builder, payloadType) {
        builder.addFieldInt8(1, payloadType, 0);
    }
    static addClockRate(builder, clockRate) {
        builder.addFieldInt32(2, clockRate, 0);
    }
    static addChannels(builder, channels) {
        builder.addFieldInt8(3, channels, 0);
    }
    static addParameters(builder, parametersOffset) {
        builder.addFieldOffset(4, parametersOffset, 0);
    }
    static createParametersVector(builder, data) {
        builder.startVector(4, data.length, 4);
        for (let i = data.length - 1; i >= 0; i--) {
            builder.addOffset(data[i]);
        }
        return builder.endVector();
    }
    static startParametersVector(builder, numElems) {
        builder.startVector(4, numElems, 4);
    }
    static addRtcpFeedback(builder, rtcpFeedbackOffset) {
        builder.addFieldOffset(5, rtcpFeedbackOffset, 0);
    }
    static createRtcpFeedbackVector(builder, data) {
        builder.startVector(4, data.length, 4);
        for (let i = data.length - 1; i >= 0; i--) {
            builder.addOffset(data[i]);
        }
        return builder.endVector();
    }
    static startRtcpFeedbackVector(builder, numElems) {
        builder.startVector(4, numElems, 4);
    }
    static endRtpCodecParameters(builder) {
        const offset = builder.endObject();
        builder.requiredField(offset, 4); // mime_type
        return offset;
    }
    static createRtpCodecParameters(builder, mimeTypeOffset, payloadType, clockRate, channels, parametersOffset, rtcpFeedbackOffset) {
        RtpCodecParameters.startRtpCodecParameters(builder);
        RtpCodecParameters.addMimeType(builder, mimeTypeOffset);
        RtpCodecParameters.addPayloadType(builder, payloadType);
        RtpCodecParameters.addClockRate(builder, clockRate);
        if (channels !== null)
            RtpCodecParameters.addChannels(builder, channels);
        RtpCodecParameters.addParameters(builder, parametersOffset);
        RtpCodecParameters.addRtcpFeedback(builder, rtcpFeedbackOffset);
        return RtpCodecParameters.endRtpCodecParameters(builder);
    }
    unpack() {
        return new RtpCodecParametersT(this.mimeType(), this.payloadType(), this.clockRate(), this.channels(), this.bb.createObjList(this.parameters.bind(this), this.parametersLength()), this.bb.createObjList(this.rtcpFeedback.bind(this), this.rtcpFeedbackLength()));
    }
    unpackTo(_o) {
        _o.mimeType = this.mimeType();
        _o.payloadType = this.payloadType();
        _o.clockRate = this.clockRate();
        _o.channels = this.channels();
        _o.parameters = this.bb.createObjList(this.parameters.bind(this), this.parametersLength());
        _o.rtcpFeedback = this.bb.createObjList(this.rtcpFeedback.bind(this), this.rtcpFeedbackLength());
    }
}
exports.RtpCodecParameters = RtpCodecParameters;
class RtpCodecParametersT {
    mimeType;
    payloadType;
    clockRate;
    channels;
    parameters;
    rtcpFeedback;
    constructor(mimeType = null, payloadType = 0, clockRate = 0, channels = null, parameters = [], rtcpFeedback = []) {
        this.mimeType = mimeType;
        this.payloadType = payloadType;
        this.clockRate = clockRate;
        this.channels = channels;
        this.parameters = parameters;
        this.rtcpFeedback = rtcpFeedback;
    }
    pack(builder) {
        const mimeType = (this.mimeType !== null ? builder.createString(this.mimeType) : 0);
        const parameters = RtpCodecParameters.createParametersVector(builder, builder.createObjectOffsetList(this.parameters));
        const rtcpFeedback = RtpCodecParameters.createRtcpFeedbackVector(builder, builder.createObjectOffsetList(this.rtcpFeedback));
        return RtpCodecParameters.createRtpCodecParameters(builder, mimeType, this.payloadType, this.clockRate, this.channels, parameters, rtcpFeedback);
    }
}
exports.RtpCodecParametersT = RtpCodecParametersT;
