

bool go = true;
char direction = 'S';
void followLine() {
    go = true;
    while (go)
    {
        motor(direction, 1);
        checkIfContinue();
    }
    
}

void checkIfContinue () {
    // Bot is on the station line. Stop the bot.
    if (LT_L && LT_M && LT_R)
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
    }
}

// Example of how the sensor macros can be used.  Whether or not this
// type of sensor interaction belongs in loop() is up to your
// code structure.
//if (LT_M)
//{
// Do something based on the middle sensor detecting a dark surface
//}
bool onStation() {
    return (LT_L && LT_M && LT_R);
}