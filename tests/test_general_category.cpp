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

class GeneralCategoryTest : public UnitTest {};

__TEST_U(GeneralCategoryTest, test_first) {
    __ASSERT_EQ(unicode::GeneralCategory::Cc, unicode::getGeneralCategory(0));
}

__TEST_U(GeneralCategoryTest, test_last) {
    __ASSERT_EQ(unicode::GeneralCategory::Co, unicode::getGeneralCategory(0x10FFFD));
}

__TEST_U(GeneralCategoryTest, test_continuous) {
__ASSERT_EQ(unicode::GeneralCategory::Lu, unicode::getGeneralCategory(0x370));
__ASSERT_EQ(unicode::GeneralCategory::Ll, unicode::getGeneralCategory(0x378));
}

}  // namespace test
