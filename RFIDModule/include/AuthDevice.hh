//
// Created by amsakan on 06.08.25.
//

#ifndef AUTHDEVICE_HH
#define AUTHDEVICE_HH
class AuthDevice {
public:
    virtual void init() = 0;
    virtual void authenticate() = 0;
};
#endif //AUTHDEVICE_HH
