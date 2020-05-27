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
#include "test.h"
#include "unicode_char.h"

using unicode::getUpperCase;
using unicode::getLowerCase;
using unicode::getTitleCase;

namespace test {

class CasesTest : public UnitTest {};

__TEST_U(CasesTest, test_upper) {
    __ASSERT_EQ(0, getUpperCase(0));
    __ASSERT_EQ(static_cast<int>('A'), getUpperCase(static_cast<int>('a')));
    __ASSERT_EQ(static_cast<int>('Z'), getUpperCase(static_cast<int>('z')));
    __ASSERT_EQ(static_cast<int>('-'), getUpperCase(static_cast<int>('-')));
    __ASSERT_EQ(0x10fffd, getUpperCase(0x10fffd));
}

__TEST_U(CasesTest, test_lower) {
    __ASSERT_EQ(0, getLowerCase(0));
    __ASSERT_EQ(static_cast<int>('a'), getLowerCase(static_cast<int>('A')));
    __ASSERT_EQ(static_cast<int>('z'), getLowerCase(static_cast<int>('Z')));
    __ASSERT_EQ(static_cast<int>('-'), getLowerCase(static_cast<int>('-')));
    __ASSERT_EQ(0x10fffd, getLowerCase(0x10fffd));
}

__TEST_U(CasesTest, test_title) {
    __ASSERT_EQ(0, getTitleCase(0));
    __ASSERT_EQ(static_cast<int>('A'), getTitleCase(static_cast<int>('a')));
    __ASSERT_EQ(static_cast<int>('Z'), getTitleCase(static_cast<int>('z')));
    __ASSERT_EQ(static_cast<int>('-'), getTitleCase(static_cast<int>('-')));
    __ASSERT_EQ(0x10fffd, getTitleCase(0x10fffd));
}

}  // namespace test
