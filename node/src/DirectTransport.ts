import { Logger } from './Logger';
import { UnsupportedError } from './errors';
import {
	BaseTransportDump,
	parseBaseTransportDump,
	parseTransportTraceEventData,
	Transport,
	TransportEvents,
	TransportObserverEvents,
	TransportConstructorOptions
} from './Transport';
import { SctpParameters } from './SctpParameters';
import { Event, Notification } from './fbs/notification_generated';
import * as FbsDirectTransport from './fbs/directTransport_generated';
import * as FbsTransport from './fbs/transport_generated';
import * as FbsNotification from './fbs/notification_generated';
import * as FbsRequest from './fbs/request_generated';

export type DirectTransportOptions =
{
	/**
	 * Maximum allowed size for direct messages sent from DataProducers.
	 * Default 262144.
	 */
	maxMessageSize: number;

	/**
	 * Custom application data.
	 */
	appData?: Record<string, unknown>;
};

export type DirectTransportStat =
{
	// Common to all Transports.
	type: string;
	transportId: string;
	timestamp: number;
	bytesReceived: number;
	recvBitrate: number;
	bytesSent: number;
	sendBitrate: number;
	rtpBytesReceived: number;
	rtpRecvBitrate: number;
	rtpBytesSent: number;
	rtpSendBitrate: number;
	rtxBytesReceived: number;
	rtxRecvBitrate: number;
	rtxBytesSent: number;
	rtxSendBitrate: number;
	probationBytesSent: number;
	probationSendBitrate: number;
	availableOutgoingBitrate?: number;
	availableIncomingBitrate?: number;
	maxIncomingBitrate?: number;
};

export type DirectTransportEvents = TransportEvents &
{
	rtcp: [Buffer];
};

export type DirectTransportObserverEvents = TransportObserverEvents &
{
	rtcp: [Buffer];
};

type DirectTransportConstructorOptions = TransportConstructorOptions &
{
	data: DirectTransportData;
};

export type DirectTransportData =
{
	sctpParameters?: SctpParameters;
};

const logger = new Logger('DirectTransport');

export class DirectTransport extends
	Transport<DirectTransportEvents, DirectTransportObserverEvents>
{
	// DirectTransport data.
	readonly #data: DirectTransportData;

	/**
	 * @private
	 */
	constructor(options: DirectTransportConstructorOptions)
	{
		super(options);

		logger.debug('constructor()');

		this.#data =
		{
			// Nothing.
		};

		this.handleWorkerNotifications();
	}

	/**
	 * Close the DirectTransport.
	 *
	 * @override
	 */
	close(): void
	{
		if (this.closed)
			return;

		super.close();
	}

	/**
	 * Router was closed.
	 *
	 * @private
	 * @override
	 */
	routerClosed(): void
	{
		if (this.closed)
			return;

		super.routerClosed();
	}

	/**
	 * Dump Transport.
	 */
	async dump(): Promise<any>
	{
		logger.debug('dump()');

		const response = await this.channel.request(
			FbsRequest.Method.TRANSPORT_DUMP,
			undefined,
			undefined,
			this.internal.transportId
		);

		/* Decode the response. */
		const dump = new FbsTransport.DumpResponse();

		response.body(dump);

		const transportDump = new FbsTransport.DirectTransportDump();

		dump.data(transportDump);

		return parseDirectTransportDump(transportDump);
	}

	/**
	 * Get DirectTransport stats.
	 *
	 * @override
	 */
	async getStats(): Promise<DirectTransportStat[]>
	{
		logger.debug('getStats()');

		const response = await this.channel.request(
			FbsRequest.Method.TRANSPORT_GET_STATS,
			undefined,
			undefined,
			this.internal.transportId
		);

		/* Decode the response. */
		const data = new FbsTransport.GetStatsResponse();

		response.body(data);

		return JSON.parse(data.stats()!);
	}

	/**
	 * NO-OP method in DirectTransport.
	 *
	 * @override
	 */
	async connect(): Promise<void>
	{
		logger.debug('connect()');
	}

	/**
	 * @override
	 */
	// eslint-disable-next-line @typescript-eslint/no-unused-vars
	async setMaxIncomingBitrate(bitrate: number): Promise<void>
	{
		throw new UnsupportedError(
			'setMaxIncomingBitrate() not implemented in DirectTransport');
	}

	/**
	 * @override
	 */
	// eslint-disable-next-line @typescript-eslint/no-unused-vars
	async setMaxOutgoingBitrate(bitrate: number): Promise<void>
	{
		throw new UnsupportedError(
			'setMaxOutgoingBitrate() not implemented in DirectTransport');
	}

	/**
	 * Send RTCP packet.
	 */
	sendRtcp(rtcpPacket: Buffer)
	{
		if (!Buffer.isBuffer(rtcpPacket))
		{
			throw new TypeError('rtcpPacket must be a Buffer');
		}

		const builder = this.channel.bufferBuilder;
		const dataOffset =
			FbsTransport.SendRtcpNotification.createDataVector(builder, rtcpPacket);
		const notificationOffset =
			FbsTransport.SendRtcpNotification.createSendRtcpNotification(
				builder,
				dataOffset
			);

		this.channel.notify(
			FbsNotification.Event.TRANSPORT_SEND_RTCP,
			FbsNotification.Body.FBS_Transport_SendRtcpNotification,
			notificationOffset,
			this.internal.transportId
		);

	}

	private handleWorkerNotifications(): void
	{
		this.channel.on(this.internal.transportId, (event: Event, data?: Notification) =>
		{
			switch (event)
			{
				case Event.TRANSPORT_TRACE:
				{
					const notification = new FbsTransport.TraceNotification();

					data!.body(notification);

					const trace = parseTransportTraceEventData(notification);

					this.safeEmit('trace', trace);

					// Emit observer event.
					this.observer.safeEmit('trace', trace);

					break;
				}

				case Event.DIRECTTRANSPORT_RTCP:
				{
					if (this.closed)
						break;

					const notification = new FbsDirectTransport.RtcpNotification();

					data!.body(notification);

					this.safeEmit('rtcp', Buffer.from(notification.dataArray()!));

					break;
				}

				default:
				{
					logger.error('ignoring unknown event "%s"', event);
				}
			}
		});
	}
}

export function parseDirectTransportDump(
	binary: FbsTransport.DirectTransportDump
): BaseTransportDump
{
	// Retrieve BaseTransportDump.
	const fbsBaseTransportDump = new FbsTransport.BaseTransportDump();

	binary.base()!.data(fbsBaseTransportDump);

	return parseBaseTransportDump(fbsBaseTransportDump);
}
