package controller;

import java.util.Optional;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ControllerImpl implements Controller {
	
	private static final String PORT = "/dev/ttyACM0";
	private static final int RATE = 9600;
	private Optional<CommChannel> commChannel;
	private static final Logger logger = Logger.getLogger("DatasetGeneratorImpl");
	private MsgParser parser;
	
	public ControllerImpl() {
		commChannel = Optional.empty();
		try {
			commChannel = Optional.of(new SerialCommChannel(PORT, RATE));
		} catch (Exception e) {
			logger.log(Level.SEVERE, e.toString());
		}
		parser = new MsgParserImpl(commChannel.orElseThrow());
	}
	
	@Override
	public MsgParser getMsgParser() {
		return parser;
	}

}
