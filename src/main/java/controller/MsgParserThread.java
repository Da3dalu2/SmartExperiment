package controller;

import model.ExperimentationSystem;

public final class MsgParserThread extends Thread implements MsgParserLoop {

	private static final long MS_BETWEEN_TICKS = 20;
	private final MsgParser parser;
	private volatile boolean paused;
	private volatile boolean stopped;

	private MsgParserThread(final MsgParser parser,
			final ExperimentationSystem system) {
		this.parser = parser;
		paused = false;
		stopped = false;
	}

	/**
	 * Static factory to create the parser loop, cannot be instantiated outside
	 * package controller.
	 *
	 * @param view     the view of the application
	 * @param scenario the current loaded scenario
	 * @return the new thread that performs the loop
	 */
	public static MsgParserThread createParsingLoop(final MsgParser parser,
			final ExperimentationSystem system) {
		final MsgParserThread parseLoop = new MsgParserThread(parser, system);
		parseLoop.setName("ParsingLoop");
		parseLoop.setDaemon(true);
		return parseLoop;
	}

	private void parseData() {
		parser.parseIncomingData();
	}

	private void waitForNextFrame(final long current) {
		final long dt = System.currentTimeMillis() - current;
		if (dt < MS_BETWEEN_TICKS) {
			try {
				Thread.sleep(MS_BETWEEN_TICKS - dt);
			} catch (final InterruptedException ex) {
			}
		}
	}

	private synchronized void handlePauseState() {
		while (paused) {
			try {
				this.wait();
			} catch (final InterruptedException e) {
			}
		}
	}

	@Override
	public void run() {
		while (!stopped) {
			if (paused) {
				handlePauseState();
			}
			final long current = System.currentTimeMillis();
			parseData();
			waitForNextFrame(current);
		}
	}

	@Override
	public synchronized void pauseLoop() {
		paused = true;
	}

	@Override
	public synchronized void resumeLoop() {
		paused = false;
		notifyAll();
	}

	@Override
	public synchronized void startLoop() {
		start();
	}
}
