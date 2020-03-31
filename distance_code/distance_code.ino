#include <Ultrasonic.h>
#include <BoltIoT-Arduino-Helper.h>

#define TRIG_PIN 12
#define ECHO_PIN 13

Ultrasonic ultrasonic(TRIG_PIN,ECHO_PIN);
int distance=0;

String getDistance(String *arguments){
  distance = ultrasonic.read();
    String returnString=""+String(distance);
    return returnString;
}

void setup() {
  boltiot.begin(Serial);
  boltiot.setCommandString("RD\r",getDistance);
  boltiot.setCommandString("GetDistance",getDistance);
}

void loop() {
  boltiot.handleCommand();
  
}
