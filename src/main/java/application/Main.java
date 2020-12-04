package application;

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
		 View view = new ViewImpl();
		 view.launch();
	 }
}
