#ifndef DIGIAUTH_HH
#define DIGIAUTH_HH


namespace DigiAuth {
        constexpr unsigned char DIGIAUTH_PREAMBLE = 0b1010;

        constexpr unsigned char PREAMBLE_MASK = 0b11110000;
        constexpr unsigned char ID_MASK = 0b00001100;
        constexpr unsigned char STATUS_MASK = 0b00000011;

        constexpr unsigned char DIGIAUTH_CHANNEL = 9;

        enum Status {
                SUCCESS = 1,
                FAIL = 2,
                INVALID = 3
        };

        struct DigiAuthMessage {
                Status status;

                bool
                operator==(const DigiAuthMessage &message) const {
                        return this->status == message.status;
                }

                bool
                operator!=(const DigiAuthMessage &message) const {
                        return this->status != message.status;
                }
        };

        unsigned char
        encode(DigiAuthMessage message);

        DigiAuthMessage
        decode(unsigned char code);
}

#endif 
