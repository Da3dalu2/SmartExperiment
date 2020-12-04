package view;

import java.awt.EventQueue;

import controller.Controller;
import controller.ControllerImpl;

public class ViewImpl implements View {
	private static final String TITLE = "Viewer";

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void launch() {
		Controller controller = new ControllerImpl();
		 EventQueue.invokeLater(new Runnable() {
	            @Override
	            public void run() {
	                GraphsWindow demo = new GraphsWindow(TITLE, controller);
	                demo.pack();
	                demo.setVisible(true);
	                demo.start();
	            }
	     });
	}
}
