#include <PulseSensorPlayground.h>
#include <ESP8266TimerInterrupt.h>

//const int LED_pin = 4;
int Threshold = 450;

PulseSensorPlayground pulseSensor;

void setup() {

  Serial.begin(115200);
  pulseSensor.analogInput(A0);
//  pulseSensor.blinkOnPulse(LED_pin);
  pulseSensor.setThreshold(Threshold);

  if(pulseSensor.begin()) {
    Serial.println("Pulse Sensor is running...");
  }
  
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();

    if(pulseSensor.sawStartOfBeat()) {
        Serial.println("A Heartbeat Happened ! BPM: ");
        Serial.println(myBPM);
        delay(10);
    }
}