package controller;

import java.util.Optional;
import java.util.logging.Level;
import java.util.logging.Logger;

import model.ExperimentationSystem;
import model.SystemStatus;
import view.View;

/**
 * Controller holds a reference to the view and the model.
 * It allows the creation of a communication channel over
 * serial port /dev/ttyACM0 with the Arduino Uno board.
 *
 * In addition this class allows spawning a thread used
 * to listen for serial events, allowing to receive and
 * elaborate a constant stream of real-time data coming
 * from the Arduino.
 *
 * The status of the system, held in the model class Experimentation System,
 * is updated accordingly to the information given by the Arduino.
 *
 * The updates are signaled by the thread that listens for serial events.
 * The Controller mantains the model in sync with these updates and the
 * View asks the Controller for updates when is needed.
 *
 * The Controller tells the View when an alert for asking the confirmation
 * for ending the experiment should be spawn and waits for the result,
 * finally sending the message with the result to the board.
 *
 */
public class ControllerImpl implements Controller {

	private static final Logger logger = Logger.getLogger("ControllerImpl");

	private static final String PORT = "/dev/ttyACM0";
	private static final int RATE = 9600;
	private Optional<CommChannel> commChannel;

	private MsgParser parser;
	private MsgParserLoop parserLoop;

	private View view;
	private final ExperimentationSystem system;

	public ControllerImpl(final ExperimentationSystem system) {
		this.system = system;
		commChannel = Optional.empty();
	}

	@Override
	public void setView(View view) {
		this.view = view;
	}

	@Override
	public void init() {
		try {
			commChannel = Optional.of(new SerialCommChannel(PORT, RATE));
		} catch (final Exception e) {
			logger.log(Level.SEVERE, e.toString());
		}
		parser = new MsgParserImpl(commChannel.orElseThrow(), this);
		logger.log(Level.INFO,
				"[Controller]: Establishing serial communications");
		parserLoop = MsgParserThread.createParsingLoop(parser, system);
		logger.log(Level.INFO, "[Controller]: Creating ParserLoop");
		parserLoop.startLoop();
	}

	@Override
	public MsgParser getMsgParser() {
		return parser;
	}

	@Override
	public boolean askForEndConfirmation() {
		logger.log(Level.INFO, "[Application]: Requesting end confirmation");
		return view.requestExperimentationEndConfirmation();
	}

	@Override
	public void updateSystemStatus(SystemStatus status) {
		logger.log(Level.INFO, "[ParserLoop]: Status update");
		system.setStatus(status);
		view.updateStatusDisplay(status);
	}

	@Override
	public void cleanClose() {
		logger.log(Level.INFO, "[Application]: Closing serial port");
		commChannel.get().close();
	}
}