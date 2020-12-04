package model;

import org.jfree.chart.JFreeChart;
import org.jfree.data.xy.XYDataset;

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
	public JFreeChart createChart(XYDataset dataset);
}
