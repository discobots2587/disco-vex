	//collector_flip();

	//waitforBump(); 									// robot waits for bumb
	//drive_collect(127, 127, 200); 	// robot drives and collects the two buckyballs
	//collect(127,1000);							// continues collecting
	//drive_collect(-127,127,200);		// back to starting tile
	//motor[collector] = 127;
	//lifter(medgoal);								// raise lift... wait for reposition...

	//waitforBump(); 									// we turn the robot
	//collect(-127, 1500); 						// the robot spits out the bucky balls... waits for reposition...

	//waitforBump();									// we turn robot
	//lift(-127,500,1);								// lowers lift
	//wait1Msec(250);									// wait 500 milleseconds to stabalize
	//drive_collect(127,127,500);			// drives and collects beach ball
	//collect(127,1000);							// continues collecting...
	//drive_collect(127,127,500);
	//drive_collect(30,127,1000);
	//collect(127,500);
	//drive(-127,-127,800);

	//lifter(lowgoal);								// raise lift a tad
	//motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 20; // sets lift motors to power 20 to hold up lift
	//drive(127,-127,400);																								// turns 90 degress left
	//wait1Msec(300);																											// wait 300 milleseconds
	//motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;	// sets lift motors to 0
	//lift_collect(-127,-127,150,1);																			// lowers lift and spits out big ball (which pushes 3 buckies of bump)
	//drive_collect(127,-127,200);																				// drives forward
	//collect(-127,2000);																									// spits out

	collector_flip();
	waitforBump();
	drive_collect(63,63,3000);
	wait1Msec(200);
	drive(-63,-63,3000);
	wait1Msec(300);
	lifter(medgoal);
	waitforBump();
	drive(63,63,3500);
	spin(-1,3000);

