package view;

import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import model.LabeledDataset;
import model.SensorMeasures;

/**
 * Holds all the logic needed to create GUI components as the
 * text field that shows the current status to the user,
 * the graphs that show sensor data and the timer that periodically
 * gathers updated data to be plotted on the charts.
 *
 */
public interface GraphsWindowLogics {

	Map<SensorMeasures, LabeledDataset> initDatasets();

	JTextField setDisplayStatus(JPanel panel);

	Timer getTimer();

}