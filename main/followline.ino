void followLine() {
    // Initialize instance variables and reset the servo head
    bool go = true;
    char direction = 'S';
    head.write(90);
    delay(500);

    // Main loop for path traversal
    while (go)
    {
        // Check if there's an obstacle within a foot in front of the bot. 
        // Delay 1 second after an object is detected
        while (obstacleCheck(30))
        {
            delay(1000);
        }
           
        // If it's now on a station, stop the bot at the next iteration
        go = !onStation();

        // Check what direction to go in if moving
        if (go)
        {
            direction = checkDirection();
        }

        // Move the bot two ticks in specified direction. 
        // Adjust this number to change how "jittery" the bot is at the expense of polling rate.
        motor(direction, 2); 
    }
}

char checkDirection () {
    // Bot is skewed to the right. Only the left sensor is triggered
    if (LT_L && !LT_M && !LT_R)
    {
        return 'c';
    }

    // Bot is skewed to the left. Only the right sensor is triggered
    else if (!LT_L && !LT_M && LT_R)
    {
        return 'C';
    }

    // Bot is on track. Go straight
    else if (!LT_L && LT_M && !LT_R)
    {
        return 'S';
    }

    // Bot is completely off track. Turn clockwise until it finds the track.
    else if (!LT_L && !LT_M && !LT_R)
    {
        return 'C';
    }
}

// Check if the bot is on a station. (all three sensors detect black)
bool onStation() {
    return (LT_L && LT_M && LT_R);
}