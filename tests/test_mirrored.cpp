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

class MirroredTest : public UnitTest {};

__TEST_U(MirroredTest, test_invalid) {
    __ASSERT_FALSE(unicode::isMirrored(-1));
    __ASSERT_FALSE(unicode::isMirrored(0x7FFFFF));
}

__TEST_U(MirroredTest, test_cases) {
    __ASSERT_FALSE(unicode::isMirrored(0x4E11));
    __ASSERT_TRUE(unicode::isMirrored(0x003C));
    __ASSERT_FALSE(unicode::isMirrored(0x003D));
    __ASSERT_TRUE(unicode::isMirrored(0x003E));
    __ASSERT_FALSE(unicode::isMirrored(0x003F));
}

}  // namespace test
