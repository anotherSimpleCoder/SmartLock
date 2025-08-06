//
// Created by amsakan on 06.08.25.
//
#include "Keys.hh"

#include "String.hh"

Keys::Keys() {
    keypad = new Keypad(
        makeKeymap(keys),
        rowPins,
        colPins,
        ROWS,
        COLS
    );
}

void Keys::init() {
    leds.init();
}

void Keys::authenticate() {
    char key = keypad->getKey();
    if(!key) return;

    if(key == '#') {
        bool equal = Strings::equals(pinCode, buffer);

        if(equal) {
            leds.greenBlink();
        } else {
            leds.redBlink();
        }

        i = 0;
        Strings::clear(buffer);
    } else if(i < 4) {
        Serial.println(key);
        buffer[i] = key;
        i++;
    }
}
