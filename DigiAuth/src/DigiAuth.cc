#include "DigiAuth.hh"

#include <iostream>

unsigned char 
DigiAuth::encode(DigiAuth::DigiAuthMessage message) {
        unsigned char code = DIGIAUTH_PREAMBLE << 2;
        code = (code | message.deviceId) << 2;
        code = (code | message.status);

        return code;
}

DigiAuth::DigiAuthMessage 
DigiAuth::decode(unsigned char code) {
        if(((code & PREAMBLE_MASK) >> 4) != DIGIAUTH_PREAMBLE) {
                return DigiAuthMessage{0xFF, Status::FAIL};
        }

        DigiAuth::DigiAuthMessage res{
                (code & ID_MASK) >> 2,
                (Status)(code & STATUS_MASK)
        };

        std::cout << "Device ID: " << res.deviceId << "\n";

        return res;
}
