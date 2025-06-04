#include<Encoder.h>
#include<Motors.h>
#include<Line_Follow.h>

#ifndef _BLUE_GRID6_H_
#define _BLUE_GRID6_H_


/*
 * Grid 6: Boxes at (1,1), (1,3), (3,2)
 */
void blue_grid6() {
    // ============ Move to (1,1) ============
    lineFollowUntil(4); // reach vertical intersection
    delay(500);

    moveLeftEncoder(300, 100); // align to column 1
    delay(500);
    linefollowFiveEncoder(50);
    delay(500);

    linefollowFiveUntil(3); // go to row 1
    delay(500);
    moveLeftEncoder(300, 100);
    delay(500);
    linefollowFiveEncoder(50);
    delay(500);
    ///////line until 2
    linefollowFiveUntil(2);
    delay(500);


   /////// pickFromFrontServo(); // pick from (1,1)
    /////delay(1000);

    // ============ Move to (1,3) ============
    moveRightEncoder(600, 100); // move across to (1,3)
    delay(500);
    linefollowFiveEncoder(60);
    delay(500);
    ////line untill 2
    linefollowFiveUntil(2);
    delay(500);
    ////right move 
      

    // pickFromFrontServo(); // pick from (1,3)
    // delay(1000);

    // ============ Move to (3,2) ============
    // First move to row 3
    moveLeftEncoder(300, 100); // to column 2
    delay(500);
    linefollowFiveEncoder(30);
    delay(500);
/////////// move back
  backlinefollowfiveUntil(2);
  delay(500);

    linefollowFiveUntil(3); // move downward to row 3
    delay(500);
    moveLeftEncoder(300, 100);
    delay(500);
    linefollowFiveUntil(2);
    delay(500);

    // pickFromFrontServo(); // pick from (3,2)
    // delay(1000);

    // ============ Move to Drop Station 1 ============
    // Backtrack vertically
    backlinefollowfiveUntil(5);
    delay(500);
    backLinefollowFiveEncoder(30);
    delay(500);

    ////////
    linefollowEncoder(30);
    // Go left to rejoin horizontal black line
    moveLeftEncoder(300, 100);
    delay(500);
    linefollowFiveEncoder(60);
    delay(500);
    linefollowFiveUntil(4); // main line
    delay(500);

    moveLeftEncoder(300, 100);
    delay(500);
    linefollowFiveEncoder(100);
    delay(500);

    // dropRedBox(); // first drop
    // delay(500);

    // ============ Drop other boxes at Station 2 ============
    backlinefollowfiveUntil(2);
    delay(500);
    moveRightEncoder(300, 100);
    delay(500);
    moveForwardEncoder(600, 100);
    delay(500);

    // dropOtherBoxes(); // second and third drop
    // delay(500);

    // ============ Parking ============
    moveBackwardEncoder(500, 100);
    moveLeftEncoder(300, 100);
}

#endif // _BLUE_GRID6_H_