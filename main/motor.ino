/**
 * This file provides motor control for other
 * actions to move the robot.
 */


// Motor driver pin connections
// #define ENB 5  // left motor enable
//#define IN1 7  // left motor control
//#define IN2 8  // left motor control
//#define ENA 6  // right motor enable
//#define IN3 9  // right motor control
//#define IN4 11 // right motor control

    void motor()
    {
        // Configure the pins that are outputs
//        pinMode(Trig, OUTPUT);
//        pinMode(IN1, OUTPUT);
//        pinMode(IN2, OUTPUT);
//        pinMode(IN3, OUTPUT);
//        pinMode(IN4, OUTPUT);
//        pinMode(ENA, OUTPUT);
//        pinMode(ENB, OUTPUT);
//        pinMode(ServoPin, OUTPUT);

        // test the left motors
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        analogWrite(ENB, 128);
        delay(2000);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        analogWrite(ENB, 0);
        delay(1000);

        // test the right motors
        digitalWrite(IN4, LOW);
        digitalWrite(IN3, HIGH);
        analogWrite(ENA, 128);
        delay(2000);
        digitalWrite(IN4, LOW);
        digitalWrite(IN3, LOW);
        analogWrite(ENA, 0);
        delay(1000);
    }

