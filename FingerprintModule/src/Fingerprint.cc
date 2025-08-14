//
// Created by amsakan on 06.08.25.
//
#include "Fingerprint.hh"

#include <Arduino.h>

#include "../lib/DigiAuth/DigiAuth.hh"

Fingerprint::Fingerprint():
    mySerial(SoftwareSerial(2, 3)), finger(Adafruit_Fingerprint(&mySerial)){}


void Fingerprint::init() {
    Wire.begin();
    finger.begin(57600);
}

void Fingerprint::authenticate() {
    Wire.beginTransmission(9);

    auto status = finger.getImage();

    if (status == FINGERPRINT_OK) {
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::SUCCESS
        }));
    }

    if (status == FINGERPRINT_IMAGEFAIL) {
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::FAIL
        }));
    }

    Wire.endTransmission();
}

Adafruit_Fingerprint* Fingerprint::getFingerprint() {
    return &finger;
}