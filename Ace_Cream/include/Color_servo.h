#ifndef _Color_Servo_H_
#define _Color_Servo_H_


#include <Servo.h>
#include <Arduino.h>
#include<Line_Follow.h>

// =================== Servo Declarations ===================
Servo mainServo;
Servo rightServo;
Servo leftServo;
Servo frontServo;

// =================== Servo Pin Configuration ===================
int mainServoPin = 47;
int frontServoPin = 53;
int leftServoPin = 49;
int rightServoPin = 51;

/////////////////////////

int angle0=140;
int angle90=77;
int angle180=15;
// =================== Servo Position State ===================
int main_servo_current_position = 130;
bool servo1_got_box = false;
bool servo2_got_box = false;
bool servo3_got_box = false;

// =================== Color Sensor Pins ===================
#define SENSOR_1_PIN 45  // Left side color sensor
#define SENSOR_2_PIN 43  // Right side color sensor

// =================== Red Color Range (Adjust as needed) ===================
#define RED_MIN 10
#define RED_MAX 30

// =================== Setup Color Sensor Pins ===================
void setupColorSensors() {
  pinMode(SENSOR_1_PIN, INPUT);
  pinMode(SENSOR_2_PIN, INPUT);
}

// =================== Read Color Sensor ===================
int readCSensor(int sensorPin) {
  delay(200);  // Allow sensor to stabilize
  return pulseIn(sensorPin, LOW);  // Read pulse for color intensity
}

// =================== Initialize Servos ===================
void initServos() {
  mainServo.attach(mainServoPin);
  rightServo.attach(rightServoPin);
  leftServo.attach(leftServoPin);
  frontServo.attach(frontServoPin);
}

// =================== Smooth Servo Movement ===================
void servoMove(Servo *servo, int start, int end) {
  if (start > end) {
    for (int i = start; i >= end; i--) {
      servo->write(i);
      delay(15);
    }
  } else {
    for (int i = start; i <= end; i++) {
      servo->write(i);
      delay(15);
    }
  }
}

// =================== Move Servo1 ===================
void Servo1Move(int down, int up) {
  servoMove(&rightServo, 0, down);   // Move down to drop
  delay(300);
  servoMove(&rightServo, down, up);  // Lift up
  delay(300);
}

void all_set(){
  mainServo.attach(mainServoPin);
  frontServo.attach(frontServoPin);
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);


 
    mainServo.write(angle0);  
  delay(1000);
 
  frontServo.write(80); 
   delay(300);      // Neutral position
  leftServo.write(80);    
   delay(300);    // Neutral
  rightServo.write(80);  
   delay(1000);     // Neutral
   

}


// =================== Move Servo2 ===================
void Servo2Move(int down, int up) {
  servoMove(&leftServo, 0, down);
  delay(300);
  servoMove(&leftServo, down, up);
  delay(300);
}

// =================== Move Servo3 ===================
void Servo3Move(int down, int up) {
  servoMove(&frontServo, 0, down);
  delay(300);
  servoMove(&frontServo, down, up);
  delay(300);
}

// =================== Move Main Servo ===================
void mainServoMove(int from, int to) {
  servoMove(&mainServo, from, to);
}



// =================== Main Red Box Handling Logic ===================
void RedColorBox(int ticks_of_encoder) {
  int frontSensor = readCSensor(SENSOR_1_PIN);  // front
  int leftSensor = readCSensor(SENSOR_2_PIN);   // left

  Serial.print("Front Sensor: "); Serial.print(frontSensor);
  Serial.print(" | Left Sensor: "); Serial.println(leftSensor);

  if (leftSensor >= RED_MIN && leftSensor <= RED_MAX) {
    // RED detected at LEFT sensor --> Use LEFT SERVO (comes in front at 0 deg)
    // mainServoMove(main_servo_current_position, angle0);
    servoMove(&mainServo,angle180,angle0);
    delay(2000);
    // servoMove(&leftServo,70, angle0);  // LEFT SERVO
    leftServo.write(0);
    delay(2000);
    linefollowFiveEncoder(ticks_of_encoder);
    delay(2000);
  
    main_servo_current_position = angle0;
    servo1_got_box = false;

  } else if (frontSensor >= RED_MIN && frontSensor <= RED_MAX) {
    // RED detected at FRONT sensor --> Use FRONT SERVO (at 90 deg)
    mainServoMove(main_servo_current_position, angle90);
    // servoMove(&frontServo,70,angle0);  // FRONT SERVO
    frontServo.write(0);
    delay(500);
    linefollowEncoder(ticks_of_encoder);
    delay(500);
    main_servo_current_position = angle90;
    servo3_got_box = false;

  } else {
    // No detection --> Move to RIGHT position (180 deg) and try
    mainServoMove(main_servo_current_position, angle180);
    // servoMove(&rightServo,70, angle0);  // RIGHT SERVO
    rightServo.write(0);
    delay(500);
    linefollowEncoder(ticks_of_encoder);
    delay(500);
   
    main_servo_current_position = angle180;
    servo2_got_box = false;
  }
}

void remain(){
if(main_servo_current_position== 0){

  backLinefollowFiveEncoder(10); 
  delay(500);
rightServo.write(90);
backLinefollowFiveEncoder(40);
delay(500);
 servoMove(&rightServo,0,66);
 delay(500);
   ;
    //////
    linefollowFiveEncoder(20);
delay(500);
    ///line follow
    moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(60);
delay(500);
/////// line untill 4
linefollowFiveUntil(4);
delay(500);
    ///move 90
    servoMove(&mainServo,0,66);
    moveLeftEncoder(300,100);
delay(500);
    ////drop front
   servoMove(&frontServo,angle90,angle0);
} else if(main_servo_current_position==90){

///line follow

  backLinefollowFiveEncoder(10); 
  delay(500);
  servoMove(&mainServo,angle90,angle180);
  delay(500);
leftServo.write(90);
backLinefollowFiveEncoder(20);
delay(500);
 servoMove(&leftServo,0,66);
 delay(500);
////move 180 


///line follow
linefollowFiveEncoder(20);
delay(500);
    ///line follow
    moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(60);
delay(500);
/////// line untill 4
linefollowFiveUntil(4);
delay(500);
moveLeftEncoder(300,100);
delay(500);
///drop right
servoMove(&frontServo,angle90,angle0);
}
else {

  
    //line follow
  
  backLinefollowFiveEncoder(10); 
    delay(500);
leftServo.write(90);
backLinefollowFiveEncoder(20);
delay(500);
 servoMove(&leftServo,angle90,angle0);
 delay(500);
    /// drop right
  ;
    //////
    linefollowFiveEncoder(20);
delay(500);
    ///line follow
    moveLeftEncoder(300,100);
delay(500);
linefollowFiveEncoder(60);
delay(500);
/////// line untill 4
linefollowFiveUntil(4);
delay(500);
    ///move 90
    servoMove(&mainServo,0,0);
    delay(500);
     servoMove(&mainServo,0,66);
     delay(500);
     moveLeftEncoder(300,100);
delay(500);
    ////drop front
   servoMove(&frontServo,angle90,angle0);
    ///line follow
    ////drop left
    ////line follow
    //move zero kar ke move 90
    //////drop
}

}




#endif // _Color_Servo_H_
