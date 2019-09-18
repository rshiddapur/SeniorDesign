/**
 * This file is the overall hierarchy for our project code. 
 */

// Library for controlling the hobby servo
#include <Servo.h>

// Configuration
// Period of the loop, in ms
#define LoopTime 100
long prevMillis; // used to time loop()

/**
 * waitForTick() blocks until a periodic time based on the global millis() time,
 * which can be used to force loop() to run at a predictable rate (as long as
 * the code in loop() is faster than the tick time).
 * This may or may not be desirable for your code, but it usually is.
 */
void waitForTick()
{
    // block until the specified time
    while ((millis() - prevMillis) <= LoopTime)
        ;
    prevMillis = millis();
    return;
}

void setup() {

    //initialize();
    // Example of reading the ultrasonic rangefinder and printing to
    // the serial port.

    // Macros to read the three line tracking sensors.
// These will return '0' with a light surface and '1'
// with a dark surface.
#define LT_R !digitalRead(10)
#define LT_M !digitalRead(4)
#define LT_L !digitalRead(2)

    // record the current time for the timing function
    prevMillis = millis();

    Serial.println("Initialization complete");
}

void loop () {
    // calling waitForTick() at the beginning of loop will keep it periodic
    //waitForTick();

    // Example of reading the ultrasonic rangefinder and printing to
    // the serial port.
    // Note that readDistance() is blocking, meaning that it will prevent
    // any other code from executing until it returns.  This will
    // take a variable amount of time, up to ~10 ms.
    //Serial.println(readDistance());

    followLine();
    station();
}


