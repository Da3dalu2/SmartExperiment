package model;

import java.util.Map;

import org.jfree.chart.JFreeChart;

/**
 * Interface for generating charts with custom settings.
 */
public interface ChartFactoryWrapper {

	/**
     * Creates a chart.
     *
     * @param dataset  a dataset.
     *
     * @return A chart.
     */
	public JFreeChart createCombinedChart(Map<SensorMetrics, DynamicTimeSeriesCollectionWrapper> datasets);
}
