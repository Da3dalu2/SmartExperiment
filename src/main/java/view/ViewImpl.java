package view;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.Timer;

import org.jfree.chart.JFreeChart;
import org.jfree.chart.fx.ChartViewer;
import org.jfree.data.xy.XYDataset;

import controller.DatasetGenerator;
import controller.DatasetGeneratorImpl;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.stage.Stage;
import model.ChartFactoryWrapper;
import model.ChartFactoryWrapperImpl;

public class ViewImpl implements View {

	private static final String TITLE = "Viewer";
	private static final String START = "Start";
    private static final String STOP = "Stop";
    private static final int FAST = 100;
    private static final int SLOW = FAST * 5;
	private boolean started;
    private static Stage stage;
	private Timer timer;
	
	private final ChartFactoryWrapper chartFactory;
	private final DatasetGenerator realtimeDataGenerator;
	
	public ViewImpl(final Stage stageToLoad) {
		stage = stageToLoad;
		chartFactory = new ChartFactoryWrapperImpl();
		realtimeDataGenerator= new DatasetGeneratorImpl();
		timer = new Timer(FAST, new ActionListener() {

            float[] newData = new float[1];

            @Override
            public void actionPerformed(ActionEvent e) {
                newData[0] = randomValue();
                dataset.advanceTime();
                dataset.appendData(newData);
            }
        });
	}

	/**
	 * {@inheritDoc}
	 */
	@Override
	public void launch() {
		XYDataset dataset = realtimeDataGenerator.getData();
        JFreeChart chart = chartFactory.createChart(dataset); 
        ChartViewer viewer = new ChartViewer(chart);
        setButtons();
        stage.setScene(new Scene(viewer)); 
        stage.setTitle(TITLE); 
        stage.setWidth(700);
        stage.setHeight(390);
        stage.show();
        timer.start();
	}
	
	private void setButtons() {
		final Button rn = new Button(STOP);
		rn.setOnAction((event) -> {
	         if(started) {
	        	started = false;
	        	timer.stop();
	            rn.setText(START);
	         } else {
	        	timer.start();
	        	started = true;
	            rn.setText(STOP);
	         }
	     });
		
        final ComboBox<String> combo = new ComboBox<>();
        combo.getItems().addAll("Fast", "Slow");
        combo.setOnAction((event) -> {
        	if ("Fast".equals(combo.getValue())) {
                timer.setDelay(FAST);
            } else {
                timer.setDelay(SLOW);
            }
	     });
	}
}
