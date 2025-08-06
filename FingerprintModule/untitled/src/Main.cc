#include <Arduino.h>
#include "Fingerprint.hh"

Fingerprint fingerprintSensor;

void setup() {
    Serial.begin(9600);
    while (!Serial);
    delay(100);
    fingerprintSensor.init();
}

void loop() {
    fingerprintSensor.authenticate();
}