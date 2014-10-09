// *********************************************** // General Functions // ****************************************************** //
void stopdrivemotors()	{
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
}
/*
void waitforAnyBump()	{
	while(SensorValue[touchL] == 0 && SensorValue[touchR] == 0 && SensorValue[touch3] == 0)
		stopdrivemotors();
}
void waitforBumpL()	{
	while(SensorValue[touchL] == 0)
		stopdrivemotors();
}
void waitforBumpR()	{
	while(SensorValue[touchR] == 0)
		stopdrivemotors();
}
void waitforBump()	{
	while(SensorValue[touch3] == 0)
		stopdrivemotors();
}
*/

// *********************************************** // Drive Functions // ****************************************************** //
void drive (int driveL, int driveR, int duration) {
	motor[driveL1] = motor[driveL2] = driveL;
	motor[driveR1] = motor[driveR2] = driveR;
	wait1Msec(duration);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2]= 0;
}
void drive_acceleration(int driveL, int driveR, int duration) {
	int DL2 = driveL/3;
	int DR2 = driveR/3;

	while(DL2 < driveL && DR2 < driveR) {
		motor[driveL1] = motor[driveL2] = DL2;
		motor[driveR1] = motor[driveR2] = DR2;
		wait1Msec(duration/3);
		DL2 += driveL/3;
		DR2 += driveR/3;
	}
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
}

// *********************************************** // Lift Functions // ****************************************************** //
void lift (int liftraise, int time) {
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftraise;
	wait1Msec(time);
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}
int lock(int final_pos)	{ 														//locks arm to final_pos potentiometer point
	int speed;
	int current_pos = SensorValue(pot); 								//reads potentiometer
	float direction;                      							//up or down?
	int arm_diff = abs(current_pos - final_pos);				//difference between current and desired points

	if(arm_diff > 120) {  															//potentiometer is very precise, so
		if (current_pos > final_pos) {										//arm too high
			direction = -.5;    														//will move down
		}
		else if(current_pos < final_pos) { 								//arm too low
			direction = 1; 																	//will move up
		}

		speed = arm_diff/5;
		motor[liftL1] = motor[liftL2] = speed * direction ;	//sets motors
		motor[liftR1] = motor[liftR2] = speed * direction;

		return 0;
	}
	else {
		motor[liftL1] = motor[liftL1] = 15;
		motor[liftR1] = motor[liftR1] = 15;
		return 1;
	}
}


// *********************************************** // Collector Functions // ****************************************************** //

void collect (int gather, int duration) {
	motor[collectorL] = motor[collectorR] = gather;
	wait1Msec(duration);
	motor[collectorL] = motor[collectorR] = 0;
}

// *********************************************** // Multitasking Functions // **************************************************** //

void drive_collect (int drivespeed, int collectspeed, int duration) {

	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = drivespeed;
	motor[collectorL] = motor[collectorR] = collectspeed;
	wait1Msec(duration);
	motor[collectorL] = motor[collectorR] = 0;
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
}
void drive_lift (int drivespeed, int liftspeed, int duration, int solenoidPos) {
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = drivespeed;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
	wait1Msec(duration);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}
void lift_collect (int liftspeed, int collectspeed, int duration) {

	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
	motor[collectorL] = motor[collectorR] = collectspeed;
	wait1Msec(duration);
	motor[collectorL] = motor[collectorR] = 0;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}
void lifter(int arm)	{
	switch(arm){
	case medgoal:
		while(SensorValue[pot]< med-100)
		{
			motor[liftL1] = motor[liftL2] = 127;
			motor[liftR1] = motor[liftR2] = 127;
		}
		{
			motor[liftL1] = motor[liftL2] = 15;
			motor[liftR1] = motor[liftR2] = 15;
		}
		break;
	case lowgoal:
		while(SensorValue[pot]<low)
		{
			motor[liftL1] = motor[liftL2] = 127;
			motor[liftR1] = motor[liftR2] = 127;
		}
		{
			motor[liftL1] = motor[liftL2] = 15;
			motor[liftR1] = motor[liftR2] = 15;
		}
		break;
	case highgoal:
		while(SensorValue[pot]<highest-100)
		{
			motor[liftL1] = motor[liftL2] = 127;	//sets motors
			motor[liftR1] = motor[liftR2] = 127;
		}
		{
			motor[liftL1] = motor[liftL2] = 15;	//sets motors
			motor[liftR1] = motor[liftR2] = 15;
		}
		break;
	case gravityNot:	{
			ClearTimer(T4);
			while(SensorValue[touchL] != 1 && time1[T4] < 2000)		{
				{
					motor[liftL1] = motor[liftL2] = -63;	//sets motors
					motor[liftR1] = motor[liftR2] = -63;
				}
				// stoparmmotors();
			}
		}
	}	//switch
}

void drive_liftHeight(int lDrive,int rDrive, short height, int time) {
	motor[driveL1] = motor[driveL2] = lDrive;
	motor[driveR1] = motor[driveR2] = rDrive;
	lifter(height);
	wait1Msec(time);
  motor[driveL1] = motor[driveL2] = 0;
	motor[driveR1] = motor[driveR2] = 0;

	}

// *********************************************** // Set Functions // **************************************************** //
void collectorSet(int speed){
	motor[collectorL] = motor[collectorR] = speed;
}

void liftSet(int speed){
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = speed;
}

void driveSet(int speed){
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = speed;
}
