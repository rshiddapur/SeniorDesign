/** 
 * Higher level use of Ultrasonic
 * These functions will take in the distance measurement
 * in cm and output 1 or 0 for whether there is an object or not 
 * Ultrasonic distance measurement.  Returns distance in cm.
 */

int obstacleCheck() {
    if (getDistance() <= 5){
        return 1;
    } else {
        return 0;
    }
}

int stationObstacle() {
    if (getDistance <= 10) {
        return 1;
    } else {
        return 0;
    }
}