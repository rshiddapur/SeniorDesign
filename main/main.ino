/**
 * This file is the overall hierarchy for our project code. 
 */

// Library for controlling the hobby servo
#include <Servo.h>

// Configuration
// Period of the loop, in ms
#define LoopTime 100

void setup() {

    initialize();
    // Example of reading the ultrasonic rangefinder and printing to
    // the serial port.
    Serial.println("Initialization complete");
}

void loop () {
    // followLine();
    // station();
}
