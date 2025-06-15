#ifndef _SERVOCONTROL_H_
#define _SERVOCONTROL_H_

#include <Servo.h>
#include <Arduino.h>
#include<Line_Follow.h>

Servo mainServo;
Servo rightServo;
Servo leftServo;
Servo frontServo;

// int mainServoPin = 49;
// int frontServoPin = 47;
// int leftServoPin = 43;
// int rightServoPin = 45;

int mainServoPin = 47;
int frontServoPin = 53;
int leftServoPin = 51;
int rightServoPin = 49;

// Color Sensor Pins
// int FrontColor = 7;
// int LeftColor  = 8;
// int RightColor = 10;

// // Color threshold
// int colorthreshold = 30;  // Adjust as per your sensor

// // Color frequency readings
// unsigned long frontRedFreq;
// unsigned long leftRedFreq;
// unsigned long rightRedFreq;

void initServos()
{
  mainServo.attach(mainServoPin);
  rightServo.attach(frontServoPin);
  leftServo.attach(leftServoPin);
  frontServo.attach(rightServoPin);
}
void all_set(){
  mainServo.attach(mainServoPin);
  frontServo.attach(frontServoPin);
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);

  mainServo.write(6);       // Start at 0 degrees
  frontServo.write(66);     // Neutral position
  leftServo.write(66);      // Neutral
  rightServo.write(66);     // Neutral
  delay(1000);

}

// Move MainServo to 0°
void moveMainToZero() {
mainServo.attach(mainServoPin);
  mainServo.write(2);
}

// Move MainServo to 90°
void moveMainToNinety() {
  mainServo.attach(mainServoPin);
  mainServo.write(66);
}

// Move MainServo to 180°
void moveMainToOneEighty() {
  mainServo.attach(mainServoPin);
  mainServo.write(128);
}
///////////main done/////////////

// ------------------- Front Servo Functions -------------------
void movefrontToZero() {
frontServo.attach(frontServoPin);
  frontServo.write(6);
}

void FrontPick() {

  frontServo.attach(frontServoPin);
  for (int pos = 0; pos <= 70; pos++) {
    frontServo.write(pos);
    delay(15);
  }
}

void FrontPickRed() {
  frontServo.attach(frontServoPin);
  for (int pos = 70; pos >= 30; pos--) {
    frontServo.write(pos);
    delay(15);
  }
}

void FrontPlace70() {
  frontServo.attach(frontServoPin);
  for (int pos = 70; pos >= 0; pos--) {
    frontServo.write(pos);
    delay(15);
  }
}

void FrontPlace30() {
  frontServo.attach(frontServoPin);
  for (int pos = 30; pos >= 0; pos--) {
    frontServo.write(pos);
    delay(15);
  }
}

// ------------------- Left Servo Functions -------------------
void moveleftToZero() {
leftServo.attach(leftServoPin);
  leftServo.write(6);
}

void LeftPick() {

  leftServo.attach(leftServoPin);
  for (int pos = 0; pos <= 70; pos++) {
    leftServo.write(pos);
    delay(15);
  }
}

void LeftPickRed() {
  leftServo.attach(leftServoPin);
  for (int pos = 70; pos >= 30; pos--) {
    leftServo.write(pos);
    delay(15);
  }
}

void LeftPlace70() {
  leftServo.attach(leftServoPin);
  for (int pos = 90; pos >= 0; pos--) {
    leftServo.write(pos);
    delay(15);
  }
}

void LeftPlace30() {
  leftServo.attach(leftServoPin);
  for (int pos = 30; pos >= 0; pos--) {
    leftServo.write(pos);
    delay(15);
  }
}

// ------------------- Right Servo Functions -------------------

void moverightToZero() {
rightServo.attach(rightServoPin);
  rightServo.write(6);
}

void RightPick() {
  rightServo.attach(rightServoPin);
  for (int pos = 0; pos <= 70; pos++) {
    rightServo.write(pos);
    delay(15);
  }
}

void RightPickRed() {
  rightServo.attach(rightServoPin);
  for (int pos = 70; pos >= 30; pos--) {
    rightServo.write(pos);
    delay(15);
  }
}

void RightPlace70() {
  rightServo.attach(rightServoPin);
  for (int pos = 70; pos >= 0; pos--) {
    rightServo.write(pos);
    delay(15);
  }
}

void RightPlace30() {
  rightServo.attach(rightServoPin);
  for (int pos = 30; pos >= 0; pos--) {
    rightServo.write(pos);
    delay(15);
  }
}

//////////////kkkkkkkkkkkkkkkkkkkkkk
// ------------------- Color Detection Function -------------------

// void detectColor() {
//   frontRedFreq = pulseIn(FrontColor, LOW);
//   leftRedFreq  = pulseIn(LeftColor, LOW);
//   rightRedFreq = pulseIn(RightColor, LOW);

//   if (frontRedFreq < colorthreshold) {
//     FrontPosition();
//     delay(500);
//     FrontPickRed();  // pick from red position
//   }
//   else if (leftRedFreq < colorthreshold) {
//     LeftPosition();
//     delay(500);
//     LeftPickRed();   // pick from red position
//   }
//   else if (rightRedFreq < colorthreshold) {
//     RightPosition();
//     delay(500);
//     RightPickRed();  // pick from red position
//   }
// }









void servoMove(Servo *servo, int start, int end)
{
  if (start > end)
  {
    for (int i = start; i > end; i--)
    {
      servo->write(i);
      delay(15);
    }
  }
  else
  {
    Serial.print("i am in else");

    for (int i = start; i < end; i++)
    {
      servo->write(i);
      delay(15);
    }
  }
}

void set(){
  
  // int frontLeft = analogRead(front[1]) > 700 ? 1 : 0;
  int frontcenter = analogRead(front[2]) > 700 ? 1 : 0;
  // int frontRight = analogRead(front[3]) > 700 ? 1 : 0;
  while(true){
 if(!frontcenter==0 ){
  Serial.print("whilee");
  // BacklinefollowWithFive(50);
 }
 else {
  Serial.print("ggggg");
  // stopMotors();
 }
  }

}

#endif // _SERVOCONTROL_H_