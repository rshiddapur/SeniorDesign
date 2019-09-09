/** 
 *  Ultrasonic distance measurement.  Returns distance in cm.
 *  Max distance is ~1.5m, based on the timeout of pulseIn().
 *  This is an example of a lowest-level function, since it
 *  interacts with, and depends on, the lowest level of hardware
 *  of the processor and sensor.
 */
int getDistance()
{
    digitalWrite(Trig, LOW); // ensure ping is off
    delayMicroseconds(2);
    digitalWrite(Trig, HIGH); // start ping
    delayMicroseconds(10);
    digitalWrite(Trig, LOW);                     // end ping
    return (int)pulseIn(Echo, HIGH, 10000) / 58; // measure time of flight and convert to cm
}