import * as flatbuffers from 'flatbuffers';
export declare class Rtx {
    bb: flatbuffers.ByteBuffer | null;
    bb_pos: number;
    __init(i: number, bb: flatbuffers.ByteBuffer): Rtx;
    static getRootAsRtx(bb: flatbuffers.ByteBuffer, obj?: Rtx): Rtx;
    static getSizePrefixedRootAsRtx(bb: flatbuffers.ByteBuffer, obj?: Rtx): Rtx;
    ssrc(): number | null;
    static startRtx(builder: flatbuffers.Builder): void;
    static addSsrc(builder: flatbuffers.Builder, ssrc: number): void;
    static endRtx(builder: flatbuffers.Builder): flatbuffers.Offset;
    static createRtx(builder: flatbuffers.Builder, ssrc: number | null): flatbuffers.Offset;
    unpack(): RtxT;
    unpackTo(_o: RtxT): void;
}
export declare class RtxT {
    ssrc: number | null;
    constructor(ssrc?: number | null);
    pack(builder: flatbuffers.Builder): flatbuffers.Offset;
}
//# sourceMappingURL=rtx.d.ts.map