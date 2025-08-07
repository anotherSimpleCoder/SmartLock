#include <gtest/gtest.h>
#include <ArduinoFake.h>
#include "LEDS.hh"
#include "../../src/LEDS.cc"

using namespace fakeit;

class LEDSTests : public ::testing::Test {
protected:
    void SetUp() override {
        ArduinoFakeReset();
    }
};

TEST_F(LEDSTests, BlinkRed_ShouldBeOkay) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    LEDS leds;
    leds.init();

    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    leds.redBlink();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::RED_LED_PIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

TEST_F(LEDSTests, BlinkGreen_ShouldBeOkay) {
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    LEDS leds;
    leds.init();

    When(Method(ArduinoFake(), digitalWrite)).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    leds.greenBlink();

    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LEDS::GREEN_LED_PIN, LOW)).Once();
    Verify(Method(ArduinoFake(), delay).Using(2000)).Exactly(2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}