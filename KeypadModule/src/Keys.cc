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

    display = new Display();
}

void Keys::init() {
    Wire.begin();
    display->init();
}

void Keys::authenticate() {
    char key = keypad->getKey();

    if(!key) return;

    if(key == '#') {
        bool equal = Strings::equals(pinCode, buffer);

        if(equal) {
            Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
            Wire.write(DigiAuth::encode({
                Status::SUCCESS
            }));
            Wire.endTransmission();
            display->successMessage();
        } else {
            Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
            Wire.write(DigiAuth::encode({
                Status::FAIL
            }));
            Wire.endTransmission();
            display->failMessage();
        }

        i = 0;
        Strings::clear(buffer);
    } else if(i < 4) {
        buffer[i] = key;
        i++;
        display->displayPIN(i);
    }
}

Keypad* Keys::getKeypad() {
    return keypad;
}