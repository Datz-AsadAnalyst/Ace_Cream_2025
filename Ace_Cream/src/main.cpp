#include <Arduino.h>
#include <Motors.h>
#include <Encoder.h>
#include <Line_Follow.h>
#include "Servocontrol.h"
#include "Blue/Blue_Grid9.h"
#define LEFT_ENCODER_PIN 2
#define RIGHT_ENCODER_PIN 3

int strips_count;
bool is_line;

unsigned long previousMillis = 0;
const unsigned long intervalMillis = 200;

// int MID_right = 10;
// int MID_left = 11;
// int front[] = {A5, A6, A7, A9, A8};
// int back[] = {A4, A0, A3, A1, A2};

int frontLeftmost = analogRead(front[0]) > 700 ? 1 : 0;
int frontLeft = analogRead(front[1]) > 700 ? 1 : 0;
int frontcenter = analogRead(front[2]) > 700 ? 1 : 0;
int frontRight = analogRead(front[3]) > threshold ? 1 : 0;
int frontRightmost = analogRead(front[4]) > threshold ? 1 : 0;

int backLeftmost = analogRead(back[0]) > 700 ? 1 : 0;
int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
int backRight = analogRead(back[3]) > threshold ? 1 : 0;
int backRightmost = analogRead(back[4]) > threshold ? 1 : 0;

// void readSensorValsDebugAnalog(int *sensors)
// {
//   for (int i = 0; i < 5; i++)
//   {
//     Serial.print(analogRead(sensors[i]));
//     Serial.print(" ");
//   }
//   Serial.println();
//   delay(100);
// }

void readSensorValsDebugDigital(int *sensors)
{
  int leftmost = analogRead(sensors[0]) > 700 ? 1 : 0;
  int left = analogRead(sensors[1]) > 700 ? 1 : 0;
  int center = analogRead(sensors[2]) > 700 ? 1 : 0;
  int right = analogRead(sensors[3]) > 700 ? 1 : 0;
  int rightmost = analogRead(sensors[4]) > 700 ? 1 : 0;

  Serial.print(leftmost);
  Serial.print("  ");
  Serial.print(left);
  Serial.print("  ");
  Serial.print(center);
  Serial.print("  ");
  Serial.print(right);
  Serial.print("  ");
  Serial.println(rightmost);
  delay(100);
}

// void forwardUntilMiddleSensors()
// {
//   int mid1_val = analogRead(MID1) > 800 ? 1 : 0;
//   int mid2_val = analogRead(MID2) > 800 ? 1 : 0;

//   while (mid1_val == 1 && mid2_val == 1)
//   {
//     forward(50);
//     mid1_val = analogRead(MID1) > 800 ? 1 : 0;
//     mid2_val = analogRead(MID2) > 800 ? 1 : 0;
//   }
//   halt();
// }
void configurePins()
{
  pinMode(LEFT_ENCODER_PIN, INPUT);
  pinMode(RIGHT_ENCODER_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), leftEncoderISR, RISING);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), rightEncoderISR, RISING);

  // Motor pin setup
  pinMode(leftMotorForwardPwm, OUTPUT);
  pinMode(leftMotorBackwardPwm, OUTPUT);
  pinMode(rightMotorForwardPwm, OUTPUT);
  pinMode(rightMotorBackwardPwm, OUTPUT);

  // Sensor pin setup
  pinMode(backLeftmost, INPUT);
  pinMode(backLeft, INPUT);
  pinMode(backcenter, INPUT);
  pinMode(backRight, INPUT);
  pinMode(backRightmost, INPUT);

  pinMode(frontLeftmost, INPUT);
  pinMode(frontLeft, INPUT);
  pinMode(frontcenter, INPUT);
  pinMode(frontRight, INPUT);
  pinMode(frontRightmost, INPUT);
  pinMode(MID_left, INPUT);
  pinMode(MID_right, INPUT);
}

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600);
  configurePins();
//   initServos();
//   all_set();
//   delay(1000);
 
//  blue_grid9();


// backlinefollowfiveUntil(2);

// linefollowFiveUntil(2);

// FrontPick();
// moveleftToZero();
// delay(2000);
// LeftPick();
// delay(2000);
// movefrontToZero();
// delay(2000);
// FrontPick();
// moverightToZero();
// delay(2000);
// RightPick();

////////


set();
     
    //  rightServo.write(66);
  // servoMove(&frontServo, 0, 66);
//   servoMove(&mainServo,0,66);
// servoMove(&rightServo,66,0);
  // blue_grid1();
  // linefollowFiveUntil(4);
  // delay(500);
  // moveLeftEncoder(325,80);
  // backlinefollowfiveUntil(3);
}

void loop()
{
  // readSensorValsDebugDigital(back);

  // put your main code here, to run repeatedly:
  // Serial.print(digitalRead(MID_left));
  // Serial.print(" ");
  // Serial.println(digitalRead(MID_right));

  // Serial.print(" ");
}

// put function definitions here:
