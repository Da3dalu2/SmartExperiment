package view;

import model.DynamicTimeSeriesCollectionWrapper;

public interface DatasetGenerator {

	DynamicTimeSeriesCollectionWrapper createDataset(float[] values, String seriesName, String ylabel);
}
