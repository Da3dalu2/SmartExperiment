package view;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;

import model.ChartFactoryWrapper;
import model.ChartFactoryWrapperImpl;
import model.DynamicTimeSeriesCollectionWrapper;
import model.SensorMeasures;
import model.SystemStatus;

public class GraphsWindowImpl extends org.jfree.chart.ui.ApplicationFrame implements GraphsWindow {

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	private final Timer timer;
	private final ChartFactoryWrapper chartFactory;
	private final GraphsWindowLogics graphWindowLogics;
	final JTextField displayStatus;

	public GraphsWindowImpl(final String title, final View view) {
		super(title);
		graphWindowLogics = new GraphsWindowLogicsImpl(view);
		chartFactory = new ChartFactoryWrapperImpl();
		final Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> datasets = graphWindowLogics.initDatasets();
		timer = graphWindowLogics.getTimer();

		final JFreeChart chart = chartFactory.createCombinedChart(datasets);
		this.add(new ChartPanel(chart), BorderLayout.CENTER);
		final JPanel panel = new JPanel(new FlowLayout());

		// final graphWindowLogics.setButtons(panel);
		displayStatus = graphWindowLogics.setDisplayStatus(panel);

		this.add(panel, BorderLayout.SOUTH);
	}

	@Override
	public void start() {
		timer.start();
	}

	@Override
	public void updateStatusDisplay(SystemStatus status) {
		displayStatus.setText(status.toString());
	}
}