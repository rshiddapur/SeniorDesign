/**
 * This file provides a quick sanity check that
 * the robot is working.
 */

// Library for controlling the hobby servo
#include <Servo.h>


// Motor driver pin connections
#define ENB 5  // left motor enable
#define IN1 7  // left motor control
#define IN2 8  // left motor control
#define ENA 6  // right motor enable
#define IN3 9  // right motor control
#define IN4 11 // right motor control

// Ultrasonic rangefinder pin connections
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

// global variables
Servo head; // create servo object to control the looking direction

     void initialize()
    {
        // Start serial comm in case you want to debug with it
        Serial.begin(9600);

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

        // Set the head looking to the side.
        head.write(0);
        delay(2000);
        // Set the head looking to the other side.
        head.write(180);
        delay(2000);
        // and to the middle
        head.write(90);
        delay(1000);

        getDistance();
        
        // do a little dance
        // test turning forward left
        motor('L',1);
        // test turning backward left
        motor('l',2);
        // test turning forward left
        motor('L',1);
        // test turning forward right
        motor('R',1);
        // test turning backward right
        motor('r',2);
        // test turning forward right
        motor('R',1);
        // test moving straight forward
        motor('S',1);
        // test moving straight backward
        motor('s',2);
        // test moving straight forward
        motor('S',1);
        // test turning clockwise (to the right)
        motor('C',7);
        // test turning counter-clockwise (to the left)
        motor('c',14);
        // test turning clockwise (to the right)
        motor('C',8);
    }

