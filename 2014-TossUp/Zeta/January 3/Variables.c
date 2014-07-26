// the following is the vast majority of the variables used throughout our code... (last edited 11/3/13 by Lance Dinh)

// the following variables are used for the LCD screen auton selection... (last edited 11/3/6 by Peter Dulworth)
int programselect = 1;							// an integer used when selecting autonomouses on the LCD screen
bool redteam = true;								// a boolean variable used when selecting autonomous routines on the LCD screen
bool programselecting = true;				// used in a while loop to keep the while loop from repeating itself during the LCD pre_auton phase
const int totalprogramnumber = 4;		// this number multiplied by 2, is the maximum number of autonomous routines that can be loaded on the robot(can be changed)

//the following variables are used for PID on the arm...
int goal_lock = 0;						//
const short highest = 3400-75;		// the potentiometer value of our highest arm preset (silo scoring height)
const short med = 2750;				// the potentiometer value of our middle arm preset (aprox. 14 in. off ground)
const short low = 1917+50;				// the potentiometer value of our lowest arm preset (off the ground high enough to go over bump)
//Lift stuff
const int lowgoal = 0;
const int medgoal = 1;
const int highgoal = 2;
const int gravityNot = 3;
