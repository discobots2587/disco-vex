bool auton_flag = false;
bool auton_flag2 = false;

collector_flip();
collectorSet(127);       // start spinning collector at max speed
SensorValue[wing] = 1;
drive(40,40,2550);
wait1Msec(500);          // pause
SensorValue[wing] = 0;
drive(-70,-100,1000);   // drive back to starting tile
collectorSet(0);

while(auton_flag2 == false) {
	if(SensorValue[touchL] == 1 || SensorValue[touchR] == 1 || SensorValue[touch3] == 1) {
		collectorSet(127);
		wait1Msec(500);
		auton_flag2 = true;
	}
}

while(auton_flag == false && auton_flag2 == true) {            // loop for two auton cases

	if(SensorValue[touchL] == 1) {        // case 1: scores in close goal

		collectorSet(127);
		drive(127,90,1150);
		wait1Msec(500);
		lifter(highgoal);
		drive(50,50,200);
		drive(100,100,500);
		drive(0,50,200);
		collectorSet(0);
		collect(-127,500);
		drive_collect(50,-127,500);
		collect(-127,10000);

		auton_flag = true;

		}

	else if(SensorValue[touchR] == 1) {   // case 2: scores in far goal

		//collectorSet(127);

		//lifter(medgoal);				// raise lift to aprox. 14 in. off ground
		//wait1Msec(300);					// wait 300 milleseconds to stabalize the robot after raising lift
		//drive(63,63,500);				// drive forward to knock off beach ball closest to tile into goal zone
		//wait1Msec(200);					// wait 50 milleseconds
		//drive(-63,-63,300);			// drive back to tile (wait for repositioning)
		//lift(-127,300);

		//waitforBumpR();
		//drive(100,100,225);
		//wait1Msec(500);
		//drive(-70,70,300);
		//wait1Msec(300);
		//drive(90,90,1500);

		collectorSet(127);

		lifter(medgoal);				// raise lift to aprox. 14 in. off ground
		wait1Msec(300);					// wait 300 milleseconds to stabalize the robot after raising lift
		drive(63,63,500);				// drive forward to knock off beach ball closest to tile into goal zone
		wait1Msec(200);					// wait 50 milleseconds
		drive(-63,-63,300);			// drive back to tile (wait for repositioning)

		waitforAnyBump();
		drive(127, 127, 1000);	// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
		wait1Msec(300);					// wait 300 milleseconds
		drive(-100,-100,600);
		lift(-127,200);
		drive(70,-70,300);
		wait1Msec(500);
		drive(127, 127, 900);	// drive back in an arc to starting tile
		drive(-70,70,500);
		drive(100,100,500);



		auton_flag = true;
	}

	else if(SensorValue[touch3] == 1) {   // case 3: knocks beachballs

		lifter(medgoal);				// raise lift to aprox. 14 in. off ground
		wait1Msec(300);					// wait 300 milleseconds to stabalize the robot after raising lift
		drive(63,63,500);				// drive forward to knock off beach ball closest to tile into goal zone
		wait1Msec(200);					// wait 50 milleseconds
		drive(-63,-63,300);			// drive back to tile (wait for repositioning)
		lift(-127,300);

		waitforBump();					// wait for human to press bumper button on back of robot
		drive(127, 127, 1000);	// drive forward to knock the beach ball that is farther from the starting tile into the goal zone
		wait1Msec(300);					// wait 300 milleseconds
		drive(-100,-100,400);
		lift(-127,300);			// lower lift so as to be able to go under 12 in. barrier

		drive(70,-70,500);
		drive(-127,-127,500);

		auton_flag = true;
	}
} // end while
