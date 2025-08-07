//
// Created by amsakan on 06.08.25.
//

#ifndef LEDS_HH
#define LEDS_HH
#include "Device.hh"

class LEDS : Device {
public:
    static const int RED_LED_PIN;
    static const int GREEN_LED_PIN;

    void init() override;
    void redBlink();
    void greenBlink();
};
#endif //LEDS_HH
