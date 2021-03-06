#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in8,    pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl7,  touchl,         sensorTouch)
#pragma config(Sensor, dgtl8,  bump5,          sensorTouch)
#pragma config(Sensor, dgtl9,  bump4,          sensorTouch)
#pragma config(Sensor, dgtl10, bump3,          sensorTouch)
#pragma config(Sensor, dgtl11, bump2,          sensorTouch)
#pragma config(Sensor, dgtl12, bump1,          sensorTouch)
#pragma config(Motor,  port1,           driveL1,       tmotorVex393HighSpeed_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           driveL2,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           driveL3,       tmotorVex393HighSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           liftL,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port5,           collectorL,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           collectorR,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           liftR,         tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port8,           driveR1,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port9,           driveR2,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port10,          driveR3,       tmotorVex393HighSpeed_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//int speed;
//int turning_power;

#include"Functions.c"


void pre_auton()
{

}

task autonomous()	{
//#include"red-hang-1.c"
#include"red-mid-1.c"
//#include"blue-hang-1.c"
//#include"blue-mid-1.c"

//if(SensorValue[bump1] == 1) {
//	#include"red-mid-1.c"
//}

//if(SensorValue[bump2] == 1) {
////	#include"red-hang-1.c"
//}

//if(SensorValue[bump3] == 1) {
//	#include"blue-mid-1.c"
//}

//if(SensorValue[bump4] == 1) {
////	#include"blue-hang-1.c"
//}


	}

task usercontrol()
{

	while (true)
	{
		// drive //////////////////////////////////////////////////////////////////////////

		motor(driveL1) = motor(driveL2) = motor(driveL3) = vexRT[Ch3];
		motor(driveR1) = motor(driveR2) = motor(driveR3) = vexRT[Ch2];
		//motor[driveL1] = motor[driveL2] = motor[driveL3] = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
  	//motor[driveR1] = motor[driveR2] = motor[driveR3] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
		//speed = vexRT[Ch2];
		//turning_power = speed*vexRT[Ch4];
		//motor[driveL1] = motor[driveL2] = motor[driveL3]
		//motor[driveR1] = motor[driveR2] = motor[driveR3]
		//= speed + turning_power;


		// lift //////////////////////////////////////////////////////////////////////////

		if(vexRT[Btn6U] == 1) {
			motor[liftL] = motor[liftR] = 127;
		}
		else if(vexRT[Btn6D] == 1) {
			motor[liftL] = motor[liftR] = -127;
		}
		else {
			motor[liftL] = motor[liftR] = 0;
		}

		// collector /////////////////////////////////////////////////////////////////////////////
		if(vexRT[Btn5U] == 1) {
			motor(collectorL) = motor(collectorR) = 127;
		}
		else if(vexRT[Btn5D] == 1) {
			motor(collectorL) = motor(collectorR) = -127;
		}
		else {
			motor(collectorL) = motor(collectorR) = 0;
		}
	}

}
