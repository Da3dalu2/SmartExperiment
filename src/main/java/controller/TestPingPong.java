package controller;

import model.SensorMeasures;

/**
 * Testing simple message passing.
 * 
 * To be used with an Arduino connected via Serial Port
 * running modulo-lab-2.2/pingpong.ino
 * 
 * @author aricci
 *
 */
public class TestPingPong {

	public static void main(String[] args) throws Exception {
		
		CommChannel channel = new SerialCommChannel("/dev/ttyACM0", 9600);	
		// CommChannel channel = new SerialCommChannel("/dev/cu.usbmodem1411",9600);	
		// CommChannel channel = new SerialCommChannel("/dev/cu.isi00-DevB",9600);	

		
		
		/* attesa necessaria per fare in modo che Arduino completi il reboot */
		System.out.println("Waiting Arduino for rebooting...");		
		Thread.sleep(4000);
		System.out.println("Ready.");		

		while (true){
			System.out.println("Sending ping");
			channel.sendMsg("ping");
			String msg = channel.receiveMsg();
			System.out.println("Received: "+msg);
			String[] tokens = msg.split("[\\[\\];]+");
			for (String s : tokens) 
				System.out.println(s);

			if (tokens.length != SensorMeasures.values().length) {
				System.out.println(tokens.length);
				System.out.println(SensorMeasures.values().length);
			}
			Thread.sleep(500);
		}
	}

}
