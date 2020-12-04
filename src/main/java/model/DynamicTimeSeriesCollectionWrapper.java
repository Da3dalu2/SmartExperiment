package model;

import org.jfree.data.time.DynamicTimeSeriesCollection;
import javafx.util.Pair;

public class DynamicTimeSeriesCollectionWrapper {

	private Pair<DynamicTimeSeriesCollection, String> pair;
	
	public DynamicTimeSeriesCollectionWrapper(DynamicTimeSeriesCollection timeSeries, String ylabel) {
		pair = new Pair<>(timeSeries, ylabel);
	}
	
	public DynamicTimeSeriesCollection getDataset() {
		return pair.getKey();
	}
	
	public String getLabel() {
		return pair.getValue();
	}

}
