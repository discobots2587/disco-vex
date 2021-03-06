collector_flip();
motor[collector] = 127;

waitforBump();					// wait for human to press bumper button on back of robot
lifter(medgoal);				// raise lift to aprox. 14 in. off ground
drive(127, 127, 1000);	// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
wait1Msec(300);					// wait 300 milleseconds
drive(-127,-30,400);
drive(-127, -127, 300);	// drive back in an arc to starting tile

waitforBump();					// wait for human to press bumper button on back of robot
wait1Msec(300);					// wait 300 milleseconds to stabalize the robot after raising lift
drive(63,63,400);				// drive forward to knock off beach ball closest to tile into goal zone
wait1Msec(500);					// wait 50 milleseconds
drive(-63,-63,200);			// drive back to tile (wait for repositioning)
lifter(gravityNot);			// lower lift so as to be able to go under 12 in. barrier

waitforBump();					// wait for human to press bumper button on back of robot
drive(127,127,1300);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(200);					// wait 200 milleseconds
lifter(highgoal);				// raise lift to score height
wait1Msec(500);
drive(30,30,500);				// drive
drive(63,63,500);				// drive
collect(-127, 3000);		// scoring preloaded bucky in silo
