//
// Created by amsakan on 06.08.25.
//
#include <Arduino.h>
#include "Motor.hh"

void Motor::init() {
    myservo.attach(8);
    this->close();
}

void Motor::open() {
    if (!opened) {
        for (pos = 90; pos >= 0; pos -= 10) {
            myservo.write(pos);
            delay(100);
        }
        opened = true;
    }
}

void Motor::close() {
    if (opened) {
        for (pos = 0; pos <= 90; pos += 10) {
            myservo.write(pos);
            delay(100);
        }

        opened = false;
    }
}

bool Motor::isOpen() {
    return this->opened;
}


Servo Motor::getServo() {
    return myservo;
}
