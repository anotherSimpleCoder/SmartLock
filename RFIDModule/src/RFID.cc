//
// Created by amsakan on 06.08.25.
//
#include "Leds.hh"
#include "RFID.hh"

RFID::RFID() :
    sensor(SS_PIN, RST_PIN){}

void RFID::init() {
    SPI.begin();
    sensor.PCD_Init();
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
        Serial.print(F("Authentication failed: "));
        Serial.println(sensor.GetStatusCodeName(status));
        LEDS::redBlink();
        return;
    }

    LEDS::greenBlink();
    Serial.println("Works!");


    sensor.PICC_HaltA();
    sensor.PCD_StopCrypto1();
}
