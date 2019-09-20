/** 
 *  Ultrasonic distance measurement.  Returns distance in cm.
 *  Max distance is ~1.5m, based on the timeout of pulseIn().
 */
int getDistance()
{
    digitalWrite(Trig, LOW); // ensure ping is off
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH); // start ping
    delayMicroseconds(10);
    digitalWrite(Trig, LOW); // end ping
    return (int)pulseIn(Echo, HIGH, 10000) / 58; // measure time of flight and convert to cm
}

/** 
 * Higher level use of Ultrasonic.
 * This function will take in the distance measurement
 * in cm and output true or false for whether there is an object or not.
 * Ultrasonic distance measurement returns distance in cm.
 */

bool obstacleCheck(int distance)
{
    int ultrasound = getDistance();
    return ((ultrasound < distance) && (ultrasound != 0));
}