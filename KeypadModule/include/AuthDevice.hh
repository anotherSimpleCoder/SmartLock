//
// Created by amsakan on 06.08.25.
//

#ifndef AUTHDEVICE_HH
#define AUTHDEVICE_HH
#include "Device.hh"

class AuthDevice : Device {
public:
    virtual void authenticate() = 0;
};
#endif //AUTHDEVICE_HH
