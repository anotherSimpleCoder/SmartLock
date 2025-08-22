//
// Created by amsakan on 06.08.25.
//
#include "Fingerprint.hh"

#include "../lib/DigiAuth/DigiAuth.hh"

Fingerprint::Fingerprint():
    mySerial(SoftwareSerial(2, 3)), finger(Adafruit_Fingerprint(&mySerial)){}


void Fingerprint::init() {
    Wire.begin();
    finger.begin(57600);
}

void Fingerprint::authenticate() {
    auto status = finger.getImage();

    if (status == FINGERPRINT_OK) {
        Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::SUCCESS
        }));
        Wire.endTransmission();
    }

    if (status == FINGERPRINT_IMAGEFAIL) {
        Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::FAIL
        }));
        Wire.endTransmission();
    }
}

Adafruit_Fingerprint* Fingerprint::getFingerprint() {
    return &finger;
}