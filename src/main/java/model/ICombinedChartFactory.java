package model;

import java.util.Map;

import org.jfree.chart.JFreeChart;

/**
 * Interface for generating charts with custom settings.
 */
public interface ICombinedChartFactory {

	/**
	 * Creates a chart.
	 *
	 * @param dataset  a map of labeled datasets associated with a measurement used to create the custom chart
	 *
	 * @return A chart of charts configured to plot real-time data.
	 */
	public JFreeChart createCombinedChart(Map<SensorMeasures, LabeledDataset> datasets);
}
