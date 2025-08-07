//
// Created by amsakan on 06.08.25.
//
#include "Fingerprint.hh"
#include "Leds.hh"

Fingerprint::Fingerprint():
    mySerial(SoftwareSerial(2, 3)), finger(Adafruit_Fingerprint(&mySerial)){}


void Fingerprint::init() {
    leds.init();
    finger.begin(57600);

    if (finger.verifyPassword()) {
        Serial.println("Found fingerprint sensor!");
    } else {
        Serial.println("Did not find fingerprint sensor :(");
        while (1) {delay(1);}
    }
}

void Fingerprint::authenticate() {
    auto status = finger.getImage();

    if (status == FINGERPRINT_OK) {
        status = finger.image2Tz();

        if (status == FINGERPRINT_OK) {
            Serial.println("works!");
            leds.greenBlink();
        }
    }


}
