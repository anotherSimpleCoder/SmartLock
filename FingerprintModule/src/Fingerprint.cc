//
// Created by amsakan on 06.08.25.
//
#include "Fingerprint.hh"

#include <Arduino.h>

#include "../lib/DigiAuth/DigiAuth.hh"

Fingerprint::Fingerprint():
    mySerial(SoftwareSerial(2, 3)), finger(Adafruit_Fingerprint(&mySerial)){}


void Fingerprint::init() {
    leds.init();
    finger.begin(57600);
}

void Fingerprint::authenticate() {
    Wire.beginTransmission(DigiAuth::FINGERPRINT_CHANNEL);
    Wire.write(DigiAuth::encode({0, DigiAuth::Status::START}));

    auto status = finger.getImage();

    if (status == FINGERPRINT_OK) {
        Wire.write(DigiAuth::encode({
            0, DigiAuth::Status::SUCCESS
        }));
        //leds.greenBlink();
    } else {
        Wire.write(DigiAuth::encode({
            0, DigiAuth::Status::FAIL
        }));
        //leds.redBlink();
    }

    Wire.write(DigiAuth::encode({0, DigiAuth::Status::END}));
    Wire.endTransmission();
}

Adafruit_Fingerprint* Fingerprint::getFingerprint() {
    return &finger;
}