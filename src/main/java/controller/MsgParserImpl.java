package controller;

import java.util.Map;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

import model.SensorMeasures;
import model.SystemStatus;

public class MsgParserImpl implements MsgParser {

	Map<SensorMeasures, BlockingQueue<Float>> dataQueues;
	private static final Logger logger = Logger.getLogger("MsgParserImpl");
	private final CommChannel commChannel;
	private final Controller controller;

	MsgParserImpl(CommChannel commChannel, Controller controller) {
		this.commChannel = commChannel;
		this.controller = controller;
	}

	@Override
	public float[] getIncomingData(SensorMeasures metric) {
		final float[] newData = new float[1];
		try {
			newData[0] = dataQueues.get(metric).poll(50, TimeUnit.MILLISECONDS);
		} catch (final InterruptedException e) {
			logger.log(Level.SEVERE, e.toString());
		}
		if (newData.length == 0) {
			newData[0] = 0;
		}
		return newData;
	}

	@Override
	public void parseIncomingData() {
		String msg = "";
		if (commChannel.isMsgAvailable()) {
			try {
				msg = commChannel.receiveMsg();
			} catch (final InterruptedException e) {
				logger.log(Level.SEVERE, e.toString());
			}
		}

		handleMessage(msg);
	}

	private void handleMessage(String msg) {
		switch (msg) {
		case "{running}":
			controller.updateSystemStatus(SystemStatus.Running);
		case "{ending}":
			if (controller.askForEndConfirmation())
				controller.updateSystemStatus(SystemStatus.Ready);
			else
				controller.updateSystemStatus(SystemStatus.Running);
		case "{error}":
			controller.updateSystemStatus(SystemStatus.Error);
		case "{suspended}":
			controller.updateSystemStatus(SystemStatus.Suspended);
		case "{ready}":
			controller.updateSystemStatus(SystemStatus.Ready);
		default:
			extractSensorMeasures(msg);
		}
	}

	private void extractSensorMeasures(String msg) {
		final String[] tokens = msg.split("[\\[\\];]+");

		if (tokens.length != SensorMeasures.values().length - 1) {
			logger.log(Level.WARNING, "Invalid message");
		}

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