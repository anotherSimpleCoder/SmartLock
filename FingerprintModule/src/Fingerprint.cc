//
// Created by amsakan on 06.08.25.
//
#include "Fingerprint.hh"

#include <Arduino.h>

#include "../lib/DigiAuth/DigiAuth.hh"

Fingerprint::Fingerprint():
    mySerial(SoftwareSerial(2, 3)), finger(Adafruit_Fingerprint(&mySerial)){}


void Fingerprint::init() {
    finger.begin(57600);
}

void Fingerprint::authenticate() {
    Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
    Wire.write(DigiAuth::encode({0, DigiAuth::Status::START}));

    auto status = finger.getImage();

    if (status == FINGERPRINT_OK) {
        Wire.write(DigiAuth::encode({
            0, DigiAuth::Status::SUCCESS
        }));
    } else {
        Wire.write(DigiAuth::encode({
            0, DigiAuth::Status::FAIL
        }));
    }

    Wire.write(DigiAuth::encode({0, DigiAuth::Status::END}));
    Wire.endTransmission();
}

Adafruit_Fingerprint* Fingerprint::getFingerprint() {
    return &finger;
}