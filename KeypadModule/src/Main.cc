#include <Arduino.h>
#include "Keys.hh"

Keys keys;

void setup() {
    keys.init();
}

void loop() {
    keys.authenticate();
}


