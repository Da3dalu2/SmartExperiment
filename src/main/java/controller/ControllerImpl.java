package controller;

import java.util.Optional;
import java.util.logging.Level;
import java.util.logging.Logger;

import model.ExperimentationSystem;
import model.SystemStatus;
import view.View;

public class ControllerImpl implements Controller {

	private static final String PORT = "/dev/ttyACM0";
	private static final int RATE = 9600;
	private Optional<CommChannel> commChannel;
	private static final Logger logger = Logger.getLogger("ControllerImpl");
	private MsgParser parser;
	private MsgParserLoop parserLoop;
	private View view;
	private final ExperimentationSystem system;

	public ControllerImpl(final ExperimentationSystem system) {
		this.system = system;
		commChannel = Optional.empty();
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
	public void setView(View view) {
		this.view = view;
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