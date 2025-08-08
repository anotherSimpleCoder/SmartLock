//
// Created by abav on 08.08.2025.
//
#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "Fingerprint.hh"
#include "../../src/Fingerprint.cc"

using namespace fakeit;

class FingerprintTests : public ::testing::Test {
protected:
  unsigned char rightImage[255];
  unsigned char wrongImage[255];

  void SetUp() override {
    for (int i = 0; i < 255; i++) {rightImage[i] = 0xFF;}
    for (int i = 0; i < 255; i++) {wrongImage[i] = 0xFA;}
    ArduinoFakeReset();
  }
};

TEST_F(FingerprintTests, AuthenticateRightImage_ShouldBeOkay) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  Fingerprint fingerprint;
  fingerprint.init();

  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  fingerprint.getFingerprint()->setImage(rightImage);

  fingerprint.authenticate();


  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, HIGH)).Once();
  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, LOW)).Once();
  Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

TEST_F(FingerprintTests, AuthenticateWrongImage_ShouldError) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  Fingerprint fingerprint;
  fingerprint.init();

  When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  fingerprint.getFingerprint()->setImage(wrongImage);

  fingerprint.authenticate();


  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, HIGH)).Once();
  Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, LOW)).Once();
  Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}