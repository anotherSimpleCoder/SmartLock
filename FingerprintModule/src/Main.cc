#include <Arduino.h>

#include "Fingerprint.hh"

Fingerprint fingerprint;

void setup() {
    Serial.begin(9600);
    while (!Serial);
    fingerprint.init();
}

void loop() {
    fingerprint.authenticate();
}
