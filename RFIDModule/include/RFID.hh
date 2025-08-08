//
// Created by amsakan on 06.08.25.
//

#ifndef RFID_HH
#define RFID_HH
#ifdef UNIT_TEST
#include "../test/test_native/mocks/MFRC522.hh"
#else
    #include <MFRC522.h>
#endif

#include "AuthDevice.hh"
#include "Leds.hh"

class RFID : public AuthDevice {
    constexpr static unsigned int RST_PIN = 9;
    constexpr static unsigned int SS_PIN = 10;

    unsigned char block = 0;
    unsigned char length = 15;
    unsigned char buffer[15];

    MFRC522 sensor;
    MFRC522::StatusCode status;
    MFRC522::MIFARE_Key key;

    LEDS leds;
public:
    RFID();
    void init() override;
    void authenticate() override;
    MFRC522* getSensor();
};
#endif //RFID_HH
