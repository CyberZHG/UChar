/* Copyright 2020 Zhao HG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */
#include <cmath>
#include "test.h"
#include "unicode_char.h"

using unicode::getDecimalDigitValue;
using unicode::getDigitValue;
using unicode::getNumericValue;
using unicode::getNumericFraction;

namespace test {

class NumericTest : public UnitTest {};

__TEST_U(NumericTest, test_non_numeric) {
    int code = static_cast<int>('a');
    __ASSERT_EQ(-1, getDecimalDigitValue(code));
    __ASSERT_EQ(-1, getDigitValue(code));
    __ASSERT_TRUE(std::isnan(getNumericValue(code)));
    auto fraction = getNumericFraction(code);
    __ASSERT_EQ(-1, fraction.first);
    __ASSERT_EQ(0, fraction.second);
}

__TEST_U(NumericTest, test_digit) {
    int code = static_cast<int>('3');
    __ASSERT_EQ(3, getDecimalDigitValue(code));
    __ASSERT_EQ(3, getDigitValue(code));
    __ASSERT_NEAR(3.0, getNumericValue(code), 1e-8);
    auto fraction = getNumericFraction(code);
    __ASSERT_EQ(3, fraction.first);
    __ASSERT_EQ(1, fraction.second);
}

__TEST_U(NumericTest, test_negative_half) {
    int code = 0x0F33;
    __ASSERT_EQ(-1, getDecimalDigitValue(code));
    __ASSERT_EQ(-1, getDigitValue(code));
    __ASSERT_NEAR(-0.5, getNumericValue(code), 1e-8);
    auto fraction = getNumericFraction(code);
    __ASSERT_EQ(-1, fraction.first);
    __ASSERT_EQ(2, fraction.second);
}

}  // namespace test
