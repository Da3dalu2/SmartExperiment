package view;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JPanel;
import javax.swing.Timer;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.time.DynamicTimeSeriesCollection;

import controller.Controller;
import controller.MsgParser;
import model.ChartFactoryWrapper;
import model.ChartFactoryWrapperImpl;
import model.DynamicTimeSeriesCollectionWrapper;
import model.SensorMetrics;

public class GraphsWindow extends org.jfree.chart.ui.ApplicationFrame {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
    private static final String START = "Start";
    private static final String STOP = "Stop";
    private static final float MINMAX = 10;
    private static final int COUNT = 2 * 60;
    private static final int FAST = 100;
    private static final int SLOW = FAST * 5;
    private static final Random random = new Random();
    private Timer timer;
    private final model.DatasetGenerator realtimeDataGenerator;
    private final ChartFactoryWrapper chartFactory;
    private Map<SensorMetrics, DynamicTimeSeriesCollectionWrapper> datasets;
    private final MsgParser parser;
    
    public GraphsWindow(final String title, final Controller controller) {
        super(title);
        datasets = new HashMap<>();
        realtimeDataGenerator = new model.DatasetGeneratorImpl();
        chartFactory = new ChartFactoryWrapperImpl();
        parser = controller.getMsgParser();
        initDatasets();
        JFreeChart chart = chartFactory.createCombinedChart(datasets);
        this.add(new ChartPanel(chart), BorderLayout.CENTER);
        setButtons();

        timer = new Timer(FAST, new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                for(Entry<SensorMetrics, DynamicTimeSeriesCollectionWrapper> metricDataset : datasets.entrySet()) {
                	DynamicTimeSeriesCollection dataset = metricDataset.getValue().getDataset();
                	dataset.advanceTime();
                	dataset.appendData(parser.getIncomingData(metricDataset.getKey()));
                }
            }
        });
    }
    
    private void initDatasets() {
    	DynamicTimeSeriesCollectionWrapper speedDataset = 
    			realtimeDataGenerator.createDataset(gaussianData(), "Object's speed", "m/s");
        datasets.put(SensorMetrics.Speed, speedDataset);

        DynamicTimeSeriesCollectionWrapper distanceDataset = 
        		realtimeDataGenerator.createDataset(gaussianData(), "Object's distance", "m");
        datasets.put(SensorMetrics.Distance, distanceDataset);

        DynamicTimeSeriesCollectionWrapper accelerationDataset = 
        		realtimeDataGenerator.createDataset(gaussianData(), "Object's acceleration", "m/s^2");
        datasets.put(SensorMetrics.Acceleration, accelerationDataset);
    }

    private float randomValue() {
        return (float) (random.nextGaussian() * MINMAX / 3);
    }

    private float[] gaussianData() {
        float[] a = new float[COUNT];
        for (int i = 0; i < a.length; i++) {
            a[i] = randomValue();
        }
        return a;
    }
	
    private void setButtons() {
		final JButton run = new JButton(STOP);
        run.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                String cmd = e.getActionCommand();
                if (STOP.equals(cmd)) {
                    timer.stop();
                    run.setText(START);
                } else {
                    timer.start();
                    run.setText(STOP);
                }
            }
        });

        final JComboBox<String> combo = new JComboBox<>();
        combo.addItem("Fast");
        combo.addItem("Slow");
        combo.addActionListener(new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                if ("Fast".equals(combo.getSelectedItem())) {
                    timer.setDelay(FAST);
                } else {
                    timer.setDelay(SLOW);
                }
            }
        });
        
        JPanel btnPanel = new JPanel(new FlowLayout());
        btnPanel.add(run);
        btnPanel.add(combo);
        this.add(btnPanel, BorderLayout.SOUTH);
	}

    public void start() {
        timer.start();
    }
}