//
// Created by amsakan on 06.08.25.
//

#ifndef FINGERPRINT_HH
#define FINGERPRINT_HH
#include <Adafruit_Fingerprint.h>
#include "AuthDevice.hh"
#include "Leds.hh"


class Fingerprint : public AuthDevice {
    SoftwareSerial mySerial;
    Adafruit_Fingerprint finger;
    uint8_t id;

    LEDS leds;
public:
    Fingerprint();
    void init() override;
    void authenticate() override;
};
#endif //FINGERPRINT_HH
