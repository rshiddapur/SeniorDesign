void followLine() {
    bool go = true;
    char direction = 'S';
    while (go)
    {
        // Move the bot one tick in specified direction
        motor(direction, 1);
        // If it's now on a station, stop the bot at the next iteration
        go = !onStation();
        // Check what direction to go in if moving
        if (go)
        {
            direction = checkDirection();
        } 
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
        return 'R';
    }
}

// Check if the bot is on a station. (all three sensors detect black)
bool onStation() {
    return (LT_L && LT_M && LT_R);
}