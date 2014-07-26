collector_flip();
motor[collector] = 127;

waitforBump();					// wait for human to press bumper button on back of robot
lifter(medgoal);				// raise lift to aprox. 14 in. off ground
drive(100, 100, 1000);	// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
wait1Msec(300);					// wait 300 milleseconds
drive(-127,-30,400);
drive(-100, -100, 300);	// drive back in an arc to starting tile
lift(-127,300,1);

waitforBump();					// wait for human to press bumper button on back of robot
drive(127,127,900);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(500);					// wait 200 milleseconds
drive(127,127,500);


drive(-100,-100,320);
lifter(highgoal);				// raise lift to score height
wait1Msec(500);

drive(-100,100,300);

drive(30,30,500);				// drive
drive(63,63,700);				// drive
collect(-127, 700);		// scoring preloaded bucky in silo
drive(-63,-63,600);
collect(-127,2500);


/*collector_flip();

motor[collector] = 127;
drive(127,127,1750);

waitforBump();					// wait for human to press bumper button on back of robot
drive(127,127,1300);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(200);					// wait 200 milleseconds
lifter(highgoal);
wait1Msec(500);
drive(30,30,500);
drive(63,63,500);
collect(-127, 3000);		// scoring preloaded bucky in silo

drive(-63,-63,500);
lifter(gravityNot);
drive(-127,127,700);
wait10Msec(20);
drive(127,127,900);

waitforBump();					// wait for human to press bumper button on back of robot
lifter(medgoal);				// raise lift to aprox. 14 in. off ground
wait1Msec(300);					// wait 300 milleseconds to stabalize the robot after raising lift
drive(63,63,400);				// drive forward to knock off beach ball closest to tile into goal zone
wait1Msec(500);					// wait 50 milleseconds
drive(-63,-63,200);			// drive back to tile (wait for repositioning)

waitforBump();					// wait for human to press bumper button on back of robot
drive(127, 127, 1000);		// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
wait1Msec(300);					// wait 300 milleseconds
drive(-30,-127,400);
drive(-127, -127, 300);	// drive back in an arc to starting tile
lifter(gravityNot);			// lower lift so as to be able to go under 12 in. barrier

waitforBump();

drive(-127,-127,2000);

waitforBump();
drive_collect(127, 127, 200); 	// robot drives and collects the two buckyballs
collect(127,1000);							// continues collecting
drive_collect(-127,127,200);		// back to starting tile
motor[collector] = 127;

waitforBump();
drive(127,127,2000);


waitforBump();					// wait for human to press bumper button on back of robot
drive(127,127,1300);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(200);					// wait 200 milleseconds
lifter(highgoal);
wait1Msec(500);
drive(30,30,500);
drive(63,63,500);
collect(-127, 3000);		// scoring preloaded bucky in silo
*/
