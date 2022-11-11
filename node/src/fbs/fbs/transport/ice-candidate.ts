// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';



export class IceCandidate {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):IceCandidate {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsIceCandidate(bb:flatbuffers.ByteBuffer, obj?:IceCandidate):IceCandidate {
  return (obj || new IceCandidate()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsIceCandidate(bb:flatbuffers.ByteBuffer, obj?:IceCandidate):IceCandidate {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new IceCandidate()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

foundation():string|null
foundation(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
foundation(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

priority():number {
  const offset = this.bb!.__offset(this.bb_pos, 6);
  return offset ? this.bb!.readUint32(this.bb_pos + offset) : 0;
}

ip():string|null
ip(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
ip(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 8);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

protocol():string|null
protocol(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
protocol(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 10);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

port():number {
  const offset = this.bb!.__offset(this.bb_pos, 12);
  return offset ? this.bb!.readUint16(this.bb_pos + offset) : 0;
}

type():string|null
type(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
type(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 14);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

tcpType():string|null
tcpType(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
tcpType(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 16);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

static startIceCandidate(builder:flatbuffers.Builder) {
  builder.startObject(7);
}

static addFoundation(builder:flatbuffers.Builder, foundationOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, foundationOffset, 0);
}

static addPriority(builder:flatbuffers.Builder, priority:number) {
  builder.addFieldInt32(1, priority, 0);
}

static addIp(builder:flatbuffers.Builder, ipOffset:flatbuffers.Offset) {
  builder.addFieldOffset(2, ipOffset, 0);
}

static addProtocol(builder:flatbuffers.Builder, protocolOffset:flatbuffers.Offset) {
  builder.addFieldOffset(3, protocolOffset, 0);
}

static addPort(builder:flatbuffers.Builder, port:number) {
  builder.addFieldInt16(4, port, 0);
}

static addType(builder:flatbuffers.Builder, typeOffset:flatbuffers.Offset) {
  builder.addFieldOffset(5, typeOffset, 0);
}

static addTcpType(builder:flatbuffers.Builder, tcpTypeOffset:flatbuffers.Offset) {
  builder.addFieldOffset(6, tcpTypeOffset, 0);
}

static endIceCandidate(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  builder.requiredField(offset, 4) // foundation
  builder.requiredField(offset, 8) // ip
  builder.requiredField(offset, 10) // protocol
  return offset;
}

static createIceCandidate(builder:flatbuffers.Builder, foundationOffset:flatbuffers.Offset, priority:number, ipOffset:flatbuffers.Offset, protocolOffset:flatbuffers.Offset, port:number, typeOffset:flatbuffers.Offset, tcpTypeOffset:flatbuffers.Offset):flatbuffers.Offset {
  IceCandidate.startIceCandidate(builder);
  IceCandidate.addFoundation(builder, foundationOffset);
  IceCandidate.addPriority(builder, priority);
  IceCandidate.addIp(builder, ipOffset);
  IceCandidate.addProtocol(builder, protocolOffset);
  IceCandidate.addPort(builder, port);
  IceCandidate.addType(builder, typeOffset);
  IceCandidate.addTcpType(builder, tcpTypeOffset);
  return IceCandidate.endIceCandidate(builder);
}

unpack(): IceCandidateT {
  return new IceCandidateT(
    this.foundation(),
    this.priority(),
    this.ip(),
    this.protocol(),
    this.port(),
    this.type(),
    this.tcpType()
  );
}


unpackTo(_o: IceCandidateT): void {
  _o.foundation = this.foundation();
  _o.priority = this.priority();
  _o.ip = this.ip();
  _o.protocol = this.protocol();
  _o.port = this.port();
  _o.type = this.type();
  _o.tcpType = this.tcpType();
}
}

export class IceCandidateT {
constructor(
  public foundation: string|Uint8Array|null = null,
  public priority: number = 0,
  public ip: string|Uint8Array|null = null,
  public protocol: string|Uint8Array|null = null,
  public port: number = 0,
  public type: string|Uint8Array|null = null,
  public tcpType: string|Uint8Array|null = null
){}


pack(builder:flatbuffers.Builder): flatbuffers.Offset {
  const foundation = (this.foundation !== null ? builder.createString(this.foundation!) : 0);
  const ip = (this.ip !== null ? builder.createString(this.ip!) : 0);
  const protocol = (this.protocol !== null ? builder.createString(this.protocol!) : 0);
  const type = (this.type !== null ? builder.createString(this.type!) : 0);
  const tcpType = (this.tcpType !== null ? builder.createString(this.tcpType!) : 0);

  return IceCandidate.createIceCandidate(builder,
    foundation,
    this.priority,
    ip,
    protocol,
    this.port,
    type,
    tcpType
  );
}
}