// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';



export class EncodingMapping {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):EncodingMapping {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsEncodingMapping(bb:flatbuffers.ByteBuffer, obj?:EncodingMapping):EncodingMapping {
  return (obj || new EncodingMapping()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsEncodingMapping(bb:flatbuffers.ByteBuffer, obj?:EncodingMapping):EncodingMapping {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new EncodingMapping()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

rid():string|null
rid(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
rid(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

ssrc():number|null {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.readUint32(this.bb_pos + offset) : null;
}

scalabilityMode():string|null
scalabilityMode(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
scalabilityMode(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 8);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

mappedSsrc():number {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? this.bb!.readUint32(this.bb_pos + offset) : 0;
}

static startEncodingMapping(builder:flatbuffers.Builder) {
  builder.startObject(4);
}

static addRid(builder:flatbuffers.Builder, ridOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, ridOffset, 0);
}

static addSsrc(builder:flatbuffers.Builder, ssrc:number) {
  builder.addFieldInt32(1, ssrc, 0);
}

static addScalabilityMode(builder:flatbuffers.Builder, scalabilityModeOffset:flatbuffers.Offset) {
  builder.addFieldOffset(2, scalabilityModeOffset, 0);
}

static addMappedSsrc(builder:flatbuffers.Builder, mappedSsrc:number) {
  builder.addFieldInt32(3, mappedSsrc, 0);
}

static endEncodingMapping(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  return offset;
}

static createEncodingMapping(builder:flatbuffers.Builder, ridOffset:flatbuffers.Offset, ssrc:number|null, scalabilityModeOffset:flatbuffers.Offset, mappedSsrc:number):flatbuffers.Offset {
  EncodingMapping.startEncodingMapping(builder);
  EncodingMapping.addRid(builder, ridOffset);
  if (ssrc !== null)
    EncodingMapping.addSsrc(builder, ssrc);
  EncodingMapping.addScalabilityMode(builder, scalabilityModeOffset);
  EncodingMapping.addMappedSsrc(builder, mappedSsrc);
  return EncodingMapping.endEncodingMapping(builder);
}

unpack(): EncodingMappingT {
  return new EncodingMappingT(
    this.rid(),
    this.ssrc(),
    this.scalabilityMode(),
    this.mappedSsrc()
  );
}


unpackTo(_o: EncodingMappingT): void {
  _o.rid = this.rid();
  _o.ssrc = this.ssrc();
  _o.scalabilityMode = this.scalabilityMode();
  _o.mappedSsrc = this.mappedSsrc();
}
}

export class EncodingMappingT {
constructor(
  public rid: string|Uint8Array|null = null,
  public ssrc: number|null = null,
  public scalabilityMode: string|Uint8Array|null = null,
  public mappedSsrc: number = 0
){}


pack(builder:flatbuffers.Builder): flatbuffers.Offset {
  const rid = (this.rid !== null ? builder.createString(this.rid!) : 0);
  const scalabilityMode = (this.scalabilityMode !== null ? builder.createString(this.scalabilityMode!) : 0);

  return EncodingMapping.createEncodingMapping(builder,
    rid,
    this.ssrc,
    scalabilityMode,
    this.mappedSsrc
  );
}
}
