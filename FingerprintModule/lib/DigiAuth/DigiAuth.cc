#include "DigiAuth.hh"

unsigned char 
DigiAuth::encode(DigiAuthMessage message) {
        unsigned char code = DIGIAUTH_PREAMBLE << 2;
        code = (code | message.deviceId) << 2;
        code = (code | message.status);

        return code;
}

DigiAuth::DigiAuthMessage 
DigiAuth::decode(unsigned char code) {
        if(((code & PREAMBLE_MASK) >> 4) != DIGIAUTH_PREAMBLE) {
                return DigiAuthMessage{0xFF, FAIL};
        }

        DigiAuthMessage res{
                (code & ID_MASK) >> 2,
                (Status)(code & STATUS_MASK)
        };

        return res;
}
