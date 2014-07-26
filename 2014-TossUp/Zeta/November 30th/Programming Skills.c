collector_flip();

waitforBump(); 									// robot waits for bumb
	drive_collect(127, 127, 300); 	// robot drives and collects the two buckyballs
	collect(127,1000);							// continues collecting
	drive_collect(-63,127,200);			// back to starting tile
	lift_collect(127,127,1100,1);		// raise lift... wait for reposition...



waitforBump();
lift(-127, -127, 500);
drive(-127, -127, 200);
drive_lift(127, 127, 500, 1);
drive(-127, -127, 200);

waitforBump();					// wait for human to press bumper button on back of robot
drive(127, 127, 900);		// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
wait1Msec(300);					// wait 300 milleseconds
drive(-127, -25, 600);	// drive back in an arc to starting tile
lift(-127,400,1);				// lower lift so as to be able to go under 12 in. barrier

waitforBump();					// wait for human to press bumper button on back of robot
drive(127,127,1200);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(200);					// wait 200 milleseconds
lift(127, 1150, 1);			// raise lift to score height
drive(-50,-50,200);
wait1Msec(750);					// wait 200 milleseconds
drive(50,50,1500);
collect(-127, 2000);		// scoring preloaded bucky in silo

drive(-127, -127, 100);
drive_drive_lift( -127, 127, -127, 300, 1);
drive(127, 127, 1200);

waitforBump();
drive( 127, 127, 300);
drive( -127, -127, 300);
waitforBump();
drive(127, 127, 1000);
drive(-127, 127, 200);
drive(127, 127, 400);
drive(-90, -127, 200);
drive(127, 127, 500);
