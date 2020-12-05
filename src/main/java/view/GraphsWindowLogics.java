package view;

import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import model.DynamicTimeSeriesCollectionWrapper;
import model.SensorMeasures;

public interface GraphsWindowLogics {

	Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> initDatasets();

	void setButtons(JPanel panel);

	JTextField setDisplayStatus(JPanel panel);

	Timer getTimer();

}