void station() {
    //delay (1000);
    // Check if there's an object to the right
    head.write(0);
    delay(1500);
    while (obstacleCheck(31))
    {
        delay (100);
    }
    head.write(90);

    // Get off the station
    while (onStation())
    {
        motor('S', 6);
    }
}


void servoTest() {
    // Set the head looking to the side.
    head.write(0);
    delay(2000);
    // and to the middle
    head.write(90);
    delay(1000);
}