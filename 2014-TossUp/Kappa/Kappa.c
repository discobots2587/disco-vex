#pragma config(Motor,  port1,           lbDrive,       tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rbDrive,       tmotorVex393, openLoop)
#pragma config(Motor,  port3,           lfDrive,       tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rfDrive,       tmotorVex393, openLoop)
#pragma config(Motor,  port5,           bin1,          tmotorVex269, openLoop)
#pragma config(Motor,  port6,           bin2,          tmotorVex269, openLoop)
#pragma config(Motor,  port7,           bin3,          tmotorVex269, openLoop)
#pragma config(Motor,  port8,           bin4,          tmotorVex269, openLoop)
#pragma config(Motor,  port9,           spatula1,      tmotorVex269, openLoop)
#pragma config(Motor,  port10,          spatula2,      tmotorVex269, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "Vex_Competition_Includes.c"

void pre_auton()
{

}
task autonomous()
{
  motor[port5] = motor[port7] = 127;
  motor[port6] = motor[port8] = -127;
	wait1Msec(3000);
	motor[port5] = motor[port6] = motor[port7] = motor[port8] = 0;
}

task usercontrol()
{
	while(true)
	{
  	motor[port1] = -vexRT[Ch3];
		motor[port3] = vexRT[Ch3];
		motor[port4] = -vexRT[Ch2];
		motor[port2] = vexRT[Ch2];
		motor[port5] = motor[port7] =(vexRT[Btn5U] - vexRT[Btn5D])*127;
		motor[port6] = motor[port8] =-(vexRT[Btn6U] - vexRT[Btn6D])*127;
		motor[port9] = -(vexRT[Btn7U]-vexRT[Btn7D])*127;
		motor[port10]= (vexRT[Btn8U]-vexRT[Btn8D])*127;
	}
}
