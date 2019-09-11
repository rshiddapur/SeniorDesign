/**
 * This file is the overall hierarchy for our project code. 
 */

// Library for controlling the hobby servo
#include <Servo.h>

void setup() {

    initialize();
    // Example of reading the ultrasonic rangefinder and printing to
    // the serial port.
    Serial.println("Initialization complete");
    motor('S',1);
    delay(1000);
    motor('s',10);
    delay(1000);
    motor('S',20);
}

void loop () {
    // followLine();
    // station();
}
