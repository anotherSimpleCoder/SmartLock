//
// Created by abav on 07.08.2025.
//
#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "Keys.hh"
#include "../src/Keys.cc"

using namespace fakeit;

class KeysTests : public ::testing::Test {
public:
  void SetUp() override {
    ArduinoFakeReset();
  }
};

TEST_F(KeysTests, EnterRightPin_ShouldBlinkGreen) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  Keys keys;
  keys.init();

  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  keys.getKeypad()->pressKey('1');
  keys.authenticate();

  keys.getKeypad()->pressKey('4');
  keys.authenticate();

  keys.getKeypad()->pressKey('7');
  keys.authenticate();

  keys.getKeypad()->pressKey('3');
  keys.authenticate();

  keys.getKeypad()->pressKey('#');
  keys.authenticate();

  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, HIGH)).Once();
  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, LOW)).Once();
  Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

TEST_F(KeysTests, EnterRightPin_ShouldBlinkRed) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  Keys keys;
  keys.init();

  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  keys.getKeypad()->pressKey('1');
  keys.authenticate();

  keys.getKeypad()->pressKey('4');
  keys.authenticate();

  keys.getKeypad()->pressKey('1');
  keys.authenticate();

  keys.getKeypad()->pressKey('3');
  keys.authenticate();

  keys.getKeypad()->pressKey('#');
  keys.authenticate();

  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, HIGH)).Once();
  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, LOW)).Once();
  Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}