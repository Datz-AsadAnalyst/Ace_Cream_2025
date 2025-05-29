#include <Arduino.h>
#include<Motors.h>
#ifndef ENCODER_H_
#define ENCODER_H_

// Encoder Motor Pins
// #define LEFT_ENCODER_PIN 2
// #define RIGHT_ENCODER_PIN 3

// Encoder Tick Counters
volatile int rightEncoderTick = 0;
volatile int leftEncoderTick = 0;

// Encoder Interrupts
void rightEncoderISR() {
  rightEncoderTick++;
}

void leftEncoderISR() {
  leftEncoderTick++;
}

// Encoder Movement Functions
void moveForwardEncoder(int targetTicks, int speed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

  moveForward(speed);

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Left Ticks: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right Ticks: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}

void moveBackwardEncoder(int targetTicks, int speed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

  moveBackward(speed);

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Reverse -> Left: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}

void moveLeftEncoder(int targetTicks, int left_speed,int right_speed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

  turnLeft90(left_speed,right_speed);

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Left Turn -> Left: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}

void moveRightEncoder(int targetTicks, int left_speed,int right_speed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

  turnRight90(left_speed,right_speed);

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Right Turn -> Left: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}

void softLeftEncoder(int targetTicks, int leftSpeed, int rightSpeed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

 softLeft();

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Soft Left -> Left: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}

void softRightEncoder(int targetTicks, int leftSpeed, int rightSpeed) {
  leftEncoderTick = 0;
  rightEncoderTick = 0;

  analogWrite(leftMotorForwardPwm, leftSpeed);   // Fast left motor
  analogWrite(leftMotorBackwardPwm, 0);
  analogWrite(rightMotorForwardPwm, rightSpeed); // Slow right motor
  analogWrite(rightMotorBackwardPwm, 0);

  while (leftEncoderTick < targetTicks && rightEncoderTick < targetTicks) {
    Serial.print("Soft Right -> Left: ");
    Serial.print(leftEncoderTick);
    Serial.print(" | Right: ");
    Serial.println(rightEncoderTick);
  }

  stopMotors();
}





#endif // ENCODER_H_