//
// Created by abav on 07.08.2025.
//
#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "RFID.hh"
#include "../../src/RFID.cc"

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

TEST_F(RFIDTests, CorrectRFIDChip_ShouldBeSuccessful) {
    When(Method(ArduinoFake(SPI), begin)).AlwaysReturn();
    RFID rfid;
    rfid.init();

    rfid.getSensor()->readCard(rightCard);
    rfid.authenticate();

    ASSERT_TRUE(Wire.contains(DigiAuth::encode({0, DigiAuth::Status::SUCCESS})));
}

TEST_F(RFIDTests, WrongRFIDChip_ShouldError) {
    When(Method(ArduinoFake(SPI), begin)).AlwaysReturn();
    RFID rfid;
    rfid.init();

    rfid.getSensor()->readCard(wrongCard);
    rfid.authenticate();

    ASSERT_TRUE(Wire.contains(DigiAuth::encode({0, DigiAuth::Status::FAIL})));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}