#include <Arduino.h>
#include <Wire.h>
#include "Motor.hh"
#include "LEDS.hh"
#include "../lib/DigiAuth/DigiAuth.hh"

//Motor motor;
LEDS leds;

using DigiAuth::Status;

void receive(int bytes) {
  unsigned char receivedCode = Wire.read();

  switch (receivedCode) {
    case 161: {
      //motor.run();
      Serial.println("works!");
      leds.greenBlink();
      break;
    }

    case 162: {
      leds.redBlink();
      break;
    }

    default: {}
  }
}

void setup() {
  Wire.begin(9);
  Wire.onReceive(receive);
  Serial.begin(9600);
  //motor.init();
  leds.init();
}

void loop() {
  delay(1000);
}