//
// Created by amsakan on 06.08.25.
//

#ifndef DEVICE_HH
#define DEVICE_HH
class AuthDevice {
public:
    virtual void init() = 0;
    virtual void authenticate() = 0;
};
#endif //DEVICE_HH
