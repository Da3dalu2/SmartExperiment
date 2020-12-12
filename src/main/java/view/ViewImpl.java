package view;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

import controller.Controller;
import controller.MsgParser;
import model.SystemStatus;

public class ViewImpl implements View {

	private static final String TITLE = "Viewer";
	private final Controller controller;
	private GraphsWindowImpl graphsWindow;

	public ViewImpl(final Controller controller) {
		this.controller = controller;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void launch() {
		final View view = this;
		controller.init();
		graphsWindow = new GraphsWindowImpl(TITLE, view);
		graphsWindow.pack();
		graphsWindow.setVisible(true);
		graphsWindow.start();

	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void updateStatusDisplay(SystemStatus status) {
		graphsWindow.updateStatusDisplay(status);
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public boolean requestExperimentationEndConfirmation() {
		boolean confirmationReceived = false;
		if (JOptionPane.showConfirmDialog(new JFrame(),
				"Do you want to end the experiment?", "Experimentation end",
				JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION)
			confirmationReceived = true;
		else
			confirmationReceived = false;
		return confirmationReceived;
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public MsgParser getMsgParser() {
		return controller.getMsgParser();
	}

	@Override
	public void deallocateResources() {
		controller.cleanClose();
	}

}
