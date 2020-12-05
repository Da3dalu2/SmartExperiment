package controller;

public interface MsgParserLoop {
	
	    /**
	     * Starts the parsing loop.
	     */
	    void startLoop();

	    /**
	     * Temporarily stops the loop until resume() is called.
	     */
	    void pauseLoop();

	    /**
	     * Makes the loop restart if it was previously paused.
	     */
	    void resumeLoop();
}
