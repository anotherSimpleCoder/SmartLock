#include "Fingerprint.hh"

Fingerprint fingerprint;

void setup() {
    fingerprint.init();
}

void loop() {
    fingerprint.authenticate();
}
