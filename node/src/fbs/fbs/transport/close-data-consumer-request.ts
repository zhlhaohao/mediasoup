// automatically generated by the FlatBuffers compiler, do not modify

import * as flatbuffers from 'flatbuffers';



export class CloseDataConsumerRequest {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):CloseDataConsumerRequest {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

static getRootAsCloseDataConsumerRequest(bb:flatbuffers.ByteBuffer, obj?:CloseDataConsumerRequest):CloseDataConsumerRequest {
  return (obj || new CloseDataConsumerRequest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

static getSizePrefixedRootAsCloseDataConsumerRequest(bb:flatbuffers.ByteBuffer, obj?:CloseDataConsumerRequest):CloseDataConsumerRequest {
  bb.setPosition(bb.position() + flatbuffers.SIZE_PREFIX_LENGTH);
  return (obj || new CloseDataConsumerRequest()).__init(bb.readInt32(bb.position()) + bb.position(), bb);
}

dataConsumerId():string|null
dataConsumerId(optionalEncoding:flatbuffers.Encoding):string|Uint8Array|null
dataConsumerId(optionalEncoding?:any):string|Uint8Array|null {
  const offset = this.bb!.__offset(this.bb_pos, 4);
  return offset ? this.bb!.__string(this.bb_pos + offset, optionalEncoding) : null;
}

static startCloseDataConsumerRequest(builder:flatbuffers.Builder) {
  builder.startObject(1);
}

static addDataConsumerId(builder:flatbuffers.Builder, dataConsumerIdOffset:flatbuffers.Offset) {
  builder.addFieldOffset(0, dataConsumerIdOffset, 0);
}

static endCloseDataConsumerRequest(builder:flatbuffers.Builder):flatbuffers.Offset {
  const offset = builder.endObject();
  builder.requiredField(offset, 4) // data_consumer_id
  return offset;
}

static createCloseDataConsumerRequest(builder:flatbuffers.Builder, dataConsumerIdOffset:flatbuffers.Offset):flatbuffers.Offset {
  CloseDataConsumerRequest.startCloseDataConsumerRequest(builder);
  CloseDataConsumerRequest.addDataConsumerId(builder, dataConsumerIdOffset);
  return CloseDataConsumerRequest.endCloseDataConsumerRequest(builder);
}

unpack(): CloseDataConsumerRequestT {
  return new CloseDataConsumerRequestT(
    this.dataConsumerId()
  );
}


unpackTo(_o: CloseDataConsumerRequestT): void {
  _o.dataConsumerId = this.dataConsumerId();
}
}

export class CloseDataConsumerRequestT {
constructor(
  public dataConsumerId: string|Uint8Array|null = null
){}


pack(builder:flatbuffers.Builder): flatbuffers.Offset {
  const dataConsumerId = (this.dataConsumerId !== null ? builder.createString(this.dataConsumerId!) : 0);

  return CloseDataConsumerRequest.createCloseDataConsumerRequest(builder,
    dataConsumerId
  );
}
}