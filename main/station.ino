/**
 * Arrival @ Station
 * Must change servo direction to face right/inwards
 * detect station obstacle
 * once clear, reset the servo
 * proceed forward
 */

void station() {
    int go = 0;
    head.write(0);
    delay(1000);
    while(go = 0 ){
        if(stationObstacle == 0){
            go = 1;
            head.write(90);
            delay(1000);
            return
        } else {
            go = 0;
        }
    }
}