package view;

import model.LabeledDataset;

public interface DatasetGenerator {

	LabeledDataset createDataset(float[] values, String seriesName, String ylabel);
}
