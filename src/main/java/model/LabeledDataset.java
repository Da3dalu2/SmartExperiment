package model;

import org.jfree.data.time.DynamicTimeSeriesCollection;
import javafx.util.Pair;

public class LabeledDataset implements ILabeledDataset {

	private Pair<DynamicTimeSeriesCollection, String> pair;
	
	public LabeledDataset(DynamicTimeSeriesCollection timeSeries, String ylabel) {
		pair = new Pair<>(timeSeries, ylabel);
	}
	
	@Override
	public DynamicTimeSeriesCollection getDataset() {
		return pair.getKey();
	}
	
	@Override
	public String getLabel() {
		return pair.getValue();
	}

}
