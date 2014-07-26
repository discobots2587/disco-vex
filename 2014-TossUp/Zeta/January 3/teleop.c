//StopTask(autonchooser);

// drive //////////////////////////////////////////////////////////////////////////

		motor(driveL1) = motor(driveL2) = vexRT[Ch3];
		motor(driveR1) = motor(driveR2) = vexRT[Ch2];

// lift //////////////////////////////////////////////////////////////////////////

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
        if(SensorValue[touchl] == 0){
            motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = -127;
            goal_lock = 0;
        }
        else {
         motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
         }
        break;
    case -1:
         motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 127;
        goal_lock = 0;
      break;

    case 0:
        if(goal_lock == 0){
            motor[liftL1] = motor[liftL2] = motor[liftR1] = motor[liftR2] = 0;
        }
        break;
    }
// collector /////////////////////////////////////////////////////////////////////////////
    if(vexRT[Btn5U] == 1) {
			motor(collector) = 127;
		}
		else if(vexRT[Btn5D] == 1) {
			motor(collector) = -127;
		}
		else {
			motor(collector) = 0;
		}

// Pneumatics ////////////////////////////////////////////////////////////////////////////

		if(vexRT[Btn7U] == 1) {
			SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = 1;
		}
		else if(vexRT[Btn7D] == 1) {
			SensorValue[pneuLiftL] = SensorValue[pneuLiftR] = 0;
		}
		if(vexRT[Btn7R] == 1) {
			SensorValue[pneuLock] = 1;
		}
		else if(vexRT[Btn7L] == 1) {
			SensorValue[pneuLock] = 0;
		}


