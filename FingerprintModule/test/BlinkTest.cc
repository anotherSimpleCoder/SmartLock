//
// Created by amsakan on 06.08.25.
//
#include <ArduinoFake.h>

using namespace fakeit;

void testLoop(void) {
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();

}