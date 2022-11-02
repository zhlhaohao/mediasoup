import * as flatbuffers from 'flatbuffers';
import {
	Double as FbsDouble,
	Integer as FbsInteger,
	IntegerArray as FbsIntegerArray,
	Parameter as FbsParameter,
	RtcpFeedback as FbsRtcpFeedback,
	RtcpParameters as FbsRtcpParameters,
	RtpCodecParameters as FbsRtpCodecParameters,
	RtpEncodingParameters as FbsRtpEncodingParameters,
	RtpHeaderExtensionParameters as FbsRtpHeaderExtensionParameters,
	RtpParameters as FbsRtpParameters,
	Rtx as FbsRtx,
	Value as FbsValue
} from './fbs/rtpParameters_generated';

/**
 * The RTP capabilities define what mediasoup or an endpoint can receive at
 * media level.
 */
export type RtpCapabilities =
{
	/**
	 * Supported media and RTX codecs.
	 */
	codecs?: RtpCodecCapability[];

	/**
	 * Supported RTP header extensions.
	 */
	headerExtensions?: RtpHeaderExtension[];
};

/**
 * Media kind ('audio' or 'video').
 */
export type MediaKind = 'audio' | 'video';

/**
 * Provides information on the capabilities of a codec within the RTP
 * capabilities. The list of media codecs supported by mediasoup and their
 * settings is defined in the supportedRtpCapabilities.ts file.
 *
 * Exactly one RtpCodecCapability will be present for each supported combination
 * of parameters that requires a distinct value of preferredPayloadType. For
 * example:
 *
 * - Multiple H264 codecs, each with their own distinct 'packetization-mode' and
 *   'profile-level-id' values.
 * - Multiple VP9 codecs, each with their own distinct 'profile-id' value.
 *
 * RtpCodecCapability entries in the mediaCodecs array of RouterOptions do not
 * require preferredPayloadType field (if unset, mediasoup will choose a random
 * one). If given, make sure it's in the 96-127 range.
 */
export type RtpCodecCapability =
{
	/**
	 * Media kind.
	 */
	kind: MediaKind;

	/**
	 * The codec MIME media type/subtype (e.g. 'audio/opus', 'video/VP8').
	 */
	mimeType: string;

	/**
	 * The preferred RTP payload type.
	 */
	preferredPayloadType?: number;

	/**
	 * Codec clock rate expressed in Hertz.
	 */
	clockRate: number;

	/**
	 * The number of channels supported (e.g. two for stereo). Just for audio.
	 * Default 1.
	 */
	channels?: number;

	/**
	 * Codec specific parameters. Some parameters (such as 'packetization-mode'
	 * and 'profile-level-id' in H264 or 'profile-id' in VP9) are critical for
	 * codec matching.
	 */
	parameters?: any;

	/**
	 * Transport layer and codec-specific feedback messages for this codec.
	 */
	rtcpFeedback?: RtcpFeedback[];
};

/**
 * Direction of RTP header extension.
 */
export type RtpHeaderExtensionDirection = 'sendrecv' | 'sendonly' | 'recvonly' | 'inactive';

/**
 * Provides information relating to supported header extensions. The list of
 * RTP header extensions supported by mediasoup is defined in the
 * supportedRtpCapabilities.ts file.
 *
 * mediasoup does not currently support encrypted RTP header extensions. The
 * direction field is just present in mediasoup RTP capabilities (retrieved via
 * router.rtpCapabilities or mediasoup.getSupportedRtpCapabilities()). It's
 * ignored if present in endpoints' RTP capabilities.
 */
export type RtpHeaderExtension =
{
	/**
	 * Media kind.
	 */
	kind: MediaKind;

	/*
	 * The URI of the RTP header extension, as defined in RFC 5285.
	 */
	uri: string;

	/**
	 * The preferred numeric identifier that goes in the RTP packet. Must be
	 * unique.
	 */
	preferredId: number;

	/**
	 * If true, it is preferred that the value in the header be encrypted as per
	 * RFC 6904. Default false.
	 */
	preferredEncrypt?: boolean;

	/**
	 * If 'sendrecv', mediasoup supports sending and receiving this RTP extension.
	 * 'sendonly' means that mediasoup can send (but not receive) it. 'recvonly'
	 * means that mediasoup can receive (but not send) it.
	 */
	direction?: RtpHeaderExtensionDirection;
};

/**
 * The RTP send parameters describe a media stream received by mediasoup from
 * an endpoint through its corresponding mediasoup Producer. These parameters
 * may include a mid value that the mediasoup transport will use to match
 * received RTP packets based on their MID RTP extension value.
 *
 * mediasoup allows RTP send parameters with a single encoding and with multiple
 * encodings (simulcast). In the latter case, each entry in the encodings array
 * must include a ssrc field or a rid field (the RID RTP extension value). Check
 * the Simulcast and SVC sections for more information.
 *
 * The RTP receive parameters describe a media stream as sent by mediasoup to
 * an endpoint through its corresponding mediasoup Consumer. The mid value is
 * unset (mediasoup does not include the MID RTP extension into RTP packets
 * being sent to endpoints).
 *
 * There is a single entry in the encodings array (even if the corresponding
 * producer uses simulcast). The consumer sends a single and continuous RTP
 * stream to the endpoint and spatial/temporal layer selection is possible via
 * consumer.setPreferredLayers().
 *
 * As an exception, previous bullet is not true when consuming a stream over a
 * PipeTransport, in which all RTP streams from the associated producer are
 * forwarded verbatim through the consumer.
 *
 * The RTP receive parameters will always have their ssrc values randomly
 * generated for all of its  encodings (and optional rtx: { ssrc: XXXX } if the
 * endpoint supports RTX), regardless of the original RTP send parameters in
 * the associated producer. This applies even if the producer's encodings have
 * rid set.
 */
export type RtpParameters =
{
	/**
	 * The MID RTP extension value as defined in the BUNDLE specification.
	 */
	mid?: string;

	/**
	 * Media and RTX codecs in use.
	 */
	codecs: RtpCodecParameters[];

	/**
	 * RTP header extensions in use.
	 */
	headerExtensions?: RtpHeaderExtensionParameters[];

	/**
	 * Transmitted RTP streams and their settings.
	 */
	encodings?: RtpEncodingParameters[];

	/**
	 * Parameters used for RTCP.
	 */
	rtcp?: RtcpParameters;
};

/**
 * Provides information on codec settings within the RTP parameters. The list
 * of media codecs supported by mediasoup and their settings is defined in the
 * supportedRtpCapabilities.ts file.
 */
export type RtpCodecParameters =
{
	/**
	 * The codec MIME media type/subtype (e.g. 'audio/opus', 'video/VP8').
	 */
	mimeType: string;

	/**
	 * The value that goes in the RTP Payload Type Field. Must be unique.
	 */
	payloadType: number;

	/**
	 * Codec clock rate expressed in Hertz.
	 */
	clockRate: number;

	/**
	 * The number of channels supported (e.g. two for stereo). Just for audio.
	 * Default 1.
	 */
	channels?: number;

	/**
	 * Codec-specific parameters available for signaling. Some parameters (such
	 * as 'packetization-mode' and 'profile-level-id' in H264 or 'profile-id' in
	 * VP9) are critical for codec matching.
	 */
	parameters?: any;

	/**
	 * Transport layer and codec-specific feedback messages for this codec.
	 */
	rtcpFeedback?: RtcpFeedback[];
};

/**
 * Provides information on RTCP feedback messages for a specific codec. Those
 * messages can be transport layer feedback messages or codec-specific feedback
 * messages. The list of RTCP feedbacks supported by mediasoup is defined in the
 * supportedRtpCapabilities.ts file.
 */
export type RtcpFeedback =
{
	/**
	 * RTCP feedback type.
	 */
	type: string;

	/**
	 * RTCP feedback parameter.
	 */
	parameter?: string;
};

/**
 * Provides information relating to an encoding, which represents a media RTP
 * stream and its associated RTX stream (if any).
 */
export type RtpEncodingParameters =
{
	/**
	 * The media SSRC.
	 */
	ssrc?: number;

	/**
	 * The RID RTP extension value. Must be unique.
	 */
	rid?: string;

	/**
	 * Codec payload type this encoding affects. If unset, first media codec is
	 * chosen.
	 */
	codecPayloadType?: number;

	/**
	 * RTX stream information. It must contain a numeric ssrc field indicating
	 * the RTX SSRC.
	 */
	rtx?: { ssrc: number };

	/**
	 * It indicates whether discontinuous RTP transmission will be used. Useful
	 * for audio (if the codec supports it) and for video screen sharing (when
	 * static content is being transmitted, this option disables the RTP
	 * inactivity checks in mediasoup). Default false.
	 */
	dtx?: boolean;

	/**
	 * Number of spatial and temporal layers in the RTP stream (e.g. 'L1T3').
	 * See webrtc-svc.
	 */
	scalabilityMode?: string;

	/**
	 * Others.
	 */
	scaleResolutionDownBy?: number;
	maxBitrate?: number;
};

/**
 * Defines a RTP header extension within the RTP parameters. The list of RTP
 * header extensions supported by mediasoup is defined in the
 * supportedRtpCapabilities.ts file.
 *
 * mediasoup does not currently support encrypted RTP header extensions and no
 * parameters are currently considered.
 */
export type RtpHeaderExtensionParameters =
{
	/**
	 * The URI of the RTP header extension, as defined in RFC 5285.
	 */
	uri: string;

	/**
	 * The numeric identifier that goes in the RTP packet. Must be unique.
	 */
	id: number;

	/**
	 * If true, the value in the header is encrypted as per RFC 6904. Default false.
	 */
	encrypt?: boolean;

	/**
	 * Configuration parameters for the header extension.
	 */
	parameters?: any;
};

/**
 * Provides information on RTCP settings within the RTP parameters.
 *
 * If no cname is given in a producer's RTP parameters, the mediasoup transport
 * will choose a random one that will be used into RTCP SDES messages sent to
 * all its associated consumers.
 *
 * mediasoup assumes reducedSize to always be true.
 */
export type RtcpParameters =
{
	/**
	 * The Canonical Name (CNAME) used by RTCP (e.g. in SDES messages).
	 */
	cname?: string;

	/**
	 * Whether reduced size RTCP RFC 5506 is configured (if true) or compound RTCP
	 * as specified in RFC 3550 (if false). Default true.
	 */
	reducedSize?: boolean;

	/**
	 * Whether RTCP-mux is used. Default true.
	 */
	mux?: boolean;
};

export function serializeRtpParameters(
	builder: flatbuffers.Builder, rtpParameters: RtpParameters
): number
{
	const codecs: number[] = [];
	const headerExtensions: number[] = [];

	for (const codec of rtpParameters.codecs)
	{
		const mimeTypeOffset = builder.createString(codec.mimeType);

		const codecParameters: number[] = [];

		for (const key of Object.keys(codec.parameters))
		{
			const value = codec.parameters[key];
			const keyOffset = builder.createString(key);
			let parameterOffset: number;

			if (typeof value === 'boolean')
			{
				parameterOffset = FbsParameter.createParameter(
					builder, keyOffset, FbsValue.Boolean, value === true ? 1:0
				);
			}

			else if (typeof value === 'number')
			{
				// Integer.
				if (value % 1 === 0)
				{
					const valueOffset = FbsInteger.createInteger(builder, value);

					parameterOffset = FbsParameter.createParameter(
						builder, keyOffset, FbsValue.Integer, valueOffset
					);
				}
				// Float.
				else
				{
					const valueOffset = FbsDouble.createDouble(builder, value);

					parameterOffset = FbsParameter.createParameter(
						builder, keyOffset, FbsValue.Double, valueOffset
					);
				}
			}

			else if (typeof value === 'string')
			{
				const valueOffset = builder.createString(value);

				parameterOffset = FbsParameter.createParameter(
					builder, keyOffset, FbsValue.String, valueOffset
				);
			}

			else if (Array.isArray(value))
			{
				const valueOffset = FbsIntegerArray.createValueVector(builder, value);

				parameterOffset = FbsParameter.createParameter(
					builder, keyOffset, FbsValue.IntegerArray, valueOffset
				);
			}

			else
			{
				throw new Error(`invalid parameter type [key:'${key}', value:${value}]`);
			}

			codecParameters.push(parameterOffset);
		}
		const parametersOffset =
			FbsRtpCodecParameters.createParametersVector(builder, codecParameters);

		const rtcpFeedback: number[] = [];

		for (const rtcp of codec.rtcpFeedback?? [])
		{
			const typeOffset = builder.createString(rtcp.type);
			const rtcpParametersOffset = builder.createString(rtcp.parameter);

			rtcpFeedback.push(
				FbsRtcpFeedback.createRtcpFeedback(builder, typeOffset, rtcpParametersOffset));
		}
		const rtcpFeedbackOffset =
			FbsRtpCodecParameters.createRtcpFeedbackVector(builder, rtcpFeedback);

		codecs.push(
			FbsRtpCodecParameters.createRtpCodecParameters(
				builder,
				mimeTypeOffset,
				codec.payloadType,
				codec.clockRate,
				Number(codec.channels),
				parametersOffset,
				rtcpFeedbackOffset
			));
	}
	const codecsOffset = FbsRtpParameters.createCodecsVector(builder, codecs);

	// RtpHeaderExtensionParameters.
	for (const headerExtension of rtpParameters.headerExtensions ?? [])
	{
		const uriOffset = builder.createString(headerExtension.uri);
		const parametersOffset = builder.createString(headerExtension.parameters);

		headerExtensions.push(
			FbsRtpHeaderExtensionParameters.createRtpHeaderExtensionParameters(
				builder,
				uriOffset,
				headerExtension.id,
				Boolean(headerExtension.encrypt),
				parametersOffset));
	}
	const headerExtensionsOffset =
		FbsRtpParameters.createHeaderExtensionsVector(builder, headerExtensions);

	// RtpEncodingParameters.
	let encodingsOffset: number | undefined;

	if (rtpParameters.encodings)
		encodingsOffset = serializeRtpEncodingParameters(builder, rtpParameters.encodings);

	// RtcpParameters.
	let rtcpOffset: number | undefined;

	if (rtpParameters.rtcp)
	{
		const { cname, reducedSize, mux } = rtpParameters.rtcp;
		const cnameOffset = builder.createString(cname);

		rtcpOffset = FbsRtcpParameters.createRtcpParameters(
			builder, cnameOffset, Boolean(reducedSize), Boolean(mux)
		);
	}

	const midOffset = builder.createString(rtpParameters.mid);

	FbsRtpParameters.startRtpParameters(builder);
	FbsRtpParameters.addMid(builder, midOffset);
	FbsRtpParameters.addCodecs(builder, codecsOffset);

	if (headerExtensions.length > 0)
		FbsRtpParameters.addHeaderExtensions(builder, headerExtensionsOffset);

	if (encodingsOffset)
		FbsRtpParameters.addEncodings(builder, encodingsOffset);

	if (rtcpOffset)
		FbsRtpParameters.addRtcp(builder, rtcpOffset);

	return FbsRtpParameters.endRtpParameters(builder);
}

export function serializeRtpEncodingParameters(
	builder: flatbuffers.Builder, rtpEncodingParameters: RtpEncodingParameters[]
): number
{
	const encodings: number[] = [];

	for (const encoding of rtpEncodingParameters ?? [])
	{
		// Prepare Rid.
		const ridOffset = builder.createString(encoding.rid);

		// Prepare Rtx.
		let rtxOffset: number | undefined;

		if (encoding.rtx)
			FbsRtx.createRtx(builder, encoding.rtx.ssrc);

		// Prepare scalability mode.
		let scalabilityModeOffset: number | undefined;

		if (encoding.scalabilityMode)
			scalabilityModeOffset = builder.createString(encoding.scalabilityMode);

		// Start serialization.
		FbsRtpEncodingParameters.startRtpEncodingParameters(builder);

		// Add SSRC.
		if (encoding.ssrc)
			FbsRtpEncodingParameters.addSsrc(builder, encoding.ssrc);

		// Add Rid.
		FbsRtpEncodingParameters.addRid(builder, ridOffset);

		// Add payload type.
		if (encoding.codecPayloadType)
			FbsRtpEncodingParameters.addCodecPayloadType(builder, encoding.codecPayloadType);

		// Add RTX.
		if (rtxOffset)
			FbsRtpEncodingParameters.addRtx(builder, rtxOffset);

		// Add DTX.
		if (encoding.dtx !== undefined)
			FbsRtpEncodingParameters.addDtx(builder, encoding.dtx);

		// Add scalability ode.
		if (scalabilityModeOffset)
			FbsRtpEncodingParameters.addScalabilityMode(builder, scalabilityModeOffset);

		// Add scale resolution down by.
		if (encoding.scaleResolutionDownBy !== undefined)
		{
			FbsRtpEncodingParameters.addScaleResolutionDownBy(
				builder, encoding.scaleResolutionDownBy);
		}

		// Add max bitrate.
		if (encoding.maxBitrate !== undefined)
			FbsRtpEncodingParameters.addMaxBitrate(builder, encoding.maxBitrate);

		// End serialization.
		encodings.push(FbsRtpEncodingParameters.endRtpEncodingParameters(builder));
	}

	return FbsRtpParameters.createEncodingsVector(builder, encodings);
}
