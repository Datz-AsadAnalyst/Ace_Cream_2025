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

int MID_right = 10;
int MID_left = 11;


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
    turnLeft90(25,50);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRight == 0)
  {
    turnRight90(50,25);
  }
  else
  {
    moveForward(speed);
  }
}

void lineFollowUntil(int count) {
  int strips_count = 0;

  while (true) {
    int Mid_l = digitalRead(MID_left) ;

    if (Mid_l == 1 && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      linefollow(50);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}

///////////
// void linefollowUntil(int strips)
// {
//   while (true)
//   {
//     int Mid_r = digitalRead(MID_left) ;
//     unsigned long currentMillis = millis();

//     if (Mid_r == 1 && !is_line)
//     {
//       strips_count++;
//       is_line = true;
//       previousMillis = currentMillis;
//     }
//     else if (currentMillis - previousMillis > intervalMillis)
//     {
//       is_line = false;
//     }

//     if (strips_count < strips)
//     {
//       linefollow(50);
//       Serial.print("hello: ");
//       Serial.println(strips_count);
//     }
//     else
//     {
//       stopMotors();
//       strips_count = 0;
//       return;
//     }
//   }
// }

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
    turnLeft90(25,50);
  }
  else if (frontLeftmost == 0 && frontcenter == 1 && frontRight == 1)
  {
    turnLeft90(25,50);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRight == 0)
  {
    turnRight90(50,25);
  }
  else if (frontLeft == 1 && frontcenter == 1 && frontRightmost == 0)
  {
    turnRight90(50,25);
  }
  else
  {
    moveForward(speed);
  }
}

void linefollowFiveUntil(int count) {
  int strips_count = 0;

  while (true) {
    int frontLeftmost = analogRead(front[0]) > 700 ? 1 : 0;
  int frontLeft = analogRead(front[1]) > 700 ? 1 : 0;
  int frontcenter = analogRead(front[2]) > 700 ? 1 : 0;
    int frontRight = analogRead(front[3]) > threshold ? 1 : 0;
    int frontRightmost = analogRead(front[4]) > threshold ? 1 : 0;

    if (!frontLeftmost && !frontLeft && !frontcenter && !frontRight && !frontRightmost && !is_line) {
      strips_count++;
      is_line = true;
      previousMillis = millis();
    } else if (millis() - previousMillis > intervalMillis && is_line) {
      is_line = false;
    }

    if (strips_count < count) {
      linefollowWithFive(50);
      Serial.print("Strips: ");
      Serial.println(strips_count);
    } else {

      stopMotors();
      return;
    }
  }
}

// void linefollowFiveUntil(int strips)
// {
//   while (true)
//   {
//     int Mid_r = digitalRead(MID_left) ;
//     unsigned long currentMillis = millis();

//     if (Mid_r == 1 && !is_line)
//     {
//       strips_count++;
//       is_line = true;
//       previousMillis = currentMillis;
//     }
//     else if (currentMillis - previousMillis > intervalMillis)
//     {
//       is_line = false;
//     }

//     if (strips_count < strips)
//     {
//       linefollowWithFive(50);
//       Serial.print("hello: ");
//       Serial.println(strips_count);
//     }
//     else
//     {
//       stopMotors();
//       strips_count = 0;
//       return;
//     }
//   }
// }
void backLinefollow(int speed)
{
  // white 1
  // black 0

  int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
  int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
    int backRight = analogRead(back[3]) > threshold ? 1 : 0;
    
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
    turnRight90(25,50);
  }
  else if (backLeft == 1 && backcenter == 1 && backRight == 0)
  {
    turnLeft90(50,25);
  }
  else
  {
    moveBackward(speed);
  }
}


// void BacklineFollowUntil(int count) {
//   int strips_count = 0;

//   while (true) {
//     int backLeftmost = analogRead(back[0]) > 700 ? 1 : 0;
//   int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
//   int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
//     int backRight = analogRead(back[3]) > threshold ? 1 : 0;
//     int backRightmost = analogRead(back[4]) > threshold ? 1 : 0;

//     if (!backLeftmost && !backLeft && !backcenter && !backRight && !backRightmost && !is_line) {
//       strips_count++;
//       is_line = true;
//       previousMillis = millis();
//     } else if (millis() - previousMillis > intervalMillis && is_line) {
//       is_line = false;
//     }

//     if (strips_count < count) {
//       backLinefollow(50);
//       Serial.print("Strips: ");
//       Serial.println(strips_count);
//     } else {

//       stopMotors();
//       return;
//     }
//   }
// }

void BacklineFollowUntil(int strips)
{
  while (true)
  {
    int Mid_r = digitalRead(MID_right) ;
    unsigned long currentMillis = millis();

    if (Mid_r == 1 && !is_line)
    {
      strips_count++;
      is_line = true;
      previousMillis = currentMillis;
    }
    else if (currentMillis - previousMillis > intervalMillis)
    {
      is_line = false;
    }

    if (strips_count < strips)
    {
      backLinefollow(50);
      Serial.print("hello: ");
      Serial.println(strips_count);
    }
    else
    {
      stopMotors();
      strips_count = 0;
      return;
    }
  }
}

void backLinefollowWithFive(int speed)
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
    turnRight90(25,50);
  }
  else if (backLeftmost == 0 && backcenter == 1 && backRight == 1)
  {
    turnRight90(25,50);
  }
  else if (backLeft == 1 && backcenter == 1 && backRight == 0)
  {
    turnLeft90(50,25);
  }
  else if (backLeft == 1 && backcenter == 1 && backRightmost == 0)
  {
   turnLeft90(50,25);
  }
  else
  {
    moveBackward(speed);
  }
}


// void backLinefollowFiveUntil(int count) {
//   int strips_count = 0;

//   while (true) {
//     int backLeftmost = analogRead(back[0]) > 700 ? 1 : 0;
//   int backLeft = analogRead(back[1]) > 700 ? 1 : 0;
//   int backcenter = analogRead(back[2]) > 700 ? 1 : 0;
//     int backRight = analogRead(back[3]) > threshold ? 1 : 0;
//     int backRightmost = analogRead(back[4]) > threshold ? 1 : 0;

//     if (!backLeftmost && !backLeft && !backcenter && !backRight && !backRightmost && !is_line) {
//       strips_count++;
//       is_line = true;
//       previousMillis = millis();
//     } else if (millis() - previousMillis > intervalMillis && is_line) {
//       is_line = false;
//     }

//     if (strips_count < count) {
//       backLinefollowWithFive(50);
//       Serial.print("Strips: ");
//       Serial.println(strips_count);
//     } else {

//       stopMotors();
//       return;
//     }
//   }
// }

void backlinefollowFiveUntil(int strips)
{
  while (true)
  {
    int Mid_r = digitalRead(MID_right) ;
    unsigned long currentMillis = millis();

    if (Mid_r == 1 && !is_line)
    {
      strips_count++;
      is_line = true;
      previousMillis = currentMillis;
    }
    else if (currentMillis - previousMillis > intervalMillis)
    {
      is_line = false;
    }

    if (strips_count < strips)
    {
      backLinefollowWithFive(50);
      Serial.print("hello: ");
      Serial.println(strips_count);
    }
    else
    {
      stopMotors();
      strips_count = 0;
      return;
    }
  }
}
// //////Front
// void lineFollow() {
//   int frontLM = analogRead(frontLeftMost) > threshold ? 1 : 0;
//   int frontL = analogRead(frontLeft) > threshold ? 1 : 0;
//   int frontC = analogRead(frontMiddle) > threshold ? 1 : 0;
//   int frontR = analogRead(frontRight) > threshold ? 1 : 0;
//   int frontRM = analogRead(frontRightMost) > threshold ? 1 : 0;

// // int sensors[] = {
// //     analogRead(frontLeftMost) > threshold,
// //     analogRead(frontLeft) > threshold,
// //     analogRead(frontMiddle) > threshold,
// //     analogRead(frontRight) > threshold,
// //     analogRead(frontRightMost) > threshold
// //   }; // **Compressed sensor reading using array**


// //    if (sensors[1] == 1 && sensors[2] == 0 && sensors[3] == 1) {
// //     moveForward(60);
// //   } else if ((sensors[1] == 0 && sensors[2] == 0 && sensors[3] == 1) ||
// //              (sensors[1] == 0 && sensors[2] == 1 && sensors[3] == 1)) {
// //     turnLeft(60);
// //   } else if ((sensors[1] == 1 && sensors[2] == 0 && sensors[3] == 0) ||
// //              (sensors[1] == 1 && sensors[2] == 1 && sensors[3] == 0)) {
// //     turnRight(60);
// //   }

//   if (frontL == 0 && frontC == 0 && frontR == 0) {
//     moveForward(50);
//   } else if (frontL == 1 && frontC == 0 && frontR == 1) {
//     moveForward(50);
//   } else if (frontL == 0 && frontC == 0 && frontR == 1) {
//     turnLeft90(25);
//   } else if (frontL == 0 && frontC == 1 && frontR == 1) {
//     turnLeft90(25);
//   } else if (frontL == 1 && frontC == 0 && frontR == 0) {
//     turnRight90(25);
//   } else if (frontL == 1 && frontC == 1 && frontR == 0) {
//     turnRight90(25);
//       }
//     }
// void linefollowUntil(int strips);
//   // // 00111
//   else if (!frontLM && !frontL && frontC && frontR && frontRM) {
//     turnLeft();
//     readFrontSensors();
//     Serial.print("6th");
//   }
//   // 01111
//   else if (!frontLM && frontL && frontC && frontR && frontRM) {
//     turnLeft();
//     readFrontSensors();
//     Serial.print("7th");
//   }
//   // 10111
//   else if (frontLM && !frontL && frontC && frontR && frontRM) {
//     turnLeft();
//     readFrontSensors();
//     Serial.print("8th");
//   }
//   // 11100
//   else if (frontLM && frontL && frontC && !frontR && !frontRM) {
//     turnRight();
//     readFrontSensors();
//     Serial.print("9th");
//   }
//   // 11110
//   else if (frontLM && frontL && frontC && frontR && !frontRM) {
//     turnRight();
//     readFrontSensors();
//     Serial.print("10th");
//   }
//   // 11101
//   else if (frontLM && frontL && frontC && !frontR && frontRM) {
//     turnRight();
//     readFrontSensors();
//     Serial.print("11th");
//   }
// }


#endif // LINE_FOLLOW_H_