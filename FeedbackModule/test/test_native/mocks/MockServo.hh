//
// Created by abav on 07.08.2025.
//
#ifndef MOCKSERVO_HH
#define MOCKSERVO_HH

class Servo {
    int attachedPin;
    int currentPosition;
public:
    int getAttachedPin() {
        return attachedPin;
    }

    int getCurrentPosition() {
        return currentPosition;
    }

    void attach(int pin) {
        attachedPin = pin;
    }

    void write(int position) {
        currentPosition = position;
    }
};

#endif //MOCKSERVO_HH
