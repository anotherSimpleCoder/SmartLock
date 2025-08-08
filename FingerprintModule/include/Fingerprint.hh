//
// Created by amsakan on 06.08.25.
//

#ifndef FINGERPRINT_HH
#define FINGERPRINT_HH
#ifdef UNIT_TEST
    #include <ArduinoFake.h>
    #include "../test/test_native/mocks/FingerprintMock.hh"
#else
    #include <Adafruit_Fingerprint.h>
#endif

#include "Leds.hh"
#include "AuthDevice.hh"

class Fingerprint : public AuthDevice {
    LEDS leds;
    SoftwareSerial mySerial;
    Adafruit_Fingerprint finger;
    unsigned char id;
public:
    Fingerprint();
    void init() override;
    void authenticate() override;
    Adafruit_Fingerprint* getFingerprint();
};
#endif //FINGERPRINT_HH
