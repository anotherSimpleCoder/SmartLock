#include <Arduino.h>
#include "RFID.hh"

RFID rfid;

void setup() {
    rfid.init();
}

void loop() {
    rfid.authenticate();
}