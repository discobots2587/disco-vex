// Drive //

if(vexRT[Ch2] > 100) motor[driveR1] = motor[driveR2] = 100;
else if(vexRT[Ch2] < -100) motor[driveR1]  = motor[driveR2] = -100;
else motor[driveR1] = motor[driveR2] = vexRT[Ch2];

if(vexRT[Ch3] > 100) motor[driveL1] = motor[driveL2] = 100;
else if(vexRT[Ch3] < -100) motor[driveL1] = motor[driveL2] = -100;
else motor[driveL1] = motor[driveL2] = vexRT[Ch3];

// Lift //

if(vexRT[Btn8U] == 1) 		 goal_lock = 2;  //sets to high lock
else if(vexRT[Btn8L] == 1) goal_lock = 1;  //sets to medium goal
else if(vexRT[Btn8R] == 1) goal_lock = 1;  // Same as ^
else if(vexRT[Btn8D] == 1) goal_lock = -1; // sets to low lock

if(goal_lock == 2) lock(highest);  //8U
else if(goal_lock == 1) lock(med); //8L OR 8R
else if(goal_lock == 1) lock(med); //8L OR 8R
else if(goal_lock == -1) lock(low);//8D

switch(vexRT[Btn6D] - vexRT[Btn6U])	{
case 1:
	if(SensorValue[touchL] == 0){
		motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = -127;
		goal_lock = 0;
	}
	else {
		motor[liftL1] = motor[liftL2] = motor[liftR1] =  motor[liftR2] = 0;
	}
	break;
case -1:
	motor[liftL1] = motor[liftL2] = motor[liftR1] =  motor[liftR2] = 127;
	goal_lock = 0;
	break;

case 0:
	if(goal_lock == 0){
		motor[liftL1] = motor[liftL2] = motor[liftR1] =  motor[liftR2] = 0;
	}
	break;
}

// Collector //

if(vexRT[Btn5U] == 1)	motor(collectorL) = motor(collectorR) = 127;
else if(vexRT[Btn5D] == 1) motor(collectorL) = motor(collectorR) = -127;
else motor(collectorL) = motor(collectorR) = 0;
