// Macros to read the three line tracking sensors.
// These will return '0' with a light surface and '1'
// with a dark surface.
#define LT_R !digitalRead(10)
#define LT_M !digitalRead(4)
#define LT_L !digitalRead(2)
bool go = true;
char direction = 'S';
void followLine() {
    
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