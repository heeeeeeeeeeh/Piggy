#include <Arduino.h>
#include "sensors.h"

// The numbers here should be changed according to the pins' wiring on the arduino board
const int TRIG_L = 2;
const int ECHO_L = 3;
const int TRIG_R = 4;
const int ECHO_R = 5;

void setup(){
    Serial.begin(9600);
}

void loop(){
    UltrasonicSensor leftSensor(TRIG_L, ECHO_L);       
    UltrasonicSensor rightSensor(TRIG_R, ECHO_R);

    long distance_L = leftSensor.readDistance();
    long distance_R = rightSensor.readDistance();

    /* I'm using comments instead of actual code because I don't know what whosoever in charge of motors
    * is planning to do. This is just a rough idea of what I think the sensors' activities will entail. 
    * if you spot something you wish to call to my attention just reach out to me with discord.
    */

    if(distance_R > distance_L){
        // turn left
    } else if (distance_L > distance_R){
        // turn right
    } else if (distance_L == distance_R && (distance_L != 999 && distance_R != 999)){
        // move forward
    } else{
        // stop
    }

    delay(100);  // prevents overflowing
    
}
