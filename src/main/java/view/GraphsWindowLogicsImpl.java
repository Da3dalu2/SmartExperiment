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
import model.DynamicTimeSeriesCollectionWrapper;
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
	private final Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> datasets;
	private Timer timer;

	public final DatasetGenerator realtimeDataGenerator;

	public GraphsWindowLogicsImpl(final View view) {
		datasets = new HashMap<>();
		realtimeDataGenerator = new DatasetGeneratorImpl();
		parser = view.getMsgParser();
		timer = createTimer();
	}

	@Override
	public Map<SensorMeasures, DynamicTimeSeriesCollectionWrapper> initDatasets() {
		final DynamicTimeSeriesCollectionWrapper speedDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's speed", "m/s");
		datasets.put(SensorMeasures.Speed, speedDataset);

		final DynamicTimeSeriesCollectionWrapper distanceDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's distance", "m");
		datasets.put(SensorMeasures.Distance, distanceDataset);

		final DynamicTimeSeriesCollectionWrapper accelerationDataset = realtimeDataGenerator
				.createDataset(gaussianData(), "Object's acceleration",
						"m/s^2");
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
	public JTextField setDisplayStatus(JPanel panel) {
		final JTextField displayStatus = new JTextField(
				" " + BEGIN_STATUS.toString() + " ");
		displayStatus.setEditable(false);
		panel.add(displayStatus);
		return displayStatus;
	}

	private Timer createTimer() {
		timer = new Timer(FAST, new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				for (final Entry<SensorMeasures, DynamicTimeSeriesCollectionWrapper> metricDataset : datasets
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

	@Override
	public Timer getTimer() {
		return timer;
	}

}
