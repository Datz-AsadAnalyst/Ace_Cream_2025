#include<Encoder.h>
#include<Motors.h>
#include<Line_Follow.h>

#ifndef _BLUE_GRID20_H_
#define _BLUE_GRID20_H_

void blue_grid20(){
//////line follow until 4 strips
lineFollowUntil(4);
delay(500);
///Left move
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(50);
delay(500);
///////// line untill 5
 linefollowFiveUntil(5); 
delay(1000);
//// left move
moveLeftEncoder(300,100);
delay(500);
////////pick 1st tree
linefollowFiveEncoder(35);
delay(500);
/////// line untill 2
linefollowFiveUntil(2); 
delay(500);
//// left move
 moveLeftEncoder(300,100);
delay(500);
/////pick 2nd tree
linefollowFiveEncoder(35);
delay(500);
///// line untill 1
 linefollowFiveUntil(1); 
delay(500);
///pick 3rd tree
linefollowFiveEncoder(35);
delay(500);
// right move
 moveRightEncoder(300,100);
delay(500);

/// line untill 2
 linefollowFiveUntil(2); 
 delay(500);
 /// left move
  moveLeftEncoder(310,100);
delay(500);
linefollowEncoder(200);
delay(500);
////// back line follow until 4
backlinefollowfiveUntil(5);
delay(500);
backLinefollowFiveEncoder(20);
delay(500);
linefollowFiveEncoder(20);
delay(500);
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
////// back until 2
backlinefollowfiveUntil(2);
delay(500);
moveRightEncoder(300,100);
delay(500);
moveForwardEncoder(600,100);

}

#endif // _BLUE_GRID20_H_