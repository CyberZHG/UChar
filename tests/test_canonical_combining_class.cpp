#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(CanonicalCombiningClassTest, test_invalid) {
    EXPECT_EQ(0, unicode::getCanonicalCombiningClass(-1));
    EXPECT_EQ(0, unicode::getCanonicalCombiningClass(0x7FFFFF));
}

TEST(CanonicalCombiningClassTest, test_interval) {
    EXPECT_EQ(0, unicode::getCanonicalCombiningClass(0x4E11));
}
