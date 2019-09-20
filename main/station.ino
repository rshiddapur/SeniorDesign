void station() {
    // Check if there's an object to the right
    // Wait until it is removed if it exists
    head.write(0);
    delay(1500);
    while (obstacleCheck(31))
    {
        delay (100);
    }
    head.write(90);

    // Get off the station
    // Adjust this number to change how far the bot moves off the station.
    // Increase to avoid redetecting the same station and decrease to avoid overshoot.
    while (onStation())
    {
        motor('S', 6);
    }
}