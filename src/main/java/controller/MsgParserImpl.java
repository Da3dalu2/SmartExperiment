package controller;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.logging.Level;
import java.util.logging.Logger;

import model.SensorMeasures;
import model.SystemStatus;

public class MsgParserImpl implements MsgParser {

	private static final Logger logger = Logger.getLogger("MsgParserImpl");

	Map<SensorMeasures, BlockingQueue<Float>> dataQueues;
	private static final int MESSAGE_QUEUE_CAPACITY = 250;

	private final CommChannel commChannel;
	private final Controller controller;

	MsgParserImpl(CommChannel commChannel, Controller controller) {
		dataQueues = new HashMap<>();
		initDataQueues();
		this.commChannel = commChannel;
		this.controller = controller;
	}

	private void initDataQueues() {
		for (final SensorMeasures measure : SensorMeasures.values()) {
			final BlockingQueue<Float> measureQueue = new ArrayBlockingQueue<>(
					MESSAGE_QUEUE_CAPACITY);
			dataQueues.put(measure, measureQueue);
		}
	}

	@Override
	public float[] getIncomingData(SensorMeasures metric) {
		Optional<Float> newData = Optional.empty();
		newData = Optional.ofNullable(dataQueues.get(metric).poll());
		logger.log(Level.INFO,
				"[Timer]: gathering data for " + metric.toString() + "\n");
		final float[] data = new float[1];
		if (newData.isEmpty()) {
			logger.log(Level.INFO, "[Timer]: no data received");
			data[0] = 0;
		} else
			data[0] = newData.get();
		return data;
	}

	@Override
	public void parseIncomingData() {
		String msg = "";
		if (commChannel.isMsgAvailable()) {
			try {
				msg = commChannel.receiveMsg();
				logger.log(Level.INFO, msg);
			} catch (final InterruptedException e) {
				logger.log(Level.SEVERE, e.toString());
			}
			handleMessage(msg);
		}
	}

	private void handleMessage(String msg) {
		switch (msg) {
		case "{running}":
			logger.log(Level.INFO, "[ParserLoop]: Experiment began!");
			controller.updateSystemStatus(SystemStatus.Running);
			break;
		case "{ending}":
			/*if (controller.askForEndConfirmation()) {
				logger.log(Level.INFO,
						"[ParserLoop]: experiment ending confirmed");
				commChannel.sendMsg("{exitConfirmed}");
			} else {
				logger.log(Level.INFO,
						"[ParserLoop]: experiment ending not confirmed");
				commChannel.sendMsg("{exitNotConfirmed}");
			}*/
			logger.log(Level.INFO, "[ParserLoop]: Ending experiment");
			break;
		case "{error}":
			logger.log(Level.INFO, "[ParserLoop]: Error detected");
			controller.updateSystemStatus(SystemStatus.Error);
			break;
		case "{suspended}":
			logger.log(Level.INFO,
					"[ParserLoop]: System entered power-saving mode");
			controller.updateSystemStatus(SystemStatus.Suspended);
			break;
		case "{ready}":
			logger.log(Level.INFO, "[ParserLoop]: The system is ready");
			controller.updateSystemStatus(SystemStatus.Ready);
			break;
		default:
			logger.log(Level.INFO,
					"[ParserLoop]: Processing the message received to extract"
							+ "measurements");
			extractSensorMeasures(msg);
		}
	}

	private void extractSensorMeasures(String msg) {
		final String[] tokens = msg.split("[\\[\\];]+");

		if (tokens.length != SensorMeasures.values().length - 1)
			logger.log(Level.WARNING, "Invalid message");

		final float speed = Float.parseFloat(tokens[1]);
		final float distance = Float.parseFloat(tokens[2]);
		final float acceleration = Float.parseFloat(tokens[3]);

		try {
			dataQueues.get(SensorMeasures.Speed).put(speed);
			dataQueues.get(SensorMeasures.Distance).put(distance);
			dataQueues.get(SensorMeasures.Acceleration).put(acceleration);
		} catch (final InterruptedException e) {
			logger.log(Level.SEVERE, e.toString());
		}
	}
}