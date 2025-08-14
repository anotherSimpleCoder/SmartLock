#include <gtest/gtest.h>
#include "DigiAuth.hh"

using DigiAuth::DigiAuthMessage;
using DigiAuth::Status;

TEST(DigiAuthTests, EncodeRightMessage_ShouldBeEqual) {
        auto testMessage = DigiAuthMessage{Status::SUCCESS};
        auto referenceCode = 0b10100001;

        ASSERT_EQ(DigiAuth::encode(testMessage), referenceCode);
}

TEST(DigiAuthTests, EncodeWrongMessage_ShouldBeInequal) {
        auto testMessage = DigiAuthMessage{Status::FAIL};
        auto referenceCode = 0b10100001;

        ASSERT_NE(DigiAuth::encode(testMessage), referenceCode);
}

TEST(DigiAuthTests, DecodeRightMessage_ShouldBeEqual) {
        auto testCode = 0b10100010;
        auto referenceMessage = DigiAuthMessage{Status::FAIL};

        ASSERT_EQ(DigiAuth::decode(testCode), referenceMessage);
}


TEST(DigiAuthtests, DecodeWrongMessage_ShouldBeInequal) {
        auto testCode = 0b10101111;
        auto referenceMessage = DigiAuthMessage{Status::FAIL};

        ASSERT_NE(DigiAuth::decode(testCode), referenceMessage);
}

TEST(DigiAuthtests, DecodeInvalidCode_ShouldBeInequal) {
        auto testCode = 255;
        auto referenceMessage = DigiAuthMessage{Status::SUCCESS};

        ASSERT_NE(DigiAuth::decode(testCode), referenceMessage);
}

TEST(DigiAuthtests, DecodeInvalidCode_ShouldBeInvalid) {
        auto testCode = 255;
        auto referenceMessage = DigiAuthMessage{Status::INVALID};

        ASSERT_EQ(DigiAuth::decode(testCode), referenceMessage);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
