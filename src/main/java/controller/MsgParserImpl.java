package controller;

import java.util.Map;
import java.util.Random;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

import model.SensorMetrics;

public class MsgParserImpl implements MsgParser {

	private static final int COUNT = 30;
	Map<SensorMetrics, BlockingQueue<Float>> dataQueues;
    private static final Random random = new Random();
    private static final float MINMAX = 10;
    private static final Logger logger = Logger.getLogger("MsgParserImpl");
    private CommChannel commChannel;
	
	MsgParserImpl(CommChannel commChannel) {
		this.commChannel = commChannel; 
	}
	
	private float[] initData() {
        float[] a = new float[COUNT];
        for (int i = 0; i < a.length; i++) {
            a[i] = 0;
        }
        return a;
    }
	
	private float randomValue() {
	    return (float) (random.nextGaussian() * MINMAX / 3);
	}
	
	
	
	@Override
	public float[] getIncomingData(SensorMetrics metric) {
        float[] newData = new float[1];
		try {
			newData[0] = dataQueues.get(metric).poll(50, TimeUnit.MILLISECONDS);
		} catch (InterruptedException e) {
			logger.log(Level.SEVERE, e.toString());
		}
		if ( newData.length == 0) {
			newData[0] = 0;
		}
		return newData;
	}

	@Override
	public void parseIncomingData() {
		String msg = "";
		if ( commChannel.isMsgAvailable() ) {
			try {
				msg = commChannel.receiveMsg();
			} catch (InterruptedException e) {
				logger.log(Level.SEVERE, e.toString());
			}
		}
		if ( msg.contentEquals("start")) {
			
		}
	}
}
