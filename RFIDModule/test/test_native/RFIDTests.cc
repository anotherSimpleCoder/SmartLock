//
// Created by abav on 07.08.2025.
//
#include <gtest/gtest.h>
#include "RFID.hh"
#include "../src/RFID.cc"

using namespace fakeit;

class RFIDTests : public ::testing::Test {
protected:
  unsigned char rightCard[7];
  unsigned char wrongCard[7];
public:
    void SetUp() override {
        for(int i = 0; i < 7; i++) {rightCard[i] = 0xFF;}
        for(int i = 0; i < 7; i++) {wrongCard[i] = 0xFA;}
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

    rfid.getSensor()->readCard(rightCard);
    rfid.authenticate();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

TEST_F(RFIDTests, WrongRFIDChip_ShouldBlinkRed) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();
    When(Method(ArduinoFake(SPI), begin)).AlwaysReturn();
    RFID rfid;
    rfid.init();

    rfid.getSensor()->readCard(wrongCard);
    rfid.authenticate();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}