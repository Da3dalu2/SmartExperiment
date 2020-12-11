package controller;

import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;
import java.util.logging.Level;
import java.util.logging.Logger;

import jssc.SerialPort;
import jssc.SerialPortEvent;
import jssc.SerialPortEventListener;

/**
 * Communication channel implementation using jssc.
 */
public class SerialCommChannel implements CommChannel, SerialPortEventListener {

	private static final Logger logger = Logger.getLogger("SerialCommChannel");

	private final SerialPort serialPort;

	private final BlockingQueue<String> queue;
	private StringBuffer currentMsg = new StringBuffer("");
	private static final int MESSAGE_QUEUE_CAPACITY = 1000;

	public SerialCommChannel(String port, int rate) throws Exception {
		queue = new ArrayBlockingQueue<String>(MESSAGE_QUEUE_CAPACITY);

		serialPort = new SerialPort(port);
		serialPort.openPort();

		serialPort.setParams(rate, SerialPort.DATABITS_8, SerialPort.STOPBITS_1,
				SerialPort.PARITY_NONE);

		serialPort.setFlowControlMode(SerialPort.FLOWCONTROL_RTSCTS_IN
				| SerialPort.FLOWCONTROL_RTSCTS_OUT);

		serialPort.addEventListener(this);
	}

	@Override
	public void sendMsg(String msg) {
		final char[] array = (msg + "\n").toCharArray();
		final byte[] bytes = new byte[array.length];
		for (int i = 0; i < array.length; i++)
			bytes[i] = (byte) array[i];
		try {
			synchronized (serialPort) {
				serialPort.writeBytes(bytes);
			}
		} catch (final Exception e) {
			logger.log(Level.SEVERE, e.toString());
		}
	}

	@Override
	public String receiveMsg() throws InterruptedException {
		return queue.take();
	}

	@Override
	public boolean isMsgAvailable() {
		return !queue.isEmpty();
	}

	/**
	 * This method is called to avoid port locking on Unix-like platforms.
	 */
	@Override
	public void close() {
		try {
			if (serialPort != null) {
				serialPort.removeEventListener();
				serialPort.closePort();
			}
		} catch (final Exception e) {
			logger.log(Level.SEVERE, e.toString());
		}
	}

	@Override
	public void serialEvent(SerialPortEvent event) {
		/* if there are bytes received in the input buffer */
		if (event.isRXCHAR())
			try {
				String msg = serialPort.readString(event.getEventValue());

				msg = msg.replaceAll("\r", "");

				currentMsg.append(msg);

				boolean goAhead = true;

				while (goAhead) {
					final String msg2 = currentMsg.toString();
					final int index = msg2.indexOf("\n");
					if (index >= 0) {
						queue.put(msg2.substring(0, index));
						currentMsg = new StringBuffer("");
						if (index + 1 < msg2.length())
							currentMsg.append(msg2.substring(index + 1));
					} else
						goAhead = false;
				}

			} catch (final Exception e) {
				logger.log(Level.SEVERE, e.toString());
			}
	}
}
