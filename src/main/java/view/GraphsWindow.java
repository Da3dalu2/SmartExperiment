package view;

import model.SystemStatus;

public interface GraphsWindow {

	/**
	 * Launches the GUI.
	 */
	void start();

	/**
	 * Allows updating the status of the system shown to the user with the current status.
	 *
	 * @param status the current status of the system
	 */
	void updateStatusDisplay(SystemStatus status);

}
