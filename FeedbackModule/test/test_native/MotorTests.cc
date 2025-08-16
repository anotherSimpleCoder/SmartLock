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

TEST_F(MotorTests, RunMotor_ShouldBeOpened) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  Motor motor;
  motor.init();


  ASSERT_EQ(motor.getServo().getAttachedPin(), 8);


  motor.open();

  ASSERT_TRUE(motor.isOpen());
  ASSERT_EQ(motor.getServo().getCurrentPosition(), 0);
}

TEST_F(MotorTests, RunMotor_ShouldBeClosed) {
  When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
  When(Method(ArduinoFake(), delay)).AlwaysReturn();

  Motor motor;
  motor.init();


  ASSERT_EQ(motor.getServo().getAttachedPin(), 8);


  motor.open();

  ASSERT_TRUE(motor.isOpen());
  ASSERT_EQ(motor.getServo().getCurrentPosition(), 0);

  motor.close();
  ASSERT_FALSE(motor.isOpen());
  ASSERT_EQ(motor.getServo().getCurrentPosition(), 90);
}