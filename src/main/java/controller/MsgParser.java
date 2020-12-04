package controller;

import model.SensorMetrics;

public interface MsgParser {

	float[] getIncomingData(SensorMetrics metric);
	
	void parseIncomingData();

}
