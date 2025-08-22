//
// Created by amsakan on 16.08.25.
//

#ifndef DISPLAY_HH
#define DISPLAY_HH
#include "Device.hh"

#ifdef UNIT_TEST
    #include "../test/test_native/mocks/MockDisplay.hh"
#else
    #include <LCDI2C_Multilingual_MCD.h>
#endif


class Display : Device {
    LCDI2C_Latin display;
public:
    Display();
    void init() override;
    void successMessage();
    void failMessage();
    void displayPIN(int pinLength);
    LCDI2C_Latin* getDisplay();
};
#endif //DISPLAY_HH
