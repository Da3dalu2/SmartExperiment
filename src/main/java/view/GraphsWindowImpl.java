package view;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Map;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.chart.ui.ApplicationFrame;

import model.CombinedChartFactory;
import model.ICombinedChartFactory;
import model.LabeledDataset;
import model.SensorMeasures;
import model.SystemStatus;

public class GraphsWindowImpl extends ApplicationFrame implements GraphsWindow {

	/**
	 *
	 */
	private static final long serialVersionUID = 1L;
	private final Timer timer;
	private final ICombinedChartFactory chartFactory;
	private final GraphsWindowLogics graphWindowLogics;
	final JTextField displayStatus;

	public GraphsWindowImpl(final String title, final View view) {
		super(title);
		graphWindowLogics = new GraphsWindowLogicsImpl(view);
		chartFactory = new CombinedChartFactory();

		final Map<SensorMeasures, LabeledDataset> datasets = graphWindowLogics
				.initDatasets();
		timer = graphWindowLogics.getTimer();

		final JFreeChart chart = chartFactory.createCombinedChart(datasets);

		this.add(new ChartPanel(chart), BorderLayout.CENTER);
		final JPanel panel = new JPanel(new FlowLayout());
		displayStatus = graphWindowLogics.setDisplayStatus(panel);
		this.add(panel, BorderLayout.SOUTH);

		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				view.deallocateResources();
				System.exit(0);
			}
		});
	}

	@Override
	public void start() {
		timer.start();
	}

	@Override
	public void updateStatusDisplay(SystemStatus status) {
		displayStatus.setEditable(true);
		displayStatus.setText(status.toString());
		displayStatus.setEditable(false);
	}
}