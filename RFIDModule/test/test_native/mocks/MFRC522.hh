//
// Created by abav on 07.08.2025.
//

#ifndef MFRC522_HH
#define MFRC522_HH
class MFRC522 {
    bool newCardPresent = true;
    bool readCardSerial = true;
public:
    int uid;
    const static int PICC_CMD_MF_AUTH_KEY_A = -1;
    enum StatusCode {
        STATUS_OK = 0,
    };
    struct MIFARE_Key {
        unsigned char keyByte[7];
    };

    MFRC522(unsigned int SS_PIN, unsigned int RST_PIN) {}
    void PCD_Init() {}
    void PICC_HaltA() {}
    void PCD_StopCrypto1() {}
    bool PICC_IsNewCardPresent() { return newCardPresent; }
    bool PICC_ReadCardSerial() { return readCardSerial; }

    StatusCode PCD_Authenticate(int keytype, int size, MIFARE_Key* key, int* uid) {
        return STATUS_OK;
    }
};
#endif //MFRC522_HH
