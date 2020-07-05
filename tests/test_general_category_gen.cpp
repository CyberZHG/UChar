#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(GeneralCategoryGenTest, test_cats) {
    EXPECT_EQ(unicode::GeneralCategory::Cc, unicode::getGeneralCategory(0x0000));
    EXPECT_EQ(unicode::GeneralCategory::Zs, unicode::getGeneralCategory(0x0020));
    EXPECT_EQ(unicode::GeneralCategory::Po, unicode::getGeneralCategory(0x0021));
    EXPECT_EQ(unicode::GeneralCategory::Sc, unicode::getGeneralCategory(0x0024));
    EXPECT_EQ(unicode::GeneralCategory::Ps, unicode::getGeneralCategory(0x0028));
    EXPECT_EQ(unicode::GeneralCategory::Pe, unicode::getGeneralCategory(0x0029));
    EXPECT_EQ(unicode::GeneralCategory::Sm, unicode::getGeneralCategory(0x002B));
    EXPECT_EQ(unicode::GeneralCategory::Pd, unicode::getGeneralCategory(0x002D));
    EXPECT_EQ(unicode::GeneralCategory::Nd, unicode::getGeneralCategory(0x0030));
    EXPECT_EQ(unicode::GeneralCategory::Lu, unicode::getGeneralCategory(0x0041));
    EXPECT_EQ(unicode::GeneralCategory::Sk, unicode::getGeneralCategory(0x005E));
    EXPECT_EQ(unicode::GeneralCategory::Pc, unicode::getGeneralCategory(0x005F));
    EXPECT_EQ(unicode::GeneralCategory::Ll, unicode::getGeneralCategory(0x0061));
    EXPECT_EQ(unicode::GeneralCategory::So, unicode::getGeneralCategory(0x00A6));
    EXPECT_EQ(unicode::GeneralCategory::Lo, unicode::getGeneralCategory(0x00AA));
    EXPECT_EQ(unicode::GeneralCategory::Pi, unicode::getGeneralCategory(0x00AB));
    EXPECT_EQ(unicode::GeneralCategory::Cf, unicode::getGeneralCategory(0x00AD));
    EXPECT_EQ(unicode::GeneralCategory::No, unicode::getGeneralCategory(0x00B2));
    EXPECT_EQ(unicode::GeneralCategory::Pf, unicode::getGeneralCategory(0x00BB));
    EXPECT_EQ(unicode::GeneralCategory::Lt, unicode::getGeneralCategory(0x01C5));
    EXPECT_EQ(unicode::GeneralCategory::Lm, unicode::getGeneralCategory(0x02B0));
    EXPECT_EQ(unicode::GeneralCategory::Mn, unicode::getGeneralCategory(0x0300));
    EXPECT_EQ(unicode::GeneralCategory::Me, unicode::getGeneralCategory(0x0488));
    EXPECT_EQ(unicode::GeneralCategory::Mc, unicode::getGeneralCategory(0x0903));
    EXPECT_EQ(unicode::GeneralCategory::Nl, unicode::getGeneralCategory(0x16EE));
    EXPECT_EQ(unicode::GeneralCategory::Zl, unicode::getGeneralCategory(0x2028));
    EXPECT_EQ(unicode::GeneralCategory::Zp, unicode::getGeneralCategory(0x2029));
    EXPECT_EQ(unicode::GeneralCategory::Cs, unicode::getGeneralCategory(0xD800));
    EXPECT_EQ(unicode::GeneralCategory::Co, unicode::getGeneralCategory(0xE000));
}

TEST(GeneralCategoryGenTest, test_base_cats) {
    EXPECT_EQ(unicode::BaseGeneralCategory::C, unicode::getBaseGeneralCategory(0x0000));
    EXPECT_EQ(unicode::BaseGeneralCategory::Z, unicode::getBaseGeneralCategory(0x0020));
    EXPECT_EQ(unicode::BaseGeneralCategory::P, unicode::getBaseGeneralCategory(0x0021));
    EXPECT_EQ(unicode::BaseGeneralCategory::S, unicode::getBaseGeneralCategory(0x0024));
    EXPECT_EQ(unicode::BaseGeneralCategory::N, unicode::getBaseGeneralCategory(0x0030));
    EXPECT_EQ(unicode::BaseGeneralCategory::L, unicode::getBaseGeneralCategory(0x0041));
    EXPECT_EQ(unicode::BaseGeneralCategory::M, unicode::getBaseGeneralCategory(0x0300));
}
