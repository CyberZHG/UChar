#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(EncodeTest, test_utf8) {
    EXPECT_EQ(64, unicode::fromUTF8Char(unicode::toUTF8(64)));
    EXPECT_EQ(0x7ff - 9, unicode::fromUTF8Char(unicode::toUTF8(0x7ff - 9)));
    EXPECT_EQ(0xffff - 10, unicode::fromUTF8Char(unicode::toUTF8(0xffff - 10)));
    EXPECT_EQ(0x1fffff - 11, unicode::fromUTF8Char(unicode::toUTF8(0x1fffff - 11)));
    EXPECT_EQ(0x3ffffff - 12, unicode::fromUTF8Char(unicode::toUTF8(0x3ffffff - 12)));
    EXPECT_EQ(0x7fffffff - 13, unicode::fromUTF8Char(unicode::toUTF8(0x7fffffff - 13)));
}

TEST(EncodeTest, test_utf8_invalid) {
    EXPECT_THROW(unicode::toUTF8(-10), std::runtime_error);
    EXPECT_THROW(unicode::fromUTF8Char(""), std::runtime_error);
    auto str = unicode::toUTF8(0x7fffff);
    str.pop_back();
    EXPECT_THROW(unicode::fromUTF8Char(str), std::runtime_error);
}

TEST(EncodeTest, test_utf8_string) {
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
    EXPECT_EQ(3u, codes.size());
    EXPECT_EQ(0xffff - 14, codes[0]);
    EXPECT_EQ(0x7fffffff - 15, codes[1]);
    EXPECT_EQ(0x7f - 16, codes[2]);
}

TEST(EncodeTest, test_utf16) {
    std::vector<int32_t> codes = {0x10016, 0x6f};
    auto gen = unicode::fromUTF16(unicode::toUTF16(codes));
    EXPECT_EQ(2u, gen.size());
    EXPECT_EQ(codes[0], gen[0]);
    EXPECT_EQ(codes[1], gen[1]);
}
