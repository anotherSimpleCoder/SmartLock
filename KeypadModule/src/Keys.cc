//
// Created by amsakan on 06.08.25.
#include "Keys.hh"
#include "../lib/Strings/Strings.hh"
#include "../lib/DigiAuth/DigiAuth.hh"

using DigiAuth::Status;

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
    Wire.begin();
    leds.init();
}

void Keys::authenticate() {
    Wire.beginTransmission(9);
    Wire.write(DigiAuth::encode({0, Status::START}));

    char key = keypad->getKey();
    if(!key) return;

    if(key == '#') {
        bool equal = Strings::equals(pinCode, buffer);

        if(equal) {
            Wire.write(DigiAuth::encode({
                0, Status::SUCCESS
            }));
            leds.greenBlink();
        } else {
            Wire.write(DigiAuth::encode({
                0, Status::FAIL
            }));
            leds.redBlink();
        }

        i = 0;
        Strings::clear(buffer);
    } else if(i < 4) {
        //Serial.println(key);
        buffer[i] = key;
        i++;
    }

    Wire.write(DigiAuth::encode({0, Status::END}));
    Wire.endTransmission();
}

Keypad* Keys::getKeypad() {
    return keypad;
}