package controller;

import model.SensorMeasures;

public interface MsgParser {

	float[] getIncomingData(SensorMeasures metric);
	
	void parseIncomingData();

}
