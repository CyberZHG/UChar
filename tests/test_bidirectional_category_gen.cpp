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

class BidirectionalCategoryGenTest : public UnitTest {};

__TEST_U(BidirectionalCategoryGenTest, test_cats) {
    __ASSERT_EQ(unicode::BidirectionalCategory::BN, unicode::getBidirectionalCategory(0x0000));
    __ASSERT_EQ(unicode::BidirectionalCategory::S, unicode::getBidirectionalCategory(0x0009));
    __ASSERT_EQ(unicode::BidirectionalCategory::B, unicode::getBidirectionalCategory(0x000A));
    __ASSERT_EQ(unicode::BidirectionalCategory::WS, unicode::getBidirectionalCategory(0x000C));
    __ASSERT_EQ(unicode::BidirectionalCategory::ON, unicode::getBidirectionalCategory(0x0021));
    __ASSERT_EQ(unicode::BidirectionalCategory::ET, unicode::getBidirectionalCategory(0x0023));
    __ASSERT_EQ(unicode::BidirectionalCategory::ES, unicode::getBidirectionalCategory(0x002B));
    __ASSERT_EQ(unicode::BidirectionalCategory::CS, unicode::getBidirectionalCategory(0x002C));
    __ASSERT_EQ(unicode::BidirectionalCategory::EN, unicode::getBidirectionalCategory(0x0030));
    __ASSERT_EQ(unicode::BidirectionalCategory::L, unicode::getBidirectionalCategory(0x0041));
    __ASSERT_EQ(unicode::BidirectionalCategory::NSM, unicode::getBidirectionalCategory(0x0300));
    __ASSERT_EQ(unicode::BidirectionalCategory::R, unicode::getBidirectionalCategory(0x05BE));
    __ASSERT_EQ(unicode::BidirectionalCategory::AN, unicode::getBidirectionalCategory(0x0600));
    __ASSERT_EQ(unicode::BidirectionalCategory::AL, unicode::getBidirectionalCategory(0x0608));
    __ASSERT_EQ(unicode::BidirectionalCategory::LRE, unicode::getBidirectionalCategory(0x202A));
    __ASSERT_EQ(unicode::BidirectionalCategory::RLE, unicode::getBidirectionalCategory(0x202B));
    __ASSERT_EQ(unicode::BidirectionalCategory::PDF, unicode::getBidirectionalCategory(0x202C));
    __ASSERT_EQ(unicode::BidirectionalCategory::LRO, unicode::getBidirectionalCategory(0x202D));
    __ASSERT_EQ(unicode::BidirectionalCategory::RLO, unicode::getBidirectionalCategory(0x202E));
    __ASSERT_EQ(unicode::BidirectionalCategory::LRI, unicode::getBidirectionalCategory(0x2066));
    __ASSERT_EQ(unicode::BidirectionalCategory::RLI, unicode::getBidirectionalCategory(0x2067));
    __ASSERT_EQ(unicode::BidirectionalCategory::FSI, unicode::getBidirectionalCategory(0x2068));
    __ASSERT_EQ(unicode::BidirectionalCategory::PDI, unicode::getBidirectionalCategory(0x2069));
}

}  // namespace test
