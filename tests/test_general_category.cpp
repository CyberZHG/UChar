#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(GeneralCategoryTest, test_first) {
    EXPECT_EQ(unicode::GeneralCategory::Cc, unicode::getGeneralCategory(0));
}

TEST(GeneralCategoryTest, test_last) {
    EXPECT_EQ(unicode::GeneralCategory::Co, unicode::getGeneralCategory(0x10FFFD));
}

TEST(GeneralCategoryTest, test_continuous) {
EXPECT_EQ(unicode::GeneralCategory::Lu, unicode::getGeneralCategory(0x370));
EXPECT_EQ(unicode::GeneralCategory::Ll, unicode::getGeneralCategory(0x378));
}
