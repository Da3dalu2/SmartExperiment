package model;

public interface DatasetGenerator {

	DynamicTimeSeriesCollectionWrapper createDataset(float[] values, String seriesName, String ylabel);
}
