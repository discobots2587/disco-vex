collector_flip();
waitforBump();
drive(127, 127, 1000);	// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
wait1Msec(300);					// wait 300 milleseconds
//drive(-30,-127,400);
waitforBump();
drive(127,127,1300);		// drive forward untill far enough under barrier so that we can raise list
wait1Msec(200);					// wait 200 milleseconds

lifter(highgoal);


drive(30,30,500);				// drive
drive(63,63,500);				// drive
collect(-127, 3000);		// scoring preloaded bucky in silo
