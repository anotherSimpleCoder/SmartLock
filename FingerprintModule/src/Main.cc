#include <Arduino.h>

#include "Fingerprint.hh"

Fingerprint fingerprint;

void setup() {
    while (!Serial);
    fingerprint.init();
}

void loop() {
    fingerprint.authenticate();
}
