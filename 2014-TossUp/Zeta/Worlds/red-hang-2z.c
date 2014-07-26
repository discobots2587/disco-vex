	collector_flip();

	waitforBump(); 									// robot waits for bumb
	drive_collect(127, 127, 300); 	// robot drives and collects the two buckyballs
	collectorSet(127);

	waitforBump();
	lifter(lowgoal);
	drive(-100,-100,1200);
	lift(-127,200);
	drive(-100,-100,1700);

	wait1Msec(500);

	lifter(highgoal);

	wait1Msec(500);

	drive(70,70,500);
	wait1Msec(200);

	drive(-70,70,680);

	wait1Msec(500);

	drive(80,80,700);

	collectorSet(0);
	collect(-127,5000);
