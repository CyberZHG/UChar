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

namespace test {

class CanonicalCombiningClassGenTest : public UnitTest {};

__TEST_U(CanonicalCombiningClassGenTest, test_classes) {
    __ASSERT_EQ(0, unicode::getCanonicalCombiningClass(0x1E94B));
    __ASSERT_EQ(230, unicode::getCanonicalCombiningClass(0x1E944));
    __ASSERT_EQ(232, unicode::getCanonicalCombiningClass(0x302C));
    __ASSERT_EQ(220, unicode::getCanonicalCombiningClass(0x1E8D0));
    __ASSERT_EQ(216, unicode::getCanonicalCombiningClass(0x1D16E));
    __ASSERT_EQ(202, unicode::getCanonicalCombiningClass(0x1DD0));
    __ASSERT_EQ(1, unicode::getCanonicalCombiningClass(0x1D167));
    __ASSERT_EQ(240, unicode::getCanonicalCombiningClass(0x0345));
    __ASSERT_EQ(233, unicode::getCanonicalCombiningClass(0x1DFC));
    __ASSERT_EQ(234, unicode::getCanonicalCombiningClass(0x1DCD));
    __ASSERT_EQ(222, unicode::getCanonicalCombiningClass(0x302D));
    __ASSERT_EQ(228, unicode::getCanonicalCombiningClass(0x302B));
    __ASSERT_EQ(10, unicode::getCanonicalCombiningClass(0x05B0));
    __ASSERT_EQ(11, unicode::getCanonicalCombiningClass(0x05B1));
    __ASSERT_EQ(12, unicode::getCanonicalCombiningClass(0x05B2));
    __ASSERT_EQ(13, unicode::getCanonicalCombiningClass(0x05B3));
    __ASSERT_EQ(14, unicode::getCanonicalCombiningClass(0x05B4));
    __ASSERT_EQ(15, unicode::getCanonicalCombiningClass(0x05B5));
    __ASSERT_EQ(16, unicode::getCanonicalCombiningClass(0x05B6));
    __ASSERT_EQ(17, unicode::getCanonicalCombiningClass(0x05B7));
    __ASSERT_EQ(18, unicode::getCanonicalCombiningClass(0x05C7));
    __ASSERT_EQ(19, unicode::getCanonicalCombiningClass(0x05B9));
    __ASSERT_EQ(20, unicode::getCanonicalCombiningClass(0x05BB));
    __ASSERT_EQ(21, unicode::getCanonicalCombiningClass(0x05BC));
    __ASSERT_EQ(22, unicode::getCanonicalCombiningClass(0x05BD));
    __ASSERT_EQ(23, unicode::getCanonicalCombiningClass(0x05BF));
    __ASSERT_EQ(24, unicode::getCanonicalCombiningClass(0x05C1));
    __ASSERT_EQ(25, unicode::getCanonicalCombiningClass(0x05C2));
    __ASSERT_EQ(30, unicode::getCanonicalCombiningClass(0x064E));
    __ASSERT_EQ(31, unicode::getCanonicalCombiningClass(0x064F));
    __ASSERT_EQ(32, unicode::getCanonicalCombiningClass(0x0650));
    __ASSERT_EQ(27, unicode::getCanonicalCombiningClass(0x08F0));
    __ASSERT_EQ(28, unicode::getCanonicalCombiningClass(0x08F1));
    __ASSERT_EQ(29, unicode::getCanonicalCombiningClass(0x08F2));
    __ASSERT_EQ(33, unicode::getCanonicalCombiningClass(0x0651));
    __ASSERT_EQ(34, unicode::getCanonicalCombiningClass(0x0652));
    __ASSERT_EQ(35, unicode::getCanonicalCombiningClass(0x0670));
    __ASSERT_EQ(36, unicode::getCanonicalCombiningClass(0x0711));
    __ASSERT_EQ(7, unicode::getCanonicalCombiningClass(0x1E94A));
    __ASSERT_EQ(9, unicode::getCanonicalCombiningClass(0x11D97));
    __ASSERT_EQ(84, unicode::getCanonicalCombiningClass(0x0C55));
    __ASSERT_EQ(91, unicode::getCanonicalCombiningClass(0x0C56));
    __ASSERT_EQ(103, unicode::getCanonicalCombiningClass(0x0E38));
    __ASSERT_EQ(107, unicode::getCanonicalCombiningClass(0x0E48));
    __ASSERT_EQ(118, unicode::getCanonicalCombiningClass(0x0EB8));
    __ASSERT_EQ(122, unicode::getCanonicalCombiningClass(0x0EC8));
    __ASSERT_EQ(129, unicode::getCanonicalCombiningClass(0x0F71));
    __ASSERT_EQ(130, unicode::getCanonicalCombiningClass(0x0F80));
    __ASSERT_EQ(132, unicode::getCanonicalCombiningClass(0x0F74));
    __ASSERT_EQ(214, unicode::getCanonicalCombiningClass(0x1DCE));
    __ASSERT_EQ(218, unicode::getCanonicalCombiningClass(0x302A));
    __ASSERT_EQ(224, unicode::getCanonicalCombiningClass(0x302E));
    __ASSERT_EQ(8, unicode::getCanonicalCombiningClass(0x3099));
    __ASSERT_EQ(26, unicode::getCanonicalCombiningClass(0xFB1E));
    __ASSERT_EQ(6, unicode::getCanonicalCombiningClass(0x16FF0));
    __ASSERT_EQ(226, unicode::getCanonicalCombiningClass(0x1D16D));
}

}  // namespace test
