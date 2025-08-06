//
// Created by amsakan on 06.08.25.
//

#ifndef RFID_HH
#define RFID_HH
#include "AuthDevice.hh"
#include <SPI.h>
#include <MFRC522.h>

class RFID : public AuthDevice {
    constexpr unsigned int RST_PIN = 9;
    constexpr unsigned int SS_PIN = 10;

    unsigned char block = 0;
    unsigned char length = 15;
    unsigned char buffer[15];

    MFRC522 sensor;
    MFRC522::StatusCode status;
    MFRC522::MIFARE_Key key;
public:
    RFID();
    void init() override;
    void authenticate() override;
};
#endif //RFID_HH
