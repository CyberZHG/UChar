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

class DecompositionMappingGenTest : public UnitTest {};

__TEST_U(DecompositionMappingGenTest, test_cats) {
    unicode::UChar buffer[16];
    __ASSERT_EQ(unicode::DecompositionMappingTag::NO_MAPPING, unicode::getDecompositionMappingTag(0x0000)); {
        auto decomposition = unicode::getDecompositionMapping(0x0000);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0000, decomposition[0]);
        unicode::getDecompositionMapping(0x0000, buffer);
        __ASSERT_EQ(0x0000, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::NOBREAK, unicode::getDecompositionMappingTag(0x00A0)); {
        auto decomposition = unicode::getDecompositionMapping(0x00A0);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0020, decomposition[0]);
        unicode::getDecompositionMapping(0x00A0, buffer);
        __ASSERT_EQ(0x0020, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::COMPAT, unicode::getDecompositionMappingTag(0x00A8)); {
        auto decomposition = unicode::getDecompositionMapping(0x00A8);
        __ASSERT_EQ(2u, decomposition.size());
        __ASSERT_EQ(0x0020, decomposition[0]);
        __ASSERT_EQ(0x0308, decomposition[1]);
        unicode::getDecompositionMapping(0x00A8, buffer);
        __ASSERT_EQ(0x0020, buffer[0]);
        __ASSERT_EQ(0x0308, buffer[1]);
        __ASSERT_EQ(0, buffer[2]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::SUPER, unicode::getDecompositionMappingTag(0x00AA)); {
        auto decomposition = unicode::getDecompositionMapping(0x00AA);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0061, decomposition[0]);
        unicode::getDecompositionMapping(0x00AA, buffer);
        __ASSERT_EQ(0x0061, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::FRACTION, unicode::getDecompositionMappingTag(0x00BC)); {
        auto decomposition = unicode::getDecompositionMapping(0x00BC);
        __ASSERT_EQ(3u, decomposition.size());
        __ASSERT_EQ(0x0031, decomposition[0]);
        __ASSERT_EQ(0x2044, decomposition[1]);
        __ASSERT_EQ(0x0034, decomposition[2]);
        unicode::getDecompositionMapping(0x00BC, buffer);
        __ASSERT_EQ(0x0031, buffer[0]);
        __ASSERT_EQ(0x2044, buffer[1]);
        __ASSERT_EQ(0x0034, buffer[2]);
        __ASSERT_EQ(0, buffer[3]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::CANONICAL, unicode::getDecompositionMappingTag(0x00C0)); {
        auto decomposition = unicode::getDecompositionMapping(0x00C0);
        __ASSERT_EQ(2u, decomposition.size());
        __ASSERT_EQ(0x0041, decomposition[0]);
        __ASSERT_EQ(0x0300, decomposition[1]);
        unicode::getDecompositionMapping(0x00C0, buffer);
        __ASSERT_EQ(0x0041, buffer[0]);
        __ASSERT_EQ(0x0300, buffer[1]);
        __ASSERT_EQ(0, buffer[2]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::SUB, unicode::getDecompositionMappingTag(0x1D62)); {
        auto decomposition = unicode::getDecompositionMapping(0x1D62);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0069, decomposition[0]);
        unicode::getDecompositionMapping(0x1D62, buffer);
        __ASSERT_EQ(0x0069, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::FONT, unicode::getDecompositionMappingTag(0x2102)); {
        auto decomposition = unicode::getDecompositionMapping(0x2102);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0043, decomposition[0]);
        unicode::getDecompositionMapping(0x2102, buffer);
        __ASSERT_EQ(0x0043, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::CIRCLE, unicode::getDecompositionMappingTag(0x2460)); {
        auto decomposition = unicode::getDecompositionMapping(0x2460);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0031, decomposition[0]);
        unicode::getDecompositionMapping(0x2460, buffer);
        __ASSERT_EQ(0x0031, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::WIDE, unicode::getDecompositionMappingTag(0x3000)); {
        auto decomposition = unicode::getDecompositionMapping(0x3000);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0020, decomposition[0]);
        unicode::getDecompositionMapping(0x3000, buffer);
        __ASSERT_EQ(0x0020, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::VERTICAL, unicode::getDecompositionMappingTag(0x309F)); {
        auto decomposition = unicode::getDecompositionMapping(0x309F);
        __ASSERT_EQ(2u, decomposition.size());
        __ASSERT_EQ(0x3088, decomposition[0]);
        __ASSERT_EQ(0x308A, decomposition[1]);
        unicode::getDecompositionMapping(0x309F, buffer);
        __ASSERT_EQ(0x3088, buffer[0]);
        __ASSERT_EQ(0x308A, buffer[1]);
        __ASSERT_EQ(0, buffer[2]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::SQUARE, unicode::getDecompositionMappingTag(0x3250)); {
        auto decomposition = unicode::getDecompositionMapping(0x3250);
        __ASSERT_EQ(3u, decomposition.size());
        __ASSERT_EQ(0x0050, decomposition[0]);
        __ASSERT_EQ(0x0054, decomposition[1]);
        __ASSERT_EQ(0x0045, decomposition[2]);
        unicode::getDecompositionMapping(0x3250, buffer);
        __ASSERT_EQ(0x0050, buffer[0]);
        __ASSERT_EQ(0x0054, buffer[1]);
        __ASSERT_EQ(0x0045, buffer[2]);
        __ASSERT_EQ(0, buffer[3]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::ISOLATED, unicode::getDecompositionMappingTag(0xFB50)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB50);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0671, decomposition[0]);
        unicode::getDecompositionMapping(0xFB50, buffer);
        __ASSERT_EQ(0x0671, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::FINAL, unicode::getDecompositionMappingTag(0xFB51)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB51);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x0671, decomposition[0]);
        unicode::getDecompositionMapping(0xFB51, buffer);
        __ASSERT_EQ(0x0671, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::INITIAL, unicode::getDecompositionMappingTag(0xFB54)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB54);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x067B, decomposition[0]);
        unicode::getDecompositionMapping(0xFB54, buffer);
        __ASSERT_EQ(0x067B, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::MEDIAL, unicode::getDecompositionMappingTag(0xFB55)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB55);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x067B, decomposition[0]);
        unicode::getDecompositionMapping(0xFB55, buffer);
        __ASSERT_EQ(0x067B, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::SMALL, unicode::getDecompositionMappingTag(0xFE50)); {
        auto decomposition = unicode::getDecompositionMapping(0xFE50);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x002C, decomposition[0]);
        unicode::getDecompositionMapping(0xFE50, buffer);
        __ASSERT_EQ(0x002C, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
    __ASSERT_EQ(unicode::DecompositionMappingTag::NARROW, unicode::getDecompositionMappingTag(0xFF61)); {
        auto decomposition = unicode::getDecompositionMapping(0xFF61);
        __ASSERT_EQ(1u, decomposition.size());
        __ASSERT_EQ(0x3002, decomposition[0]);
        unicode::getDecompositionMapping(0xFF61, buffer);
        __ASSERT_EQ(0x3002, buffer[0]);
        __ASSERT_EQ(0, buffer[1]);
    }
}

}  // namespace test
