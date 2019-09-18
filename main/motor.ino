/**
 * This file provides motor control for other
 * actions to move the robot.
 */


// Motor driver pin connections set in initialize() as:
//#define ENB 5  // left motor enable
//#define IN1 7  // left motor control
//#define IN2 8  // left motor control
//#define ENA 6  // right motor enable
//#define IN3 9  // right motor control
//#define IN4 11 // right motor control

    void motor(  char direction, int numTicks )
    {
    // set default motor run time to 1/10 second (orig. value was 2000)
    int runTime = 8;

    // set default motor delay time to 1/100 second (orig. value was 1000)
    int delayTime =10;

    // adjust right motor runTime to account for motor differences
    int rightMotorFactor = 1.25; 

    int roll;
    for ( roll = 0; roll < numTicks; roll++) {

        switch (direction)
            {
            case 'S':
                // move the robot straight by enabling left and right motors
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, HIGH);
                analogWrite(ENB, 100);
                analogWrite(ENA, 100);
                delay(runTime * 3.5);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 0);
                analogWrite(ENA, 0);
                delay(delayTime/5);
                break;
            
            case 's':
                // move the robot backwards straight 
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, HIGH);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 64);
                analogWrite(ENA, 64);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 0);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;

            case 'R':
                // move the robot forward to the right 
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, HIGH);
                analogWrite(ENA, 200);
                delay(runTime);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;

            case 'r':
                // move the robot backwards to the right 
                digitalWrite(IN4, HIGH);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 200);
                delay(runTime);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;

            case 'L':
                // move the robot forward to the left 
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                analogWrite(ENB, 200);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 0);
                delay(delayTime);
                break;

            case 'l':
                // move the robot backwards to the left 
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 200);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 0);
                delay(delayTime);
                break;

            case 'C':
                // turn the robot clockwise
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, HIGH);
                analogWrite(ENB, 255);
                analogWrite(ENA, 255);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 0);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;
            
            case 'c':
                // turn the robot counter-clockwise
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                digitalWrite(IN4, HIGH);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 255);
                analogWrite(ENA, 255);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENB, 0);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;

            default:
                Serial.println("Motor command not recognized");
                break;
            }
        }
    }

