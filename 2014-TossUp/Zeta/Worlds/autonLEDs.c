if(455 <= SensorValue[aPot] < 910) {  	// case 2:
	SensorValue[redOne] = 1;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

else if(910 <= SensorValue[aPot] < 1365) {   // case 3:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 1;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

else if(1365 <= SensorValue[aPot] < 1820) {  // case 4:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 1;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

else if(1820 <= SensorValue[aPot] < 2275) {  // case 5:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 1;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

else if(2275 <= SensorValue[aPot] < 2730) {  // case 6:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 1;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

else if(2730 <= SensorValue[aPot] < 3185) {  // case 7:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 1;
	SensorValue[redThree] = 0;
}

else if(3185 <= SensorValue[aPot] < 3640) {  // case 8:
		SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 1;
}

else {
	SensorValue[redOne] = 0;
	SensorValue[greenOne] = 0;
	SensorValue[yellowOne] = 0;
	SensorValue[redTwo] = 0;
	SensorValue[greenTwo] = 0;
	SensorValue[yellowTwo] = 0;
	SensorValue[redThree] = 0;
}

