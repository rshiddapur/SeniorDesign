// Library for controlling the hobby servo
#include <Servo.h>
// Ultrasonic rangefinder pin connections
#define Echo A4
#define Trig A5

// Servo pins
#define ServoPin 3


void station() {
    delay (2000);
    servoTest();
    while (onStation())
    {
        motor('S', 1);
    }
}


void servoTest() {
    pinMode(ServoPin, OUTPUT);

    // Attach the servo controller to the servo pin
    head.attach(ServoPin);

    // Set the head looking to the side.
    head.write(0);
    delay(2000);
    // and to the middle
    head.write(90);
    delay(1000);
}