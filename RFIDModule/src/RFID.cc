//
// Created by amsakan on 06.08.25.
//
#include "RFID.hh"

#include <Arduino.h>

#include "../lib/DigiAuth/DigiAuth.hh"

RFID::RFID() :
    sensor(SS_PIN, RST_PIN) {}

void RFID::init() {
    SPI.begin();
    sensor.PCD_Init();
    Wire.begin();
}

void RFID::authenticate() {
    for(int i = 0; i < 6; i++) key.keyByte[i] = 0xFF;
    
    if( ! sensor.PICC_IsNewCardPresent()) {
        return;
    }

    if( ! sensor.PICC_ReadCardSerial() ) {
        return;
    }


    status = sensor.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &sensor.uid);
    if(status != MFRC522::STATUS_OK) {
        Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::FAIL
        }));
        Wire.endTransmission();
    } else {
        Wire.beginTransmission(DigiAuth::DIGIAUTH_CHANNEL);
        Wire.write(DigiAuth::encode({
            DigiAuth::Status::SUCCESS
        }));
        Wire.endTransmission();
    }

    sensor.PICC_HaltA();
    sensor.PCD_StopCrypto1();

}

MFRC522* RFID::getSensor() {
    return &sensor;
}