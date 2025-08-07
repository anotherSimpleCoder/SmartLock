//
// Created by amsakan on 06.08.25.
//
#include <gtest/gtest.h>

#include "../../lib/Strings/Strings.hh"

TEST(StringsTests, CompareUnequalStrings_ShouldBeInequal) {
    const char testString1[5] = "1419";
    const char testString2[5] = "1913";

    ASSERT_FALSE(Strings::equals(testString1, testString2));
}

TEST(StringsTests, CompareEqualString_ShouldBeEqual) {
    const char testString1[5] = "1419";
    const char testString2[5] = "1419";

    ASSERT_TRUE(Strings::equals(testString1, testString2));
}

TEST(StringsTests, ClearString_ShouldBeEqmpty) {
    char testString[5] = "1419";
    Strings::clear(testString);
    bool equal = false;


    for (int i = 0; i < 4; i++) {
        equal = testString[i] == '\0';
    }

    ASSERT_TRUE(equal);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}