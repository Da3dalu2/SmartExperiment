package controller;

import model.SystemStatus;
import view.View;

public interface Controller {

	MsgParser getMsgParser();

	void setView(View view);

	boolean askForEndConfirmation();

	void updateSystemStatus(SystemStatus status);

	void cleanClose();

	void init();
}
