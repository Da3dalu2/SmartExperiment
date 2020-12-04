package model;

import java.util.Map;
import java.util.Map.Entry;
import java.util.Optional;

import org.jfree.chart.JFreeChart;
import org.jfree.chart.axis.AxisLocation;
import org.jfree.chart.axis.DateAxis;
import org.jfree.chart.axis.NumberAxis;
import org.jfree.chart.axis.ValueAxis;
import org.jfree.chart.plot.CombinedDomainXYPlot;
import org.jfree.chart.plot.PlotOrientation;
import org.jfree.chart.plot.XYPlot;
import org.jfree.chart.renderer.xy.XYLineAndShapeRenderer;
import org.jfree.data.xy.XYDataset;

public class ChartFactoryWrapperImpl implements ChartFactoryWrapper {
    
    private XYPlot createPlot(XYDataset dataset, String ylabel) {
        NumberAxis valueAxis = new NumberAxis(ylabel);
        valueAxis.setAutoRangeIncludesZero(false);
        XYLineAndShapeRenderer renderer = new XYLineAndShapeRenderer(true, false);
        XYPlot plot = new XYPlot(dataset, null, valueAxis, renderer);

		return plot;
    }
    
    private enum PlotNumber {
    	firstPlot,
    	secondPlot,
    	thirdPlot,
    	forthPlot,
    	noFreeSlots
    }
    
    private Optional<AxisLocation> placePlot(PlotNumber plotNumber) {
    	switch(plotNumber) {
			case firstPlot:
				plotNumber = PlotNumber.secondPlot;
				return Optional.of(AxisLocation.BOTTOM_OR_LEFT);
			case secondPlot:
				plotNumber = PlotNumber.thirdPlot;
				return Optional.of(AxisLocation.BOTTOM_OR_RIGHT);
			case thirdPlot:
				plotNumber = PlotNumber.forthPlot;
				return Optional.of(AxisLocation.TOP_OR_LEFT);
			case forthPlot:
				plotNumber = PlotNumber.noFreeSlots;
				return Optional.of(AxisLocation.TOP_OR_LEFT);
			default:
				return Optional.empty();
    	}    	
    }
    
    /**
	 * {@inheritDoc}
	 */
	@Override
	public JFreeChart createCombinedChart(Map<SensorMetrics, DynamicTimeSeriesCollectionWrapper> datasets) {
		ValueAxis timeAxis = new DateAxis("hh:mm:ss");
        timeAxis.setLowerMargin(0.02);
        timeAxis.setUpperMargin(0.02);
    	final CombinedDomainXYPlot plot = new CombinedDomainXYPlot(timeAxis);
    	PlotNumber plotNumber = PlotNumber.firstPlot;
    	for(Entry<SensorMetrics, DynamicTimeSeriesCollectionWrapper> labeledDataset : datasets.entrySet()) {
    		XYPlot subplot = createPlot(labeledDataset.getValue().getDataset(), labeledDataset.getValue().getLabel());
			subplot.setRangeAxisLocation(placePlot(plotNumber).orElseThrow());
    		plot.add(subplot, 1);
    	}
    	plot.setGap(10.0);
    	plot.setOrientation(PlotOrientation.VERTICAL);
		return new JFreeChart("Experiment's data", JFreeChart.DEFAULT_TITLE_FONT, plot, true);
	}
}