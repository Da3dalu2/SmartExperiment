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
	private final MsgParser parser;
	private final MsgParserLoop parserLoop;
	private View view;
	private final ExperimentationSystem system;
	private boolean started;

	public ControllerImpl(final ExperimentationSystem system) {
		this.system = system;
		started = false;
		commChannel = Optional.empty();
		try {
			commChannel = Optional.of(new SerialCommChannel(PORT, RATE));
		} catch (final Exception e) {
			logger.log(Level.SEVERE, e.toString());
		}
		parser = new MsgParserImpl(commChannel.orElseThrow(), this);
		parserLoop = MsgParserThread.createParsingLoop(parser, system);
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
		return view.requestExperimentationEndConfirmation();
	}

	@Override
	public void updateSystemStatus(SystemStatus status) {
		system.setStatus(status);
		view.updateStatusDisplay(status);
		handleParserLoop(status);
	}

	private void handleParserLoop(SystemStatus status) {
		if (status.equals(SystemStatus.Running) || !started) {
			parserLoop.startLoop();
			started = true;
		} else if (status.equals(SystemStatus.Running) || started) {
			parserLoop.resumeLoop();
		} else {
			parserLoop.pauseLoop();
		}
	}
}