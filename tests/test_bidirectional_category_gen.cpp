#include <gtest/gtest.h>
#include "unicode_char.h"

TEST(BidirectionalCategoryGenTest, test_cats) {
    EXPECT_EQ(unicode::BidirectionalCategory::BN, unicode::getBidirectionalCategory(0x0000));
    EXPECT_EQ(unicode::BidirectionalCategory::S, unicode::getBidirectionalCategory(0x0009));
    EXPECT_EQ(unicode::BidirectionalCategory::B, unicode::getBidirectionalCategory(0x000A));
    EXPECT_EQ(unicode::BidirectionalCategory::WS, unicode::getBidirectionalCategory(0x000C));
    EXPECT_EQ(unicode::BidirectionalCategory::ON, unicode::getBidirectionalCategory(0x0021));
    EXPECT_EQ(unicode::BidirectionalCategory::ET, unicode::getBidirectionalCategory(0x0023));
    EXPECT_EQ(unicode::BidirectionalCategory::ES, unicode::getBidirectionalCategory(0x002B));
    EXPECT_EQ(unicode::BidirectionalCategory::CS, unicode::getBidirectionalCategory(0x002C));
    EXPECT_EQ(unicode::BidirectionalCategory::EN, unicode::getBidirectionalCategory(0x0030));
    EXPECT_EQ(unicode::BidirectionalCategory::L, unicode::getBidirectionalCategory(0x0041));
    EXPECT_EQ(unicode::BidirectionalCategory::NSM, unicode::getBidirectionalCategory(0x0300));
    EXPECT_EQ(unicode::BidirectionalCategory::R, unicode::getBidirectionalCategory(0x05BE));
    EXPECT_EQ(unicode::BidirectionalCategory::AN, unicode::getBidirectionalCategory(0x0600));
    EXPECT_EQ(unicode::BidirectionalCategory::AL, unicode::getBidirectionalCategory(0x0608));
    EXPECT_EQ(unicode::BidirectionalCategory::LRE, unicode::getBidirectionalCategory(0x202A));
    EXPECT_EQ(unicode::BidirectionalCategory::RLE, unicode::getBidirectionalCategory(0x202B));
    EXPECT_EQ(unicode::BidirectionalCategory::PDF, unicode::getBidirectionalCategory(0x202C));
    EXPECT_EQ(unicode::BidirectionalCategory::LRO, unicode::getBidirectionalCategory(0x202D));
    EXPECT_EQ(unicode::BidirectionalCategory::RLO, unicode::getBidirectionalCategory(0x202E));
    EXPECT_EQ(unicode::BidirectionalCategory::LRI, unicode::getBidirectionalCategory(0x2066));
    EXPECT_EQ(unicode::BidirectionalCategory::RLI, unicode::getBidirectionalCategory(0x2067));
    EXPECT_EQ(unicode::BidirectionalCategory::FSI, unicode::getBidirectionalCategory(0x2068));
    EXPECT_EQ(unicode::BidirectionalCategory::PDI, unicode::getBidirectionalCategory(0x2069));
}
