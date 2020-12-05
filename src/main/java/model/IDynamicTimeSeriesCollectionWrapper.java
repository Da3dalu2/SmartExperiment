package model;

import org.jfree.data.time.DynamicTimeSeriesCollection;

public interface IDynamicTimeSeriesCollectionWrapper {

	DynamicTimeSeriesCollection getDataset();
	
	String getLabel();
}
