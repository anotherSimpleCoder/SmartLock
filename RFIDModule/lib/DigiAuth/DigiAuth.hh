#ifndef DIGIAUTH_HH
#define DIGIAUTH_HH


namespace DigiAuth {
        constexpr unsigned char DIGIAUTH_PREAMBLE = 0b1010;

        constexpr unsigned char PREAMBLE_MASK = 0b11110000;
        constexpr unsigned char ID_MASK = 0b00001100;
        constexpr unsigned char STATUS_MASK = 0b00000011;

        constexpr unsigned char KEYPAD_CHANNEL = 9;
        constexpr unsigned char FINGERPRINT_CHANNEL = 10;
        constexpr unsigned char RFID_CHANNEL = 11;

        enum Status {
                START = 0,
                SUCCESS = 1,
                FAIL = 2,
                END = 3
        };

        struct DigiAuthMessage {
                unsigned char deviceId;
                Status status;

                bool
                operator==(const DigiAuthMessage &message) const {
                        return (this->deviceId == message.deviceId)
                        && (this->status == message.status);
                }

                bool
                operator!=(const DigiAuthMessage &message) const {
                        return !(this->deviceId != message.deviceId)
                        && (this->status != message.status);
                }
        };

        unsigned char
        encode(DigiAuthMessage message);

        DigiAuthMessage
        decode(unsigned char code);
}

#endif 
