#include<Encoder.h>
#include<Motors.h>
#include<Line_Follow.h>

#ifndef _BLUE_GRID5_H_
#define _BLUE_GRID5_H_
void blue_grid5(){
/*
 * Grid 5
 *
 *  grid is 3x3 the points are (1,1), (2,2) and (3,3)
*/
lineFollowUntil(4);
delay(500);
///Left move
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(50);
delay(500);
///////// line untill 3
 linefollowFiveUntil(3); 
delay(1000);
//// left move
moveLeftEncoder(300,100);
delay(500);
////////////Pick 1st tree//////////////
linefollowFiveEncoder(35);
delay(500);
 linefollowFiveUntil(2); 
delay(1000);
/////right move
moveRightEncoder(330,100);
delay(500);
///////////Pick 2nd tree/////////
linefollowFiveEncoder(35);
delay(500);
// ///////////Pick 3rd tree/////////
// linefollowFiveEncoder(35);
// delay(500);
/////line until 2
linefollowFiveUntil(2);
delay(500);
// left move
 moveLeftEncoder(330,100);
delay(500);
linefollowFiveEncoder(40);
delay(500);
/// line untill 2
 linefollowFiveUntil(2); 
 delay(500);
 //////////left move
 moveLeftEncoder(330,100);
 delay(500);
////////line untill 2
linefollowFiveUntil(2);
delay(500);

///////Drop red one
////// back line follow until 5
backlinefollowfiveUntil(5);
delay(500);
backLinefollowFiveEncoder(20);
delay(500);
linefollowFiveEncoder(20);
delay(500);
////////drop other one
///// left move
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(60);
delay(500);
/////// line untill 4
linefollowFiveUntil(4);
delay(500);
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(100);
delay(500);
////////drop other one
////// back until 2
backlinefollowfiveUntil(2);
delay(500);
moveRightEncoder(300,100);
delay(500);
moveForwardEncoder(600,100);
//////////End in parking 

}


#endif // _BLUE_GRID5_H_