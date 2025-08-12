//
// Created by amsakan on 06.08.25.
//

#ifndef FINGERPRINT_HH
#define FINGERPRINT_HH
#ifdef UNIT_TEST
    #include "../test/test_native/mocks/FingerprintMock.hh"
    #include "../test/test_native/mocks/WireMock.hh"
    #define Wire WireMock
#else
    #include <Adafruit_Fingerprint.h>
    #include <Wire.h>
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
