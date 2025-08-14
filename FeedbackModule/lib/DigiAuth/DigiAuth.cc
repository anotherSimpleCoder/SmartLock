#include "DigiAuth.hh"

unsigned char 
DigiAuth::encode(DigiAuthMessage message) {
        unsigned char code = DIGIAUTH_PREAMBLE << 4;
        code = (code | message.status);

        return code;
}

DigiAuth::DigiAuthMessage 
DigiAuth::decode(unsigned char code) {
        if(((code & PREAMBLE_MASK) >> 4) != DIGIAUTH_PREAMBLE) {
                return DigiAuthMessage{INVALID};
        }

        DigiAuthMessage res{
                (Status)(code & STATUS_MASK)
        };

        return res;
}
