#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(MirroredTest, test_invalid) {
    EXPECT_FALSE(unicode::isMirrored(-1));
    EXPECT_FALSE(unicode::isMirrored(0x7FFFFF));
}

TEST(MirroredTest, test_cases) {
    EXPECT_FALSE(unicode::isMirrored(0x4E11));
    EXPECT_TRUE(unicode::isMirrored(0x003C));
    EXPECT_FALSE(unicode::isMirrored(0x003D));
    EXPECT_TRUE(unicode::isMirrored(0x003E));
    EXPECT_FALSE(unicode::isMirrored(0x003F));
}
