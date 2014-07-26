
/*
if redteam == true, then robot on red side
if redteam == false, then robot on blue side
if programselect == 1 or programselect = 2, then robot in mid-zone
if programselect == 3 or programselect = 4, then robot in hang-zone
*/

// the following is our auton code... (last edited 11/8/13 by Cedric Shy)


// mid-zone(1), red... (last edited 11/8/13 by Cedric Shy)
if(programselect == 1 && redteam == true) {
#include"red-mid-1.c"
//#include"Programming Skills.c"
}
//mid-zone(2), red
if(programselect == 2 && redteam == true) {
#include"Programming Skills.c"
//#include"red-mid-2.c"
}
//hang(1), red
if(programselect == 3 && redteam == true) {
#include"red-hang-1.c"
}
//hang(2), red
if(programselect == 4 && redteam == true) {
#include"red-hang-2.c"
}
//mid(1), blue
if(programselect == 1 && redteam == false) {
#include "blue-mid-1.c"
}
//mid(2), blue
if(programselect == 2 && redteam == false) {
#include "blue-mid-2.c"
}
//hang(1), blue
if(programselect == 3 && redteam == false) {
#include "blue-hang-1.c"
}
//hang(2), blue
if(programselect == 4 && redteam == false) {
#include "blue-hang-2.c"
}
