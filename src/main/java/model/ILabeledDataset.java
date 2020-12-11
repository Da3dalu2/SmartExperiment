package model;

import org.jfree.data.time.DynamicTimeSeriesCollection;

public interface ILabeledDataset {

	DynamicTimeSeriesCollection getDataset();
	
	String getLabel();
}
