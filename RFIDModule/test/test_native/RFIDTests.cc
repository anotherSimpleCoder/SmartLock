//
// Created by abav on 07.08.2025.
//
#include <gtest/gtest.h>
#include "RFID.hh"
#include "../src/RFID.cc"

using namespace fakeit;

class RFIDTests : public ::testing::Test {
public:
    void SetUp() override {
        ArduinoFakeReset();
    }
};

TEST_F(RFIDTests, CorrectRFIDChip_ShouldBlinkGreen) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();
    When(Method(ArduinoFake(SPI), begin)).AlwaysReturn();
    RFID rfid;
    rfid.init();

    rfid.authenticate();
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}