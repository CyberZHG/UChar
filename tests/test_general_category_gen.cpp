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

class GeneralCategoryGenTest : public UnitTest {};

__TEST_U(GeneralCategoryGenTest, test_cats) {
    __ASSERT_EQ(unicode::GeneralCategory::Cc, unicode::getGeneralCategory(0x0000));
    __ASSERT_EQ(unicode::GeneralCategory::Zs, unicode::getGeneralCategory(0x0020));
    __ASSERT_EQ(unicode::GeneralCategory::Po, unicode::getGeneralCategory(0x0021));
    __ASSERT_EQ(unicode::GeneralCategory::Sc, unicode::getGeneralCategory(0x0024));
    __ASSERT_EQ(unicode::GeneralCategory::Ps, unicode::getGeneralCategory(0x0028));
    __ASSERT_EQ(unicode::GeneralCategory::Pe, unicode::getGeneralCategory(0x0029));
    __ASSERT_EQ(unicode::GeneralCategory::Sm, unicode::getGeneralCategory(0x002B));
    __ASSERT_EQ(unicode::GeneralCategory::Pd, unicode::getGeneralCategory(0x002D));
    __ASSERT_EQ(unicode::GeneralCategory::Nd, unicode::getGeneralCategory(0x0030));
    __ASSERT_EQ(unicode::GeneralCategory::Lu, unicode::getGeneralCategory(0x0041));
    __ASSERT_EQ(unicode::GeneralCategory::Sk, unicode::getGeneralCategory(0x005E));
    __ASSERT_EQ(unicode::GeneralCategory::Pc, unicode::getGeneralCategory(0x005F));
    __ASSERT_EQ(unicode::GeneralCategory::Ll, unicode::getGeneralCategory(0x0061));
    __ASSERT_EQ(unicode::GeneralCategory::So, unicode::getGeneralCategory(0x00A6));
    __ASSERT_EQ(unicode::GeneralCategory::Lo, unicode::getGeneralCategory(0x00AA));
    __ASSERT_EQ(unicode::GeneralCategory::Pi, unicode::getGeneralCategory(0x00AB));
    __ASSERT_EQ(unicode::GeneralCategory::Cf, unicode::getGeneralCategory(0x00AD));
    __ASSERT_EQ(unicode::GeneralCategory::No, unicode::getGeneralCategory(0x00B2));
    __ASSERT_EQ(unicode::GeneralCategory::Pf, unicode::getGeneralCategory(0x00BB));
    __ASSERT_EQ(unicode::GeneralCategory::Lt, unicode::getGeneralCategory(0x01C5));
    __ASSERT_EQ(unicode::GeneralCategory::Lm, unicode::getGeneralCategory(0x02B0));
    __ASSERT_EQ(unicode::GeneralCategory::Mn, unicode::getGeneralCategory(0x0300));
    __ASSERT_EQ(unicode::GeneralCategory::Me, unicode::getGeneralCategory(0x0488));
    __ASSERT_EQ(unicode::GeneralCategory::Mc, unicode::getGeneralCategory(0x0903));
    __ASSERT_EQ(unicode::GeneralCategory::Nl, unicode::getGeneralCategory(0x16EE));
    __ASSERT_EQ(unicode::GeneralCategory::Zl, unicode::getGeneralCategory(0x2028));
    __ASSERT_EQ(unicode::GeneralCategory::Zp, unicode::getGeneralCategory(0x2029));
    __ASSERT_EQ(unicode::GeneralCategory::Cs, unicode::getGeneralCategory(0xD800));
    __ASSERT_EQ(unicode::GeneralCategory::Co, unicode::getGeneralCategory(0xE000));
}

__TEST_U(GeneralCategoryGenTest, test_base_cats) {
    __ASSERT_EQ(unicode::BaseGeneralCategory::C, unicode::getBaseGeneralCategory(0x0000));
    __ASSERT_EQ(unicode::BaseGeneralCategory::Z, unicode::getBaseGeneralCategory(0x0020));
    __ASSERT_EQ(unicode::BaseGeneralCategory::P, unicode::getBaseGeneralCategory(0x0021));
    __ASSERT_EQ(unicode::BaseGeneralCategory::S, unicode::getBaseGeneralCategory(0x0024));
    __ASSERT_EQ(unicode::BaseGeneralCategory::N, unicode::getBaseGeneralCategory(0x0030));
    __ASSERT_EQ(unicode::BaseGeneralCategory::L, unicode::getBaseGeneralCategory(0x0041));
    __ASSERT_EQ(unicode::BaseGeneralCategory::M, unicode::getBaseGeneralCategory(0x0300));
}

}  // namespace test
