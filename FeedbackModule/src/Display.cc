//
// Created by amsakan on 16.08.25.
//
#include <Arduino.h>
#include "Display.hh"

Display::Display()
    :display(LCDI2C_Latin(0x27, 16, 2)) {}


void Display::init() {
    display.init();
    display.backlight();
}

void Display::successMessage() {
    constexpr char message[16] = "Access granted";

    display.clear();
    display.setCursor(3,0);
    display.print(message);

    delay(1000);
}

void Display::failMessage() {
    constexpr char message[16] = "Access denied";

    display.clear();
    display.setCursor(3,0);
    display.print(message);

    delay(1000);
}

LCDI2C_Latin* Display::getDisplay() {
    return &(this->display);
}
