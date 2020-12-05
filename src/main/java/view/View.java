package view;

import controller.MsgParser;
import model.SystemStatus;

/**
 * Interface describing the View of the application.
 */
public interface View {

	/**
	 * Loads the main scene.
	 */
	void launch();

	/**
	 * Update GUI components that show the current status of the system.
	 */
	void updateStatusDisplay(SystemStatus status);

	/**
	 * Get the parser used for updating graphs.
	 *
	 * @return the parser
	 */
	MsgParser getMsgParser();

	/**
	 * Ask the GUI to show a confirmation dialog for ending the experimentation.
	 *
	 * @return a boolean that tells if the user confirmed ending the experiment
	 */
	boolean requestExperimentationEndConfirmation();

}