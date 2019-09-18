void station() {
    //delay (2000);
    servoTest();
    while (onStation())
    {
        motor('S', 3);
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