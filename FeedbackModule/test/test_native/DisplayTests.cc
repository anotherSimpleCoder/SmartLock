//
// Created by amsakan on 17.08.25.
//
#include <iostream>
#include <string.h>
#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "Display.hh"
#include "../../src/Display.cc"

using namespace fakeit;

class DisplayTests : public ::testing::Test {
protected:
    void SetUp() override {
        ArduinoFakeReset();
    }
};

TEST_F(DisplayTests, DisplaySuccessMessage_ShouldBeEqual) {
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    Display display;
    display.init();

    display.successMessage();
    ASSERT_EQ(strcmp(display.getDisplay()->getDisplayedMessage(), "Access granted"), 0);
}

TEST_F(DisplayTests, DisplayFailMessage_ShouldBeEqual) {
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    Display display;
    display.init();

    display.failMessage();
    ASSERT_EQ(strcmp(display.getDisplay()->getDisplayedMessage(), "Access denied"), 0);
}