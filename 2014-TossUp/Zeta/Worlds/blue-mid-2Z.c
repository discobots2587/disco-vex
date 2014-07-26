collectorSet(127);

				// wait 300 milleseconds to stabalize the robot after raising lift
drive(127,127,2000);				// drive forward to knock off beach ball closest to tile into goal zone
wait1Msec(200);					// wait 50 milleseconds
		// drive back to tile (wait for repositioning)
