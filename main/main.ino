/**
 * This file is the point of entry for our project code. 
 * Arduino will first run setup() once to initialize all hardware, and then will call loop() to run the robot through its normal steps.
 * loop() invokes followLine() and station(). 
 */

// Global definitions
#include <Servo.h> // Library for controlling the hobby servo

// Variables
#define LoopTime 100 // Period of the loop, in ms
long prevMillis; // used to time loop() in followline()
Servo head; // create servo object to control the looking direction

void setup() {  
    //initialize(); // Test all hardware
    // Hardware definitions
    // Motor driver pins
    #define ENB 5  // left motor enable
    #define IN1 7  // left motor control
    #define IN2 8  // left motor control
    #define ENA 6  // right motor enable
    #define IN3 9  // right motor control
    #define IN4 11 // right motor control

    // Ultrasonic rangefinder pins
    #define Echo A4
    #define Trig A5

    // Servo pins
    #define ServoPin 3

    // Macros to read the three line tracking sensors.
    // These will return '0' with a light surface and '1'
    // with a dark surface.
    #define LT_R !digitalRead(10)
    #define LT_M !digitalRead(4)
    #define LT_L !digitalRead(2)

    // Configure the pins that are outputs
    pinMode(Trig, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(ServoPin, OUTPUT);

    // Attach the servo controller to the servo pin
    head.attach(ServoPin);

    // record the current time for the timing function
    prevMillis = millis();

}

void loop () {
    // calling waitForTick() at the beginning of loop will keep it periodic
    //waitForTick();

    followLine();
    station();
}

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
