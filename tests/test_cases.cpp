#include <gtest/gtest.h>
#include "unicode_char.h"

using unicode::getUpperCase;
using unicode::getLowerCase;
using unicode::getTitleCase;

TEST(CasesTest, test_upper) {
    EXPECT_EQ(0, getUpperCase(0));
    EXPECT_EQ(static_cast<int>('A'), getUpperCase(static_cast<int>('a')));
    EXPECT_EQ(static_cast<int>('Z'), getUpperCase(static_cast<int>('z')));
    EXPECT_EQ(static_cast<int>('-'), getUpperCase(static_cast<int>('-')));
    EXPECT_EQ(0x10fffd, getUpperCase(0x10fffd));
}

TEST(CasesTest, test_lower) {
    EXPECT_EQ(0, getLowerCase(0));
    EXPECT_EQ(static_cast<int>('a'), getLowerCase(static_cast<int>('A')));
    EXPECT_EQ(static_cast<int>('z'), getLowerCase(static_cast<int>('Z')));
    EXPECT_EQ(static_cast<int>('-'), getLowerCase(static_cast<int>('-')));
    EXPECT_EQ(0x10fffd, getLowerCase(0x10fffd));
}

TEST(CasesTest, test_title) {
    EXPECT_EQ(0, getTitleCase(0));
    EXPECT_EQ(static_cast<int>('A'), getTitleCase(static_cast<int>('a')));
    EXPECT_EQ(static_cast<int>('Z'), getTitleCase(static_cast<int>('z')));
    EXPECT_EQ(static_cast<int>('-'), getTitleCase(static_cast<int>('-')));
    EXPECT_EQ(0x10fffd, getTitleCase(0x10fffd));
}
