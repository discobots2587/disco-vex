	bLCDBacklight = true;
	displayLCDPos(0,0);
	displayNextLCDString("Color Number");

  redteam = true;
  screenrefresh();
  time1[T1] = 0;

  while (programselecting == true)	{
    if (nLCDButtons & kButtonLeft)	{
      while (nLCDButtons & kButtonLeft)	{}
      	if (redteam == true)	{
        	redteam = false;
        }

      	else if (redteam == false)	{
				redteam = true;
				}

      	screenrefresh();
    }

    if (nLCDButtons & kButtonCenter)	{
      while (nLCDButtons & kButtonCenter)	{}

      programselect = programselect+1;

      if (programselect > totalprogramnumber)	{
        programselect = 1;
      }

      screenrefresh();
    }

    if (nLCDButtons & kButtonRight)	{

      clearLCDLine(0);
      clearLCDLine(1);
      displayLCDPos(0,0);

      displayNextLCDString("GO DISCO!!!");
      wait1Msec(300);

      displayNextLCDString(".");
      wait1Msec(1000);
      displayNextLCDString(".");
      wait1Msec(1000);
      displayNextLCDString(".");
      wait1Msec(1000);

      bLCDBacklight = false;
      programselecting = false;
		} //if
	} //while


//////  task autonchooser()
////  {
//  programselecting = true;
//	bLCDBacklight = true;
//	displayLCDPos(0,0);
//	displayNextLCDString("program select");

//  redteam = true;
//  screenrefresh();
//  time1[T1] = 0;

//  while (programselecting == true && usercontrol == false)	{
//    if (nLCDButtons & kButtonLeft)	{
//      while (nLCDButtons & kButtonLeft)	{}
//      	if (redteam == true)	{
//        	redteam = false;
//        }

//      	else if (redteam == false)	{
//				redteam = true;
//				}

//      	screenrefresh();
//    }

//    if (nLCDButtons & kButtonCenter)	{
//      while (nLCDButtons & kButtonCenter)	{}

//      programselect = programselect+1;

//      if (programselect > totalprogramnumber)	{
//        programselect = 1;
//      }

//      screenrefresh();
//    }

//    if (nLCDButtons & kButtonRight)	{

//      clearLCDLine(0);
//      clearLCDLine(1);
//      displayLCDPos(0,0);

//      displayNextLCDString("Robot ready");
//      wait1Msec(300);

//      displayNextLCDString(".");
//      wait1Msec(300);
//      displayNextLCDString(".");
//      wait1Msec(300);
//      displayNextLCDString(".");
//      wait1Msec(500);

//      bLCDBacklight = false;
//      programselecting = false;
//		} //if
//	} //while
////}
