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

class EncodeTest : public UnitTest {};

__TEST_U(EncodeTest, test_utf8) {
    __ASSERT_EQ(64, unicode::fromUTF8Char(unicode::toUTF8(64)));
    __ASSERT_EQ(0x7ff - 9, unicode::fromUTF8Char(unicode::toUTF8(0x7ff - 9)));
    __ASSERT_EQ(0xffff - 10, unicode::fromUTF8Char(unicode::toUTF8(0xffff - 10)));
    __ASSERT_EQ(0x1fffff - 11, unicode::fromUTF8Char(unicode::toUTF8(0x1fffff - 11)));
    __ASSERT_EQ(0x3ffffff - 12, unicode::fromUTF8Char(unicode::toUTF8(0x3ffffff - 12)));
    __ASSERT_EQ(0x7fffffff - 13, unicode::fromUTF8Char(unicode::toUTF8(0x7fffffff - 13)));
}

__TEST_U(EncodeTest, test_utf8_invalid) {
    __ASSERT_THROW(unicode::toUTF8(-10), std::runtime_error);
    __ASSERT_THROW(unicode::fromUTF8Char(""), std::runtime_error);
    auto str = unicode::toUTF8(0x7fffff);
    str.pop_back();
    __ASSERT_THROW(unicode::fromUTF8Char(str), std::runtime_error);
}

__TEST_U(EncodeTest, test_utf8_string) {
    std::string str;
    str += static_cast<char>(0xef);
    str += static_cast<char>(0xbb);
    str += static_cast<char>(0xbf);
    str += unicode::toUTF8(std::vector<int32_t>{
        0xffff - 14,
        0x7fffffff - 15,
        0x7f - 16,
    });
    auto codes = unicode::fromUTF8(str);
    __ASSERT_EQ(3u, codes.size());
    __ASSERT_EQ(0xffff - 14, codes[0]);
    __ASSERT_EQ(0x7fffffff - 15, codes[1]);
    __ASSERT_EQ(0x7f - 16, codes[2]);
}

__TEST_U(EncodeTest, test_utf16) {
    std::vector<int32_t> codes = {0x10016, 0x6f};
    auto gen = unicode::fromUTF16(unicode::toUTF16(codes));
    __ASSERT_EQ(2u, gen.size());
    __ASSERT_EQ(codes[0], gen[0]);
    __ASSERT_EQ(codes[1], gen[1]);
}

}  // namespace test
