package model;

import org.jfree.data.time.DynamicTimeSeriesCollection;
import org.jfree.data.time.Second;

public class DatasetGeneratorImpl implements DatasetGenerator {

	private static final int COUNT = 2 * 60;
	
	@Override
	public DynamicTimeSeriesCollectionWrapper createDataset(float[] values, String seriesName, String ylabel) {
		 final DynamicTimeSeriesCollection dataset =
				 new DynamicTimeSeriesCollection(1, COUNT, new Second());
		  dataset.setTimeBase(new Second());
	      dataset.addSeries(values, 0, seriesName);
	      final DynamicTimeSeriesCollectionWrapper labeledDataset = new DynamicTimeSeriesCollectionWrapper(dataset, ylabel);
	      return labeledDataset;
	}
}