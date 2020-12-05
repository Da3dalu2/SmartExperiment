package view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import org.jfree.data.time.DynamicTimeSeriesCollection;

import controller.MsgParser;
import model.DynamicTimeSeriesCollectionWrapper;
import model.SensorMeasures;
import model.SystemStatus;

public class GraphsWindowLogicsImpl implements GraphsWindowLogics {

	// private static final String START = "Start";
	// private static final String STOP = "Stop";
	private static final float MINMAX = 10;
	private static final int COUNT = 2 * 60;
	private static final int FAST = 100;
	// private static final int SLOW = FAST * 5;
	private static final SystemStatus BEGIN_STATUS = SystemStatus.Ready;
	private static final Random random = new Random();
	private final MsgParser parser;
	private Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> datasets;
	private Timer timer;

	public final DatasetGenerator realtimeDataGenerator;

	public GraphsWindowLogicsImpl(final View view) {
		realtimeDataGenerator = new DatasetGeneratorImpl();
		parser = view.getMsgParser();
		timer = createTimer();
	}

	@Override
	public Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> initDatasets() {
		final DynamicTimeSeriesCollectionWrapper speedDataset = realtimeDataGenerator.createDataset(gaussianData(),
				"Object's speed", "m/s");
		datasets.put(SensorMeasures.Speed, speedDataset);

		final DynamicTimeSeriesCollectionWrapper distanceDataset = realtimeDataGenerator.createDataset(gaussianData(),
				"Object's distance", "m");
		datasets.put(SensorMeasures.Distance, distanceDataset);

		final DynamicTimeSeriesCollectionWrapper accelerationDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's acceleration", "m/s^2");
		datasets.put(SensorMeasures.Acceleration, accelerationDataset);
		return datasets;
	}

	private float randomValue() {
		return (float) (random.nextGaussian() * MINMAX / 3);
	}

	private float[] gaussianData() {
		final float[] a = new float[COUNT];
		for (int i = 0; i < a.length; i++) {
			a[i] = randomValue();
		}
		return a;
	}

	@Override
	public void setButtons(JPanel panel) {
		/*
		 * final JButton run = new JButton(STOP); run.addActionListener(new
		 * ActionListener() {
		 *
		 * @Override public void actionPerformed(ActionEvent e) { final String cmd =
		 * e.getActionCommand(); if (STOP.equals(cmd)) { timer.stop();
		 * run.setText(START); } else { timer.start(); run.setText(STOP); } } });
		 *
		 * final JComboBox<String> combo = new JComboBox<>(); combo.addItem("Fast");
		 * combo.addItem("Slow"); combo.addActionListener(new ActionListener() {
		 *
		 * @Override public void actionPerformed(ActionEvent e) { if
		 * ("Fast".equals(combo.getSelectedItem())) { timer.setDelay(FAST); } else {
		 * timer.setDelay(SLOW); } } });
		 *
		 * panel.add(run); panel.add(combo);
		 */
	}

	@Override
	public JTextField setDisplayStatus(JPanel panel) {
		final JTextField displayStatus = new JTextField(BEGIN_STATUS.toString());
		panel.add(displayStatus);
		return displayStatus;
	}

	private Timer createTimer() {
		timer = new Timer(FAST, new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				for (final Entry<SensorMeasures, DynamicTimeSeriesCollectionWrapper> metricDataset : datasets
						.entrySet()) {
					final DynamicTimeSeriesCollection dataset = metricDataset.getValue().getDataset();
					dataset.advanceTime();
					dataset.appendData(parser.getIncomingData(metricDataset.getKey()));
				}
			}
		});
		return timer;
	}

	@Override
	public Timer getTimer() {
		return timer;
	}

}
