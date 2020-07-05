#include <cmath>
#include <gtest/gtest.h>
#include "unicode_char.h"

using unicode::getDecimalDigitValue;
using unicode::getDigitValue;
using unicode::getNumericValue;
using unicode::getNumericFraction;

TEST(NumericTest, test_non_numeric) {
    int code = static_cast<int>('a');
    EXPECT_EQ(-1, getDecimalDigitValue(code));
    EXPECT_EQ(-1, getDigitValue(code));
    EXPECT_TRUE(std::isnan(getNumericValue(code)));
    auto fraction = getNumericFraction(code);
    EXPECT_EQ(-1, fraction.first);
    EXPECT_EQ(0, fraction.second);
}

TEST(NumericTest, test_digit) {
    int code = static_cast<int>('3');
    EXPECT_EQ(3, getDecimalDigitValue(code));
    EXPECT_EQ(3, getDigitValue(code));
    EXPECT_NEAR(3.0, getNumericValue(code), 1e-8);
    auto fraction = getNumericFraction(code);
    EXPECT_EQ(3, fraction.first);
    EXPECT_EQ(1, fraction.second);
}

TEST(NumericTest, test_negative_half) {
    int code = 0x0F33;
    EXPECT_EQ(-1, getDecimalDigitValue(code));
    EXPECT_EQ(-1, getDigitValue(code));
    EXPECT_NEAR(-0.5, getNumericValue(code), 1e-8);
    auto fraction = getNumericFraction(code);
    EXPECT_EQ(-1, fraction.first);
    EXPECT_EQ(2, fraction.second);
}
