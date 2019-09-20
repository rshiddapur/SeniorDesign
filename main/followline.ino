void followLine() {
    bool go = true;
    char direction = 'S';
    head.write(90);
    delay(500);
    while (go)
    {
        // calling waitForTick() at the beginning of loop will keep it periodic
        // waitForTick();
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
        // Move the bot one tick in specified direction
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

// /**
//  * waitForTick() blocks until a periodic time based on the global millis() time,
//  * which can be used to force loop() to run at a predictable rate (as long as
//  * the code in loop() is faster than the tick time).
//  * This may or may not be desirable for your code, but it usually is.
//  */
// void waitForTick()
// {
//     // block until the specified time
//     while ((millis() - prevMillis) <= LoopTime)
//         ;
//     prevMillis = millis();
//     return;
// }