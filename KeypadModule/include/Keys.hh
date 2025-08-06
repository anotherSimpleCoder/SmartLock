//
// Created by amsakan on 06.08.25.
//

#ifndef KEYPAD_HH
#define KEYPAD_HH
#include <Keypad.h>
#include "AuthDevice.hh"
#include "Leds.hh"

class Keys : public AuthDevice {
    constexpr unsigned int ROWS = 4;
    constexpr unsigned int COLS = 3;

    constexpr char keys[ROWS][COLS] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
        {'*', '0', '#'}
    };

    constexpr byte rowPins[] = {2, 3, 4, 5};
    constexpr byte colPins[] = {6, 7, 8};

    char pinCode[4] = "1473";
    char buffer[4];
    int i = 0;

    Keypad* keypad;
    LEDS leds;
public:
    Keys();
    void init() override;
    void authenticate() override;
};
#endif //KEYPAD_HH
