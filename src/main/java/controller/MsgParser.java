package controller;

import model.SensorMeasures;

/**
 * This parser is used by the thread listening for messages on
 * the serial port and is able to recognize a set of messages
 * from the Arduino Uno board.
 *
 * In addition it is able to store the data related to each
 * measurement taken by the experimentation system aboard
 * the microcontroller in a blocking queue.
 *
 * All the queues are grouped in a map. A convenience method
 * is given to allow retrieval of the latest data of a specified
 * measurement.
 *
 */
public interface MsgParser {

	/**
	 * Called by the View to obtain updated values to plot.
	 *
	 * @param metric the type of measure for which new data is available
	 * @return a value used to update the graphs
	 */
	float[] getIncomingData(SensorMeasures metric);

	/**
	 * Called by the thread that listens for incoming messages.
	 * Holds the logic for interpreting these messages.
	 */
	void parseIncomingData();

}
