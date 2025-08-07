//
// Created by amsakan on 06.08.25.
//

#ifndef MOTOR_HH
#define MOTOR_HH

#ifdef UNIT_TEST
    #include "../test/test_native/mocks/MockServo.hh"
#else
    #include <Servo.h>
#endif

#include "Device.hh"

class Motor : public Device {
    Servo myservo;
    int pos;
public:
    void init() override;
    void run();
    Servo getServo();
};
#endif //MOTOR_HH
