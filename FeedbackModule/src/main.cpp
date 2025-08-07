#include <Arduino.h>
#include "Motor.hh"
#include "LEDS.hh"

Motor motor;
LEDS leds;

void setup() {
  Serial.begin(9600);
  motor.init();
  leds.init();
}

void loop() {
  Serial.println("Running motor");
  motor.run();

  Serial.println("Running LEDs");
  leds.greenBlink();
}