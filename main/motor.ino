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
    // set default motor run time to 1/10 second
    int runTime = 200;

    // set default motor delay time to 1/10 second
    int delayTime = 100;

    int roll;
    for ( roll = 0; roll < numTicks; roll++) {

        switch (direction)
            {
            case 'S':
                // move the robot straight
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, HIGH);
                analogWrite(ENA, 128);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;
            
            case 's':
                // move the robot backwards straight 
                digitalWrite(IN4, HIGH);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 128);
                delay(runTime);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 0);
                delay(delayTime);
                digitalWrite(IN1, HIGH);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 128);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 0);
                delay(delayTime);
                break;

            case 'R':
                // move the robot to the right 
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, HIGH);
                analogWrite(ENA, 128);
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
                analogWrite(ENA, 128);
                delay(runTime);
                digitalWrite(IN4, LOW);
                digitalWrite(IN3, LOW);
                analogWrite(ENA, 0);
                delay(delayTime);
                break;

            case 'L':
                // move the robot to the left 
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, HIGH);
                analogWrite(ENB, 128);
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
                analogWrite(ENB, 128);
                delay(runTime);
                digitalWrite(IN1, LOW);
                digitalWrite(IN2, LOW);
                analogWrite(ENB, 0);
                delay(delayTime);
                break;



            default:
                break;
            }
        }
    }

