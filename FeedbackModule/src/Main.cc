#include <Arduino.h>
#include <Wire.h>
#include "Motor.hh"
#include "LEDS.hh"
#include "Display.hh"
#include "../lib/DigiAuth/DigiAuth.hh"

Motor motor;
LEDS leds;
Display display;

using DigiAuth::Status;

void receive(int bytes) {
  unsigned char receivedCode = Wire.read();
  DigiAuth::DigiAuthMessage message = DigiAuth::decode(receivedCode);
  Serial.println(receivedCode);

  switch (message.status) {
    case Status::SUCCESS: {
      motor.open();
      leds.greenBlink();
      //display.successMessage();
      break;
    }

    case Status::FAIL: {
      leds.redBlink();
      //display.failMessage();
      break;
    }

    default: {}
  }
}

void setup() {

  motor.init();
  leds.init();

  Wire.begin(DigiAuth::DIGIAUTH_CHANNEL);
  Wire.onReceive(receive);
  Serial.begin(9600);

  //display.init();
}

void loop() {
  delay(5000);

  if (motor.isOpen()) {
    motor.close();
  }
}