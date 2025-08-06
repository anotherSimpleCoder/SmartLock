//
// Created by amsakan on 06.08.25.
//
#ifndef KEYPAD_HH
#define KEYPAD_HH

#include <Keypad.h>
#include "AuthDevice.hh"
#include "Leds.hh"

class Keys : public AuthDevice {
    const static unsigned int ROWS = 4;
    const static unsigned int COLS = 3;

    const char keys[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };

    byte rowPins[4] = {2, 3, 4, 5};
    byte colPins[3] = {6, 7, 8};

    char pinCode[5] = "1473";
    char buffer[5];
    int i = 0;

    Keypad* keypad;
    LEDS leds;
public:
    Keys();
    void init() override;
    void authenticate() override;
};
#endif //KEYPAD_HH
