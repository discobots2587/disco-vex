#pragma config(Sensor, in1,    armPot,              sensorPotentiometer)
#pragma config(Sensor, in2,    gyro,                sensorGyro)
#pragma config(Sensor, dgtl1,  area,                sensorDigitalIn)
#pragma config(Sensor, dgtl2,  color,               sensorDigitalIn)
#pragma config(Sensor, dgtl3,  ,                    sensorQuadEncoder)
#pragma config(Motor,  port1,           backleft,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           left,          tmotorNormal, openLoop)
#pragma config(Motor,  port3,           armright1,     tmotorNormal, openLoop)
#pragma config(Motor,  port4,           armleft1,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port5,           spin,          tmotorNormal, openLoop)
#pragma config(Motor,  port6,           spin2,         tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port7,           armleft2,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port8,           armright2,     tmotorNormal, openLoop)
#pragma config(Motor,  port9,           right,         tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port10,          backright,     tmotorNormal, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "PIDController.c"

/////////////////////////////////////////////////////////////////////////////////////////
//
//                         Driver Skills Template
//
// This is a template for the driver skills competition. It is identical in structure to
// the standard competition template except that the two "#pragma' statements above (and
// copied below) adjust the time limits for the competition.
//				#pragma autonomousDuration(0)
//				#pragma userControlDuration(60)
// The autonomous duration for "Driver Skills" is zero; i.e. there is no autonomous phase.
// The user control duration is 60 seconds
//
// NOTE: The above two pragmas only impact the Crystal implementation. For systems using
//       VEXNET, the VEXNET system ignores these statements as it has the durations
//       for the competition built-in.
//
// Whenever this user program is run, the duration is automatically sent to the VEX master
// processor. The master CPU will only accept these commands once per power=on cycle. So, it's
// best to power cycle your VEX to ensure that they get recognized in case you were
// previously running a standard competition program with different durations.
//
int leftDrivePower, rightDrivePower, x, y, rampLimit = 2, leftDrivePrevious, rightDrivePrevious;//drivetrain variables


void resetDriveVariables(){
  leftDrivePower = rightDrivePower = x = y = leftDrivePrevious = rightDrivePrevious = 0;
}
void setDriveMotors(){
  motor[left] = leftDrivePower;
  motor[backleft] = leftDrivePower;
  motor[right] = rightDrivePower;
  motor[backright] = rightDrivePower;
}

void stopDrive(){
  rightDrivePower = leftDrivePower = 0;
  setDriveMotors();
}

void driveTank(int left, int right, bool square, bool ramp){
  if(square)
  {
    if(left!=0)
    {
      leftDrivePower = ((left*left)/127)*(left/abs(left));
    }
    else
    {
      leftDrivePower = 0;
    }

    if(right!=0)
    {
      rightDrivePower = ((right*right)/127)*(right/abs(right));
    }
    else
    {
      rightDrivePower = 0;
    }
  }
  else
  {
    leftDrivePower = left;
    rightDrivePower = right;
  }

  if(ramp == true)
  {
    if(abs(rightDrivePower) > abs(rightDrivePrevious) + rampLimit)
    {
      if(rightDrivePower > (rightDrivePower + rampLimit))
      {
        rightDrivePower = rightDrivePrevious + rampLimit;
      }
      else
      {
        rightDrivePower = rightDrivePrevious - rampLimit;
      }
  }

    if(abs(leftDrivePower) > abs(leftDrivePrevious) + rampLimit){
      if(leftDrivePower > (leftDrivePower + rampLimit)){
        leftDrivePower = leftDrivePrevious + rampLimit;
      }
      else{
        leftDrivePower = leftDrivePrevious - rampLimit;
      }
    }
  }

  setDriveMotors();
}

void driveArcade(int power, int turn, bool square, bool ramp){
  if(square)
  {
    if(power != 0)
    {
      y = ((power*power)/127)*(power/abs(power));
    }
    else
    {
      y = 0;
    }

    if(turn!=0)
    {
      x = ((turn*turn)/127)*(turn/abs(turn));
    }
    else
    {
      x = 0;
    }
  }
  else
  {
    y = power;
    x = turn;
  }

  leftDrivePower = y+x;
  rightDrivePower = y-x;

  if(ramp == true)
  {
    if(abs(rightDrivePower) > abs(rightDrivePrevious) + rampLimit)
    {
      if(rightDrivePower > (rightDrivePower + rampLimit))
      {
        rightDrivePower = rightDrivePrevious + rampLimit;
      }
      else
      {
        rightDrivePower = rightDrivePrevious - rampLimit;
      }
    }

    if(abs(leftDrivePower) > abs(leftDrivePrevious) + rampLimit)
    {
      if(leftDrivePower > (leftDrivePower + rampLimit))
      {
        leftDrivePower = leftDrivePrevious + rampLimit;
      }
      else
      {
        leftDrivePower = leftDrivePrevious - rampLimit;
      }
    }
  }

  setDriveMotors();

  leftDrivePrevious = leftDrivePower;
  rightDrivePrevious = rightDrivePower;
}
/*******************************************************************************************Arm & Claw Code****************************************************************************************/

/*********PID Variables****************/
/**************************************/
PIDController Arm;

int ArmSetPoint;
int ArmKp = 10,ArmKi = 0, ArmKd = 0;

/**************************************/
/**************************************/

void setArmPids(kp, ki, kd){
  ArmKp = kp;
  ArmKi = ki;
  ArmKd = kd;
  setPIDs(Arm, ArmKp, ArmKi, ArmKd);
}

// LDR November 11, 2011 -- armPot: armFloor = 1975, armHighPlace = 3730, armMax =
int armPower, spinPower, armPosition, clawPosition, armTolerance, clawTolerance, initialArmPosition, initialClawPosition, armOffset, clawOffset;//arm and claw tolerance to be set
int armFloor = 1975, armLowPlace = 2670, armLowScore = 2570, armMidPlace = 3060, armMidScore = 2940, armHighPlace = 3550, armHighScore = 3400, armMax = 3845, armSetPoint, armState = 0;//arm positions. Place is position above goal, Score is on goal for tubes, floor is start position
int armInput, clawInput, armPreviousInput, armRampLimit = 2, rampClawLimit = 0.2;//arm variables used in competitions code. Placed here to keep them with the rest of the arm variables
bool armPositionReached, slowClose = false;
int isolation;


void setArmMotors(){

  motor[armleft1] = motor[armleft2] = motor[armright1] = motor[armright2] = armPower;
}

void armMove(int aPower){
  armPower = aPower;
  motor[armleft1] = motor[armleft2] = motor[armright1] = motor[armright2] = armPower;
}

void spinMove(int sPower)
{
  spinPower = sPower;
  motor[spin] = motor[spin2] = spinPower;
}


/*****************************************************************************************Competition Code*****************************************************************************************/
/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////
void pre_auton()
{

  //init(Arm,1);
}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{

  {
      time1[T1] = 0;
		  while(time1[T1] < 1300) //flip out rotors and intake pre-load
			    spinMove(128);
			spinMove(0);

			time1[T1] = 0;
		  while(time1[T1] <1500)  // raise arm to high goal level
			    armMove(100);

		  time1[T1] = 0;
		  while (time1[T1] < 3000) //hold up arm to allow for loading
		      armMove(50);

		  time1[T1] = 0;
		  while (time1[T1] < 4500) //Drive forwards to goal, (while holding up arm)
		     driveArcade(40,0,false,false);

		  driveArcade(20,0,false,false);
		  time1[T1] = 0;
		  while (time1[T1] < 3000) //Release load and score!! (while holding up arm)
			  spinMove(-80);          //        ^ lolololol

		  armMove(0);
		  spinMove(0);

		  time1[T1]=0;//Drive home and lower arm
		  while (time1[T1]<1650){
		    if(time1[T1]>500){
		      armMove(-45);
		      if(SensorValue[armPot]<=armFloor+20) armMove(0);
		    }
		    driveArcade(-100,0,false,false);
		  }
		  armMove(0);
		  driveArcade(0,0,false,false);

		  time1[T1]=0;//wait to repostition robot for 4 whole seconds
		  while(time1[T1]<4000){
		  }

		  time1[T1]=0;//Drive like an old Asian lady to the doubler
		  spinMove(128);//because omnomnomnom
		  while(time1[T1]<5000){
		    driveArcade(40,0,false,false);
		  }
		  spinMove(0);

		  time1[T1]=0;//Drive home
		  while(time1[T1]<2200){
		    driveArcade(-99,0,false,false);
		  }
		  driveArcade(0,0,false,false);

		  time1[T1]=0;//Wait for only 3 seconds
		  while(time1[T1]<3000){
		  }

      //Do the same thing as before to put the doubler in the goal
		  time1[T1] = 0;
		  while(time1[T1] <1500)  // raise arm to high goal level
			    armMove(100);

      armMove(10);
		  time1[T1] = 0;
		  while (time1[T1] < 3500) //Drive forwards to goal, (while holding up arm)
		     driveArcade(40,0,false,false);

		  time1[T1] = 0;
		  while (time1[T1] < 3000) //Release load and score!! (while holding up arm)
			  spinMove(-80);

			armMove(0);
			spinMove(0);

			//make sure it's never the programmer's fault
			bool RickIsDumb=true;
			bool itsRicksFault=false;
			if(RickIsDumb){
			itsRicksFault=true;
			}
  }

  if(false)  //**************Why is this even here?***********************************************//
  {
    // time1[T1] = 0;
	  // while(time1[T1] < 500)   //push slightly forwards to fit barell into claw
	  // {
	    // driveArcade(32,0,false,false);
	  // }
	  // driveArcade(0,0,false,false);


    // time1[T1] = 0;
	  // while(time1[T1] < 250)   //reverse to fit barell into claw
	  // {
	    // driveArcade(-32,0,false,false);
	  // }
	  // driveArcade(0,0,false,false);


	  // time1[T1] = 0;
	  // while(time1[T1] < 500)  //close claw
	  // {
	    // clawPower = 100;
	    // armMove(0,clawPower);
	  // }

	  // while(sensorValue[armPot] < armHighPlace)  // raise to high goal level
	  // {
	    // armPower = 64;
	    // armMove(armpower,0);
	  // }


	  // time1[T1] = 0;
	  // while(time1[T1] < 4000)    //drive forwards to goal
	  // {
	    // driveArcade(32,0,false,false);

	  // }
	  // driveArcade(0,0,false,false);

	  // time1[T1] = 0;
	  // while(time1[T1] < 650)  //open claw to score!
	  // {
	    // clawPower = -15;
	    // armMove(0,clawPower);
	  // }

	  // while(sensorValue[clawPot] > clawOpen) //finish opening claw
	 // {
	    // clawPower = -100;
	    // armMove(0,clawPower);
   // }

	  //   after first score
	  // time1[T1] = 0;
	  // while(time1[T1] < 4000)    //drive backwards to red zone
	  // {
	    // driveArcade(-40,0,false,false);

	  // }
	  // driveArcade(0,0,false,false);

	  // while(sensorValue[armPot] > armFloor)  // lower arm to floor
	  // {
	    // armPower = -64;
	    // armMove(armpower,0);
	  // }

}
/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////
}
//I don't know why the programming skills program has a user control part, so don't ask

task usercontrol()
{
	// User control code here, inside the loop

resetDriveVariables();
  armState = 0;
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.
	while (true)
	{
    driveArcade(vexRT[Ch3],vexRT[Ch4],true,true);//leave both square and ramp as false until the code is proven to work

    if (vexRT[Btn6U] != 0){
      clawInput = 128;
      slowClose = false;
    }
    else if(vexRT[Btn6D] != 0){
      clawInput = -63;
      slowClose = false;
    }
    else if(vexRT[Btn5U] != 0){
      clawInput = 40;
      slowClose = true;
    }
    else if(vexRT[Btn5D]){
      clawInput = -31;
      slowClose = true;
    }
    else{
      clawInput = 0;
      slowClose = false;
    }

    armMove(vexRT[Ch2]);
  }
}
