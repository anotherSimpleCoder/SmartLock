//
// Created by amsakan on 06.08.25.
//

#ifndef LEDS_HH
#define LEDS_HH
#include "Device.hh"

class LEDS : Device {
    constexpr int RED_LED_PIN = 10;
    constexpr int GREEN_LED_PIN = 11;

public:
    void init() override;
    void redBlink();
    void greenBlink();
};

#endif //LEDS_HH
