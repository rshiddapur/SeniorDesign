

bool go;
char direction;
void followLine() {
    go = true;
    direction = 'S';
    while (go)
    {
        motor(direction, 1);
        checkIfContinue();
    }
    
}

void checkIfContinue () {
    // Bot is on the station line. Stop the bot.
    if (onStation())
    {
        go = false;
    } else {
        go = true;
    }

    // Bot is skewed to the right. Only the left sensor is triggered
    if (LT_L && !LT_M && !LT_R)
    {
        direction = 'c';
        go = true;
    }

    // Bot is skewed to the left. Only the right sensor is triggered
    if (!LT_L && !LT_M && LT_R)
    {
        direction = 'C';
        go = true;
    }

    // Bot is on track. Go straight
    if (!LT_L && LT_M && !LT_R)
    {
        direction = 'S';
        go = true;
    }

    // Bot is completely off track. Turn clockwise until it finds the track.
    if (!LT_L && !LT_M && !LT_R)
    {
        direction = 'R';
        go = true;
    }
    
}

// Check if the bot is on a station. (all three sensors detect black)
bool onStation() {
    return (LT_L && LT_M && LT_R);
}