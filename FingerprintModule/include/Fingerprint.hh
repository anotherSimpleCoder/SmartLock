//
// Created by amsakan on 06.08.25.
//

#ifndef FINGERPRINT_HH
#define FINGERPRINT_HH
#include <Adafruit_Fingerprint.h>
#include "AuthDevice.hh"

class Fingerprint : public AuthDevice {
    SoftwareSerial mySerial;
    Adafruit_Fingerprint finger;
    uint8_t id;
public:
    Fingerprint();
    void init() override;
    void authenticate() override;
};
#endif //FINGERPRINT_HH
