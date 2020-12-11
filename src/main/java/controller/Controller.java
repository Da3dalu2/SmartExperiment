package controller;

import model.SystemStatus;
import view.View;

public interface Controller {

	void setView(View view);

	void init();

	MsgParser getMsgParser();

	void updateSystemStatus(SystemStatus status);

	boolean askForEndConfirmation();

	void cleanClose();

}
