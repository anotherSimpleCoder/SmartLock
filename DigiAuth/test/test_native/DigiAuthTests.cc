#include <gtest/gtest.h>
#include "DigiAuth.hh"

using DigiAuth::DigiAuthMessage;
using DigiAuth::Status;

TEST(DigiAuthTests, EncodeRightMessage_ShouldBeEqual) {
        auto testMessage = DigiAuthMessage{1,Status::SUCCESS};
        auto referenceCode = 0b10100101;

        ASSERT_EQ(DigiAuth::encode(testMessage), referenceCode);
}

TEST(DigiAuthTests, EncodeWrongMessage_ShouldBeInequal) {
        auto testMessage = DigiAuthMessage{1,Status::START};
        auto referenceCode = 0b10100101;

        ASSERT_NE(DigiAuth::encode(testMessage), referenceCode);
}

TEST(DigiAuthTests, DecodeRightMessage_ShouldBeEqual) {
        auto testCode = 0b10101110;
        auto referenceMessage = DigiAuthMessage{3, Status::FAIL};

        ASSERT_EQ(DigiAuth::decode(testCode), referenceMessage);
}


TEST(DigiAuthtests, DecodeWrongMessage_ShouldBeInequal) {
        auto testCode = 0b10101111;
        auto referenceMessage = DigiAuthMessage{3, Status::FAIL};

        ASSERT_NE(DigiAuth::decode(testCode), referenceMessage);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
