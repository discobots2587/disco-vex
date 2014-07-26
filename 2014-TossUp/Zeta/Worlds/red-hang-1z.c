	collector_flip();

	waitforBump(); 									// robot waits for bumb
	drive_collect(127, 127, 300); 	// robot drives and collects the two buckyballs
	collectorSet(127);
	wait1Msec(1500);
	drive(70,-70,300);
	wait1Msec(500);
	drive(-100,-100,1000);
	wait1Msec(500);
	drive(-100,100,380);
	wait1Msec(500);
	lifter(lowgoal);
	drive(-100,-100,1500);
	lift(-127,200);

	wait1Msec(500);
	drive(70,-70,400);
	wait1Msec(500);
	drive(-70,-70,1000);
