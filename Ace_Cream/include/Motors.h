#include <Arduino.h>

#ifndef MOTORS_H_
#define MOTORS_H_

// PWM Motor Pins
int leftMotorForwardPwm = 6;
int leftMotorBackwardPwm = 7;
int rightMotorForwardPwm = 5;
int rightMotorBackwardPwm = 4;

// -----------------------------
// Basic Movement Functions
// Move forward
void moveForward(int speed) {
  analogWrite(leftMotorForwardPwm, speed);
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, speed);
  analogWrite(rightMotorBackwardPwm, 0);
}

// Move backward
void moveBackward(int speed) {
  analogWrite(leftMotorForwardPwm, 0);
  analogWrite(leftMotorBackwardPwm, speed);
  analogWrite(rightMotorForwardPwm, 0);
  analogWrite(rightMotorBackwardPwm, speed);
}





// Turn 90 degrees right (in place)
void turnRight90(int speed) {
  analogWrite(leftMotorForwardPwm, speed);
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, 0);
  analogWrite(rightMotorBackwardPwm, speed);
}

// Turn 90 degrees left (in place)
void turnLeft90(int speed) {
  analogWrite(leftMotorForwardPwm, 0);
  analogWrite(leftMotorBackwardPwm, speed);
  analogWrite(rightMotorForwardPwm, speed);
  analogWrite(rightMotorBackwardPwm, 0);
}

// Turn 90 degrees right (in place)
void turnRight(int speed) {
  analogWrite(leftMotorForwardPwm, speed);
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, 0);
  analogWrite(rightMotorBackwardPwm, 0);
}

// Turn 90 degrees left (in place)
void turnLeft(int speed) {
  analogWrite(leftMotorForwardPwm, 0);
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, speed);
  analogWrite(rightMotorBackwardPwm, 0);
}





// Stop both motors
void stopMotors() {
  analogWrite(leftMotorForwardPwm, 0);
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, 0);
  analogWrite(rightMotorBackwardPwm, 0);
}


#endif // MOTORS_H_