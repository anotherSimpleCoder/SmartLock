//
// Created by amsakan on 05.08.25.
//
#include <Arduino.h>
#include "Leds.hh"

void LEDS::redBlink() {
    digitalWrite(RED_LED_PIN, HIGH);
    delay(2000);
    digitalWrite(RED_LED_PIN, LOW);
    delay(2000);
}

void LEDS::greenBlink() {
    digitalWrite(GREEN_LED_PIN, HIGH);
    delay(2000);
    digitalWrite(GREEN_LED_PIN, LOW);
    delay(2000);
}