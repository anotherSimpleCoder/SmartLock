//
// Created by abav on 07.08.2025.
//

#ifndef MFRC522_HH
#define MFRC522_HH
class MFRC522 {
    bool newCardPresent = true;
    bool readCardSerial = true;
    unsigned char readCardData[7];
public:
    int uid;
    const static int PICC_CMD_MF_AUTH_KEY_A = -1;
    enum StatusCode {
        STATUS_OK = 0,
        STATUS_ERROR = -1,
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
    void readCard(unsigned char card[7]) {
        for (int i = 0; i < 7; i++) {
            readCardData[i] = card[i];
        }
    }


    StatusCode PCD_Authenticate(int keytype, int blockAddress, MIFARE_Key* key, int* uid) {
        for (int i = 0; i < 6; i++) {
            if (key->keyByte[i] != readCardData[i]) {
                return STATUS_ERROR;
            }
        }

        return STATUS_OK;
    }
};
#endif //MFRC522_HH
