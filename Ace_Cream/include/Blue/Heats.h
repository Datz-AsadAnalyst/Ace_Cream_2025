#include<Encoder.h>
#include<Motors.h>
#include<Line_Follow.h>
#include<Servocontrol.h>
#ifndef _Heats_H_
#define _Heats_H_
void heat(){
/*
 * Grid 9
 *
 *  grid is 3x3 the points are (1,2), (2,1) and (2,3)
*/
lineFollowUntil(4);
delay(1000);
///Left move
moveLeftEncoder(296,100);
delay(500);
linefollowFiveEncoder(50);
delay(500);

///////// line untill 2

linefollowFiveUntil(2); 
delay(1000);

//// left move
moveLeftEncoder(300,100);
delay(500);

linefollowFiveEncoder(20);
delay(500);

// until 1
linefollowFiveUntil(1);
delay(500);

//rightmove
moveRightEncoder(300,100);
delay(500);

leftServo.write(0);
delay(500);

linefollowFiveEncoder(30);
delay(500);

////untill 1
linefollowFiveUntil(1);
linefollowFiveEncoder(68);
delay(100);

// ////////////Pick 1st tree//////////////

servoMove(&leftServo,0,70);
delay(500);
 
//----
servoMove(&mainServo,0,72);
delay(500);

linefollowFiveEncoder(10);
delay(500);

///////// line until
linefollowFiveUntil(2);
delay(500);
///left move
moveLeftEncoder(305,100);
delay(500);

backLinefollowFiveEncoder(78);
delay(500);
frontServo.write(0);
delay(500);
linefollowFiveEncoder(150);
delay(500);
// ////////////Pick 2nd tree//////////////
servoMove(&frontServo,0,70);
delay(500);



/////line
linefollowFiveUntil(2);
delay(500);
// //////// left move
moveLeftEncoder(300,100);
delay(500);
backLinefollowFiveEncoder(10);
delay(500);
moveMainToOneEighty();
delay(500);
// linefollowFiveEncoder(20);


servoMove(&rightServo,0,70);
delay(500);
// ///////////Pick 3rd tree/////////
linefollowFiveEncoder(20);
delay(500);
///// line until 2
linefollowFiveUntil(2);
delay(500);

///right move
moveRightEncoder(300,100);
delay(500);
/////until 1
linefollowFiveUntil(1);
delay(500);
//left move
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(10);
delay(500);
//until 1
linefollowFiveEncoder(15);
delay(500);
linefollowFiveUntil(1);
delay(500);
////////placing 1st /////////////
linefollowEncoder(50);
delay(500);
servoMove(&rightServo,70,0);
delay(500);
// ///////Drop red one
// ////// back line follow until 5
backlinefollowfiveUntil(5);
delay(500);
backLinefollowFiveEncoder(20);
delay(500);

//////////placing 2nd //////////
servoMove(&leftServo,70,30);
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
//left move
moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(10);
delay(500);
servoMove(&frontServo,70,0);
delay(500);
// ////////drop other one
////// back until 2
backlinefollowfiveUntil(2);
delay(500);
moveRightEncoder(300,100);
delay(500);
moveForwardEncoder(600,100);
//////////End in parking 

}


#endif // _HEATS_H_