//
// Created by amsakan on 06.08.25.
//

#ifndef MOTOR_HH
#define MOTOR_HH
#include <Servo.h>
#include "Device.hh"

class Motor : public Device {
    Servo myservo;
    int pos = 0;
public:
    void init() override;
    void run();
};
#endif //MOTOR_HH
