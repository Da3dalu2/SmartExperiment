package view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;

import org.jfree.data.time.DynamicTimeSeriesCollection;

import controller.MsgParser;
import model.LabeledDataset;
import model.SensorMeasures;
import model.SystemStatus;

public class GraphsWindowLogicsImpl implements GraphsWindowLogics {

	private static final float MINMAX = 10;
	private static final int COUNT = 2 * 60;
	private static final int FAST = 100;
	private static final SystemStatus BEGIN_STATUS = SystemStatus.Ready;

	private static final Logger logger = Logger
			.getLogger("GraphsWindowLogicsImpl");

	private static final Random random = new Random();
	private final MsgParser parser;
	private final Map<SensorMeasures, LabeledDataset> datasets;
	private Timer timer;

	public final DatasetGenerator realtimeDataGenerator;

	public GraphsWindowLogicsImpl(final View view) {
		datasets = new HashMap<>();
		realtimeDataGenerator = new DatasetGeneratorImpl();
		parser = view.getMsgParser();
		timer = createTimer();
	}

	@Override
	public Map<SensorMeasures, LabeledDataset> initDatasets() {
		final LabeledDataset speedDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's speed", "m/s");
		datasets.put(SensorMeasures.Speed, speedDataset);

		final LabeledDataset distanceDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's distance", "m");
		datasets.put(SensorMeasures.Distance, distanceDataset);

		final LabeledDataset accelerationDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's acceleration",
						"m/s^2");
		datasets.put(SensorMeasures.Acceleration, accelerationDataset);
		return datasets;
	}

	@Override
	public JTextField setDisplayStatus(JPanel panel) {
		final JTextField displayStatus = new JTextField(
				" " + BEGIN_STATUS.toString() + " ");
		displayStatus.setEditable(false);
		panel.add(displayStatus);
		return displayStatus;
	}

	@Override
	public Timer getTimer() {
		return timer;
	}

	private Timer createTimer() {
		timer = new Timer(FAST, new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				for (final Entry<SensorMeasures, LabeledDataset> metricDataset : datasets
						.entrySet()) {
					logger.log(Level.INFO, "[Timer]: getting data");
					final DynamicTimeSeriesCollection dataset = metricDataset
							.getValue().getDataset();
					dataset.advanceTime();
					dataset.appendData(
							parser.getIncomingData(metricDataset.getKey()));
				}
			}
		});
		return timer;
	}

	/**
	 * Utility to plot random data used to initialize the graphs.
	 * @return
	 */
	private float[] gaussianData() {
		final float[] a = new float[COUNT];
		for (int i = 0; i < a.length; i++)
			a[i] = randomValue();
		return a;
	}

	private float randomValue() {
		return (float) (random.nextGaussian() * MINMAX / 3);
	}
}
