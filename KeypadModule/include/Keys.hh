//
// Created by amsakan on 06.08.25.
//
#ifndef KEYPAD_HH
#define KEYPAD_HH

#ifdef UNIT_TEST
    #include "../test/test_native/mocks/KeypadMock.hh"
    #include "../test/test_native/mocks/WireMock.hh"
    #define Wire WireMock
#else
    #include <Wire.h>
    #include <Keypad.h>
#endif

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

    unsigned char rowPins[4] = {2, 3, 4, 5};
    unsigned char colPins[3] = {6, 7, 8};

    char pinCode[5] = "1473";
    char buffer[5];
    int i = 0;

    Keypad* keypad;
    LEDS leds;
public:
    Keys();
    void init() override;
    void authenticate() override;
    Keypad* getKeypad();
};
#endif //KEYPAD_HH
