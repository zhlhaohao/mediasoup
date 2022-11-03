"use strict";
// automatically generated by the FlatBuffers compiler, do not modify
Object.defineProperty(exports, "__esModule", { value: true });
exports.DirectTransportDumpT = exports.DirectTransportDump = void 0;
const flatbuffers = require("flatbuffers");
const dump_response_1 = require("../../fbs/transport/dump-response");
class DirectTransportDump {
    bb = null;
    bb_pos = 0;
    __init(i, bb) {
        this.bb_pos = i;
        this.bb = bb;
        return this;
    }
    static getRootAsDirectTransportDump(bb, obj) {
        return (obj || new DirectTransportDump()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    static getSizePrefixedRootAsDirectTransportDump(bb, obj) {
        bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
        return (obj || new DirectTransportDump()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
    }
    base(obj) {
        const offset = this.bb.__offset(this.bb_pos, 4);
        return offset ? (obj || new dump_response_1.DumpResponse()).__init(this.bb.__indirect(this.bb_pos + offset), this.bb) : null;
    }
    static startDirectTransportDump(builder) {
        builder.startObject(1);
    }
    static addBase(builder, baseOffset) {
        builder.addFieldOffset(0, baseOffset, 0);
    }
    static endDirectTransportDump(builder) {
        const offset = builder.endObject();
        builder.requiredField(offset, 4); // base
        return offset;
    }
    static createDirectTransportDump(builder, baseOffset) {
        DirectTransportDump.startDirectTransportDump(builder);
        DirectTransportDump.addBase(builder, baseOffset);
        return DirectTransportDump.endDirectTransportDump(builder);
    }
    unpack() {
        return new DirectTransportDumpT((this.base() !== null ? this.base().unpack() : null));
    }
    unpackTo(_o) {
        _o.base = (this.base() !== null ? this.base().unpack() : null);
    }
}
exports.DirectTransportDump = DirectTransportDump;
class DirectTransportDumpT {
    base;
    constructor(base = null) {
        this.base = base;
    }
    pack(builder) {
        const base = (this.base !== null ? this.base.pack(builder) : 0);
        return DirectTransportDump.createDirectTransportDump(builder, base);
    }
}
exports.DirectTransportDumpT = DirectTransportDumpT;
