#include <iostream>
#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "Motor.hh"
#include "../../src/Motor.cc"

using namespace fakeit;

class MotorTests : public ::testing::Test {
protected:
  void SetUp() override {
    ArduinoFakeReset();
  }
};

TEST_F(MotorTests, RunMotor_ShouldBeZero) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  Motor motor;
  motor.init();


  ASSERT_EQ(motor.getServo().getAttachedPin(), 9);


  motor.run();


  Verify(Method(ArduinoFake(), delay).Using(5)).Exactly(362);
  Verify(Method(ArduinoFake(), delay).Using(100)).Once();
  ASSERT_EQ(motor.getServo().getCurrentPosition(), 0);
}