if(0 <= SensorValue[aPot] < 455) {  		// case 1:
	#include "red-mid-1z.c"
}

else if(455 <= SensorValue[aPot] < 910) {  	// case 2:
	//#include "red-mid-2z.c"
}

else if(910 <= SensorValue[aPot] < 1365) {   // case 3:
	//#include "red-hang-1z.c"
}

else if(1365 <= SensorValue[aPot] < 1820) {  // case 4:
	//#include "red-hang-2z.c"
}

else if(1820 <= SensorValue[aPot] < 2275) {  // case 5:
	//#include "blue-mid-1z.c"
//#include "red-mid-3z.c"
}

else if(2275 <= SensorValue[aPot] < 2730) {  // case 6:
	//#include "blue-mid-2z.c"
//#include "red-hang-3z.c"
}

else if(2730 <= SensorValue[aPot] < 3185) {  // case 7:
	//#include "blue-hang-1z.c"
}

else if(3185 <= SensorValue[aPot] < 3640) {  // case 8:
	//#include "blue-hang-2z.c"
}

else if(3640 <= SensorValue[aPot] < 4095) {  // case 9:
	#include "blue-mid-1z.c"
}
