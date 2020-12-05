package application;

import controller.Controller;
import controller.ControllerImpl;
import model.ExperimentationSystem;
import model.ExperimentationSystemImpl;
import view.View;
import view.ViewImpl;

/**
 * This class represent the Main class of the Viewer.
 */
public final class Main {

	/**
	 * @param args unused
	 */
	 public static void main(final String[] args) {
		 ExperimentationSystem system = new ExperimentationSystemImpl();
		 Controller controller = new ControllerImpl(system);
		 View view = new ViewImpl(controller);
		 controller.setView(view);
		 view.launch();
	 }
}