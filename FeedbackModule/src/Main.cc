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
  DigiAuth::DigiAuthMessage message = DigiAuth::decode(receivedCode);

  switch (message.status) {
    case Status::START: {
      break;
    }

    case Status::SUCCESS: {
      //motor.run();
      leds.greenBlink();

      break;
    }

    case Status::FAIL: {
      leds.redBlink();
      break;
    }

    case Status::END: {
      break;
    }
  }
}

void setup() {
  Wire.begin(DigiAuth::DIGIAUTH_CHANNEL);
  Wire.onReceive(receive);
  Serial.begin(9600);
  //motor.init();
  leds.init();
}

void loop() {
  delay(1000);
}