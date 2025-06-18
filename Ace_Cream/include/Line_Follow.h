#include<Arduino.h>
#include<Motors.h>
#include<Encoder.h>

#ifndef _LINE_FOLLOW_H_
#define _LINE_FOLLOW_H_

extern int strips_count;
extern bool is_line;

extern unsigned long previousMillis;
extern const unsigned long intervalMillis;

// -----------------------------
int front[] = {A5, A6, A7, A9, A8};
int back[] = {A4, A0, A3, A1, A2};

///black 1
//white 0

int MID_right = A10;
int MID_left = A11;


// // Sensor Pins - Front

// int frontRightMost = A8;
// int frontRight = A9;
// int frontMiddle = A7;
// int frontLeft = A6;
// int frontLeftMost = A5;

// // Sensor Pins - Back

// int backLeftMost = A4;
// int backLeft = A0;
// int backMiddle = A3;
// int backRight = A1;
// int backRightMost = A2;

// Threshold for analog IR sensors
int threshold = 700;


void linefollow(int speed)
{
  // white 1
  // black 0

  int frontLeft = analogRead(front[1]) > 700 ? 1 : 0;
  int frontcenter = analogRead(front[2]) > 700 ? 1 : 0;
  int frontRight = analogRead(front[3]) > 700 ? 1 : 0;

 

  if (frontLeft == 0 && frontcenter == 0 && frontRight == 0)
  {
    moveForward(speed);
  }
  else if (frontLeft == 1 && frontcenter == 0 && frontRight == 1)
  {
    moveForward(speed);
  }
  else if (frontLeft == 0 && frontcenter == 1 && frontRight == 1)
  {
    turnLeft(speed);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRight == 0)
  {
    turnRight(speed);
  }
  else
  {
    moveForward(speed);
  }
}

void lineFollowUntil(int count) {
  int strips_count = 0;

  while (true) {
    // int Mid_l = digitalRead(MID_left) ;
    // int Mid_r = digitalRead(MID_right) ;

  int Mid_r = analogRead(MID_right) > 700 ? 1 : 0;
  int Mid_l = analogRead(MID_left) > 700 ? 1 : 0;
  

    if (Mid_l==0 && Mid_r==0 && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      linefollow(40);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}



void linefollowWithFive(int speed)
{
  // white 1
  // black 0

  int frontLeftmost = analogRead(front[0]) > 700 ? 1 : 0;
  int frontLeft = analogRead(front[1]) > 700 ? 1 : 0;
  int frontcenter = analogRead(front[2]) > 700 ? 1 : 0;
  int frontRight = analogRead(front[3]) > threshold ? 1 : 0;
  int frontRightmost = analogRead(front[4]) > threshold ? 1 : 0;

  if (frontLeft == 0 && frontcenter == 0 && frontRight == 0)
  {
    moveForward(speed);
  }
  else if (frontLeft == 1 && frontcenter == 0 && frontRight == 1)
  {
    moveForward(speed);
  }
  else if (frontLeft == 0 && frontcenter == 1 && frontRight == 1)
  {
    turnLeft90(speed);
  }
  else if (frontLeftmost == 0 && frontcenter == 1 && frontRight == 1)
  {
    turnLeft90(speed);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRight == 0)
  {
    turnRight90(speed);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRightmost == 0)
  {
    turnRight90(speed);
  }
  else
  {
    moveForward(speed);
  }
}



 void linefollowFiveUntil(int count)
{
  int strips_count = 0;

  while (true) {
    // int Mid_l = digitalRead(MID_left) ;
    // int Mid_r = digitalRead(MID_right) ;

  int Mid_r = analogRead(MID_right) > 700 ? 1 : 0;
  int Mid_l = analogRead(MID_left) > 700 ? 1 : 0;

    if (Mid_l==0 && Mid_r==0 && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      linefollowWithFive(80);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}
// void backLinefollow(int speed)
// {
//   // white 1
//   // black 0

//   int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
//   int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
//     int backRight = analogRead(back[3]) > threshold ? 1 : 0;
    
//   if (backLeft == 0 && backcenter == 0 && backRight == 0)
//   {
//     moveBackward(speed);
//   }
//   else if (backLeft == 1 && backcenter == 0 && backRight == 1)
//   {
//     moveBackward(speed);
//   }
//   else if (backLeft == 0 && backcenter == 1 && backRight == 1)
//   {
//     turnRight90(speed);
//   }
//   else if (backLeft == 1 && backcenter == 1 && backRight == 0)
//   {
//     turnLeft90(speed);
//   }
//   else
//   {
//     moveBackward(speed);
//   }
// }

/////////////
void Backlinefollow(int speed)
{
  // white 1
  // black 0

  int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
  int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
  int backRight = analogRead(back[3]) > 700 ? 1 : 0;

  if (backLeft == 0 && backcenter == 0 && backRight == 0)
  {
    moveBackward(speed);
  }
  else if (backLeft == 1 && backcenter == 0 && backRight == 1)
  {
    moveBackward(speed);
  }
  else if (backLeft == 0 && backcenter == 1 && backRight == 1)
  {
    turnLeft90(speed);
  }
  else if (backLeft == 1 && backcenter == 1 && backRight == 0)
  {
    turnRight90(speed);
  }
  else
  {
    moveBackward(speed);
  }
}
////////


void backlinefollowUntil(int count) {
  int strips_count = 0;

  while (true) {
    // int Mid_l = digitalRead(MID_left) ;
    // int Mid_r = digitalRead(MID_right) ;

  int Mid_r = analogRead(MID_right) > 700 ? 1 : 0;
  int Mid_l = analogRead(MID_left) > 700 ? 1 : 0;

    if (Mid_l==0 && Mid_r==0 && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
     Backlinefollow(80);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}

/////////////
void BacklinefollowWithFive(int speed)
{
  // white 1
  // black 0

  int backLeftmost = analogRead(back[0]) > 700 ? 1 : 0;
  int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
  int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
  int backRight = analogRead(back[3]) > threshold ? 1 : 0;
  int backRightmost = analogRead(back[4]) > threshold ? 1 : 0;

  if (backLeft == 0 && backcenter == 0 && backRight == 0)
  {
    moveBackward(speed);
  }
  else if (backLeft == 1 && backcenter == 0 && backRight == 1)
  {
    moveBackward(speed);
  }
  else if (backLeft == 0 && backcenter == 1 && backRight == 1)
  {
    turnLeft90(speed);
  }
  else if (backLeftmost == 0 && backcenter == 1 && backRight == 1)
  {
    turnLeft90(speed);
  }
  else if (backLeft == 1 && backcenter == 1 && backRight == 0)
  {
    turnRight90(speed);
  }
  else if (backLeft == 1 && backcenter == 1 && backRightmost == 0)
  {
    turnRight90(speed);
  }
  else
  {
    moveBackward(speed);
  }
}





void backlinefollowfiveUntil(int count) {
  int strips_count = 0;

  while (true) {
    // int Mid_l = digitalRead(MID_left) ;
    // int Mid_r = digitalRead(MID_right) ;

  int Mid_r = analogRead(MID_right) > 700 ? 1 : 0;
  int Mid_l = analogRead(MID_left) > 700 ? 1 : 0;

    if (Mid_l==0 && Mid_r==0 && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      BacklinefollowWithFive(80);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}


///////////////
///Ecnoder Functions

void linefollowEncoder(int ticks)
{
  leftEncoderTick = 0;
  while (leftEncoderTick < ticks)
  {
    linefollow(50);
    interrupts();
  }
  stopMotors();
}

void linefollowFiveEncoder(int ticks)
{
  leftEncoderTick = 0;
  while (leftEncoderTick < ticks)
  {
    linefollowWithFive(50);
    interrupts();
  }
  stopMotors();
}

void backLinefollowEncoder(int ticks)
{
  leftEncoderTick = 0;
  while (leftEncoderTick < ticks)
  {
    Backlinefollow(50);
    interrupts();
  }
  stopMotors();
}

void backLinefollowFiveEncoder(int ticks)
{
  leftEncoderTick = 0;
  while (leftEncoderTick < ticks)
  {
    BacklinefollowWithFive(50);
    interrupts();
  }
  stopMotors();
}

#endif // LINE_FOLLOW_H_