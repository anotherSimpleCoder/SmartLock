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

  Fingerprint fingerprint;
  fingerprint.init();

  fingerprint.getFingerprint()->setImage(rightImage);

  fingerprint.authenticate();

  ASSERT_TRUE(Wire.contains(DigiAuth::encode({DigiAuth::Status::SUCCESS})));
}

TEST_F(FingerprintTests, AuthenticateWrongImage_ShouldError) {
  Fingerprint fingerprint;
  fingerprint.init();


  fingerprint.getFingerprint()->setImage(wrongImage);

  fingerprint.authenticate();

  ASSERT_TRUE(Wire.contains(DigiAuth::encode({DigiAuth::Status::FAIL})));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}