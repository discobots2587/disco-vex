	collector_flip();

	waitforBump(); 									              // robot waits for bumb
	drive_collect(63,127,900);	              		// drives and collects beach ball
	collect(127,1000);

	drive(127,-127,300);

	launch();

	drive(-127,127,300);

	lifter(gravityNot);

	drive_collect(63,127,900);	              		// drives and collects beach ball
	collect(127,1000);

	launch();


