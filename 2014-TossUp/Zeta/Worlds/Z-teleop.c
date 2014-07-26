// *********************************************** // Drive  // ****************************************************** //

if(vexRT[Ch2] > 100) {
motor[driveR1] = motor[driveR2] = 100;}

else if(vexRT[Ch2] < -100) {
motor[driveR1]  = motor[driveR2] = -100;}

else{motor[driveR1] = motor[driveR2] = vexRT[Ch2];}

if(vexRT[Ch3] > 100) {
	motor[driveL1]  = motor[driveL2] = 100;}

else if(vexRT[Ch3] < -100) {
motor[driveL1]  = motor[driveL2] = -100;}

else{motor[driveL1] = motor[driveL2] = vexRT[Ch3];}

//motor[driveL1] = motor[driveL2] = vexRT[Ch3];
//motor[driveR1] = motor[driveR2] = vexRT[Ch2];


//if(abs(vexRT[Ch3]) > threshold)  {         // If the left joystick is greater than or less than the threshold:

//	if(vexRT[Ch3] > 100)
//		motor[driveL1]  = motor[driveL2] = 100;

//	if(vexRT[Ch3] < -100)
//		motor[driveL1]  = motor[driveL2] = -100;
//	else{motor[driveL1]  = motor[driveL2] = vexRT[Ch3];}

//}
//else {motor[driveL1]  = motor[driveL2] = 0;}

//if(abs(vexRT[Ch2]) > threshold) {        // If the right joystick is greater than or less than the threshold:
//	if(vexRT[Ch2] > 100)
//		motor[driveL1]  = motor[driveL2] = 100;
//	if(vexRT[Ch2] < -100)
//		motor[driveL1]  = motor[driveL2] = -100;
//	else{motor[driveL1]  = motor[driveL2] = vexRT[Ch2];}
//}
//else {motor[driveR1]  = motor[driveR2] = 0;}

//if(vexRT[Ch3] > 100) {
//	motor[driveL1]  = motor[driveL2] = 100;}

//else if(vexRT[Ch3] < -100) {
//motor[driveL1]  = motor[driveL2] = -100;}

//else{motor[driveL1] = motor[driveL2] = vexRT[Ch3];}



//if(vexRT[Ch2] > 100) {
//motor[driveR1] = motor[driveR2] = 100;}

//else if(vexRT[Ch2] < -100) {
//motor[driveR1]  = motor[driveR2] = -100;}

//else{motor[driveR1] = motor[driveR2] = vexRT[Ch2];}


//*********************************************** // Lift // ****************************************************** //


if(vexRT[Btn8L] == 1)//auto button close loop
{
	goal_lock = 1;   //sets to medium goal
}
else if(vexRT[Btn8U] == 1) {
	goal_lock = 2;  //sets to high lock
}
else if(vexRT[Btn8D] == 1) {// descore/ score on low goal...
	goal_lock = -1;
}
else if(vexRT[Btn8R] == 1) {//same as 7D...
	goal_lock = 1;
}

if(goal_lock == -1)//if 7L is pressed...
	lock(low); //brings to low lock point
else if(goal_lock == 1)//if  7U is pressed...
	lock(med);
else if (goal_lock == 1)
	lock(med);
else if(goal_lock == 2)
	lock(highest);

switch(vexRT[Btn6D] - vexRT[Btn6U]){
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
// *********************************************** // Collector // ****************************************************** //
if(vexRT[Btn5U] == 1) {
	motor(collectorL) = motor(collectorR) = 127;
}
else if(vexRT[Btn5D] == 1) {
	motor(collectorL) = motor(collectorR) = -127;
}
else {
	motor(collectorL) = motor(collectorR) = 0;
}

// *********************************************** // Pneumatics // ****************************************************** //
//bool counter1 = true;
//bool counter2 = true;

//	if(vexRT[btn7R] == 1 && counter1 == true)		{
//		SensorValue[pLock] = 1;
//		wait1Msec(1000);
//		counter1 = false;
//}
//	else if(vexRT[btn7R] == 1 && counter1 == false)		{
//		SensorValue[pLock] = 0;
//		wait1Msec(1000);
//		counter1 = true;
//}


//	if(vexRT[btn7L] == 1 && counter2 == true)		{
//		SensorValue[wing] = 1;
//		wait1Msec(1000);
//		counter2 = false;
//}
//	else if(vexRT[btn7L] == 1 && counter2 == false)		{
//		SensorValue[wing] = 0;
//		wait1Msec(1000);
//		counter2 = true;
//}

//if(vexRT[Btn7R] == 1) {
//	SensorValue[wing] = 1;
//}

//else if (vexRT[Btn7L] == 1) {
//	SensorValue[wing] = 0;
//}

if(vexRT[Btn7U] == 1) {
	SensorValue[Catapult] = 1;
}
else if(vexRT[Btn7D] == 1) {
	SensorValue[Catapult] = 0;
}

//while(time1[T4] > 75000 && vexRT[Btn7R] == 1 ){
//	SensorValue[pLock] = 1;
//}

//if (vexRT[Btn7L] == 1) {
//	SensorValue[pLock] = 0;
//}

//if(SensorValue[pot] > 900 && vexRT[Btn6U] != 1 && vexRT[Btn6D] != 1) {
//		motor[liftL1] = motor[liftL2] = motor[liftR1] =  motor[liftR2] = 20;
//}

if(vexRT[Btn7R] == 1) {
	if( ! buttonPressed )		{
		buttonToggleState = 1 - buttonToggleState;  // change the toggle state
		buttonPressed = 1;  // Note the button is pressed
	}
}
else	{
	buttonPressed = 0;       // the button is not pressed
}

if( buttonToggleState )
	SensorValue[pLock] = 1;
else
	SensorValue[pLock] = 0;

//////////////////////////////////


if(vexRT[Btn7L] == 1) {
	if( ! buttonPressed2 )		{
		buttonToggleState2 = 1 - buttonToggleState2;  // change the toggle state
		buttonPressed2 = 1;  // Note the button is pressed
	}
}
else	{
	buttonPressed2 = 0;       // the button is not pressed
}

if( buttonToggleState2 )
	SensorValue[wing] = 1;
else
	SensorValue[wing] = 0;
