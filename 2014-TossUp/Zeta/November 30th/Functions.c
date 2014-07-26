// the following are drive functions...
void turn( int time,int direction, int speed)	{//direction: 1 = right, -1 = left.
	motor[driveL1] = motor[driveL2] = speed*direction;
	motor[driveR1] = motor[driveR2] = speed*direction*-1;
}
void stopdrivemotors()	{
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
}
void movefowardtime(float time, int speed, int direction)	{ // 1 = fowards
	ClearTimer(T4);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = speed* direction;
	wait1Msec(time*1000);
	stopdrivemotors();
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
void drive (int driveL, int driveR, int duration) {
	motor[driveL1] = motor[driveL2] = driveL;
	motor[driveR1] = motor[driveR2] = driveR;
	wait1Msec(duration);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2]= 0;
}

// the following are lift functions...
	int lock(int final_pos)	{ 													//locks arm to final_pos potentiometer point
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

void lift (int liftraise, int time, int cedric) {
	SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = cedric;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftraise;
	wait1Msec(time);
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}

// the following are collector functions...

void spin(int direction, float time)	{
	motor[collector] = 127 * direction;
	wait1Msec(time * 1000);
	motor[collector] = 0;
}
void collect (int gather, int duration) {
	motor[collector] = gather;
	wait1Msec(duration);
	motor[collector] = 0;
}

void collector_flip () {
	motor[collector] = 127;
	wait1Msec(250);
	motor[collector] = 0;
}

// the following are multitasking functions...
void drive_lift (int drivespeed, int liftspeed, int duration, int solenoidPos) {
	SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = solenoidPos;
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = drivespeed;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
	wait1Msec(duration);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}

void drive_collect (int drivespeed, int collectspeed, int duration) {

	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = drivespeed;
	motor[collector] = collectspeed;
  wait1Msec(duration);
  motor[collector] = 0;
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
}

void lift_collect (int liftspeed, int collectspeed, int duration, int Pneu) {

	SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = Pneu;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
	motor[collector] = collectspeed;
  wait1Msec(duration);
  motor[collector] = 0;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
	}
// the following functions do not fit into the above catagories...
void lift(int liftspeed) {
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
}

void screenrefresh()	{
	clearLCDLine(1);
	displayLCDPos(1,0);

	if (redteam == true)	{
		displayNextLCDString("RED ");
	}

	if (redteam == false)	{
		displayNextLCDString("BlUE");
	}

	displayNextLCDString("    ");
	displayNextLCDNumber(programselect);
	displayNextLCDString("     OK");
}

void waitforBump()	{
	while(SensorValue[Bump] == 0)
		stopdrivemotors();
}
void stoparmmotors() {
		motor[liftL1] = motor[liftL2] = 0;	//sets motors
		motor[liftR1] = motor[liftR2] = 0;
		}
void clearEncoders(){
	nMotorEncoder[driveL1] = 0;
	nMotorEncoder[driveL2] = 0;
}

void drive_drive_lift (int driveLL,int driveRR, int liftspeed, int duration, int solenoidPos) {
	SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = solenoidPos;
	motor[driveL1] = motor[driveL2] = driveLL;
	motor[driveR1] = motor[driveR2] = driveRR;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = liftspeed;
	wait1Msec(duration);
	motor[driveL1] = motor[driveL2] = motor[driveR1] = motor[driveR2] = 0;
	motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
}

void lifter(int arm)
{
	SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = 1;
  switch(arm){
  case medgoal:
    while(SensorValue[pot]< med-100)
    {
     motor[liftL1] = motor[liftL2] = 127;	//sets motors
		motor[liftR1] = motor[liftR2] = 127;
    }
    {
     motor[liftL1] = motor[liftL2] = 15;	//sets motors
		motor[liftR1] = motor[liftR2] = 15;
    }
    break;
  case lowgoal:
    while(SensorValue[pot]<low-100)
    {
      motor[liftL1] = motor[liftL2] = 127;	//sets motors
			motor[liftR1] = motor[liftR2] = 127;
    }
    {
      motor[liftL1] = motor[liftL2] = 15;	//sets motors
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
  case gravityNot:
    {
      ClearTimer(T4);
      while(SensorValue[touchl] != 1 && time1[T4] < 2000)
      {
        {
        	//SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = 0;
          	motor[liftL1] = motor[liftL2] = -63;	//sets motors
			      motor[liftR1] = motor[liftR2] = -63;
        }

        stoparmmotors();

      }
    }
  }//switch
}

/*
  Name: drive_Enc
  Purpose: Drives a certain distance foward using encoders and time.
  @Author: Lance Dinh
*/
void drive_Enc(int speed, float distance,int time)
{
  clearEncoders();
  ClearTimer(T4);
  //wait10Msec(23)
  while( ( ((float) abs(nMotorEncoder[driveL1])  * 1.6 / 360 * PI) < distance &&
    ( (float) abs(nMotorEncoder[driveR1]) * 1.6 / 360 * PI) < distance) && time1[T4] < time*1000) {
        speed = distance/10;
    if(nMotorEncoder[driveL1] > nMotorEncoder[driveR1]) {
      motor[driveL1] = speed-1;
      motor[driveL2] = speed-1;
      motor[driveR1] = speed;
      motor[driveR2] = speed;
      }
    else if(nMotorEncoder[driveL1] < nMotorEncoder[driveR1]) {
      motor[driveL1] = speed;
      motor[driveL2] = speed;
      motor[driveR1] = speed-1;
      motor[driveR2] = speed-1;
    }
    else {
      motor[driveL1] = speed;
      motor[driveL2] = speed;
      motor[driveR1] = speed;
      motor[driveR2] = speed;
    }
  }
  stopdrivemotors();
}
