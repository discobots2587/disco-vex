collector_flip();
collectorSet(127);

waitforAnybump();

drive(127,90,1150);
wait1Msec(500);
lifter(highgoal);
drive(50,50,200);
drive(100,100,500);
drive(0,50,200);
collectorSet(0);
collect(-127,500);
drive_collect(50,-127,500);
collect(-127,2000);

drive(-50,-50,200);
drive(-100,-100,400);
lift(-127,500);

drive(70,-70,500);

drive(100,100,2000);
