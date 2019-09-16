void station() {
    delay (2000);
    while (onStation())
    {
        motor('S', 2);
    }
    followLine();
}