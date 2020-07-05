#include <gtest/gtest.h>
#include <sstream>
#include <ranges>
#include <cctype>
#include "unicode_char.h"

TEST(DecompositionMappingGenTest, test_cats) {
    unicode::UChar buffer[16];
    auto toUpper = [](const std::string& text) {
        auto output = text;
        std::ranges::transform(output, output.begin(), [](const auto c){ return std::toupper(c); });
        return output;
    };
    EXPECT_EQ(unicode::DecompositionMappingTag::NO_MAPPING, unicode::getDecompositionMappingTag(0x0000)); {
        auto decomposition = unicode::getDecompositionMapping(0x0000);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0000, decomposition[0]);
        unicode::getDecompositionMapping(0x0000, buffer);
        EXPECT_EQ(0x0000, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::NO_MAPPING;
         EXPECT_EQ(std::string(), ss.str());
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::NOBREAK, unicode::getDecompositionMappingTag(0x00A0)); {
        auto decomposition = unicode::getDecompositionMapping(0x00A0);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0020, decomposition[0]);
        unicode::getDecompositionMapping(0x00A0, buffer);
        EXPECT_EQ(0x0020, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::NOBREAK;
        EXPECT_EQ("NOBREAK", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::COMPAT, unicode::getDecompositionMappingTag(0x00A8)); {
        auto decomposition = unicode::getDecompositionMapping(0x00A8);
        EXPECT_EQ(2u, decomposition.size());
        EXPECT_EQ(0x0020, decomposition[0]);
        EXPECT_EQ(0x0308, decomposition[1]);
        unicode::getDecompositionMapping(0x00A8, buffer);
        EXPECT_EQ(0x0020, buffer[0]);
        EXPECT_EQ(0x0308, buffer[1]);
        EXPECT_EQ(0, buffer[2]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::COMPAT;
        EXPECT_EQ("COMPAT", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::SUPER, unicode::getDecompositionMappingTag(0x00AA)); {
        auto decomposition = unicode::getDecompositionMapping(0x00AA);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0061, decomposition[0]);
        unicode::getDecompositionMapping(0x00AA, buffer);
        EXPECT_EQ(0x0061, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::SUPER;
        EXPECT_EQ("SUPER", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::FRACTION, unicode::getDecompositionMappingTag(0x00BC)); {
        auto decomposition = unicode::getDecompositionMapping(0x00BC);
        EXPECT_EQ(3u, decomposition.size());
        EXPECT_EQ(0x0031, decomposition[0]);
        EXPECT_EQ(0x2044, decomposition[1]);
        EXPECT_EQ(0x0034, decomposition[2]);
        unicode::getDecompositionMapping(0x00BC, buffer);
        EXPECT_EQ(0x0031, buffer[0]);
        EXPECT_EQ(0x2044, buffer[1]);
        EXPECT_EQ(0x0034, buffer[2]);
        EXPECT_EQ(0, buffer[3]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::FRACTION;
        EXPECT_EQ("FRACTION", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::CANONICAL, unicode::getDecompositionMappingTag(0x00C0)); {
        auto decomposition = unicode::getDecompositionMapping(0x00C0);
        EXPECT_EQ(2u, decomposition.size());
        EXPECT_EQ(0x0041, decomposition[0]);
        EXPECT_EQ(0x0300, decomposition[1]);
        unicode::getDecompositionMapping(0x00C0, buffer);
        EXPECT_EQ(0x0041, buffer[0]);
        EXPECT_EQ(0x0300, buffer[1]);
        EXPECT_EQ(0, buffer[2]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::CANONICAL;
        EXPECT_EQ("CANONICAL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::SUB, unicode::getDecompositionMappingTag(0x1D62)); {
        auto decomposition = unicode::getDecompositionMapping(0x1D62);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0069, decomposition[0]);
        unicode::getDecompositionMapping(0x1D62, buffer);
        EXPECT_EQ(0x0069, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::SUB;
        EXPECT_EQ("SUB", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::FONT, unicode::getDecompositionMappingTag(0x2102)); {
        auto decomposition = unicode::getDecompositionMapping(0x2102);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0043, decomposition[0]);
        unicode::getDecompositionMapping(0x2102, buffer);
        EXPECT_EQ(0x0043, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::FONT;
        EXPECT_EQ("FONT", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::CIRCLE, unicode::getDecompositionMappingTag(0x2460)); {
        auto decomposition = unicode::getDecompositionMapping(0x2460);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0031, decomposition[0]);
        unicode::getDecompositionMapping(0x2460, buffer);
        EXPECT_EQ(0x0031, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::CIRCLE;
        EXPECT_EQ("CIRCLE", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::WIDE, unicode::getDecompositionMappingTag(0x3000)); {
        auto decomposition = unicode::getDecompositionMapping(0x3000);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0020, decomposition[0]);
        unicode::getDecompositionMapping(0x3000, buffer);
        EXPECT_EQ(0x0020, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::WIDE;
        EXPECT_EQ("WIDE", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::VERTICAL, unicode::getDecompositionMappingTag(0x309F)); {
        auto decomposition = unicode::getDecompositionMapping(0x309F);
        EXPECT_EQ(2u, decomposition.size());
        EXPECT_EQ(0x3088, decomposition[0]);
        EXPECT_EQ(0x308A, decomposition[1]);
        unicode::getDecompositionMapping(0x309F, buffer);
        EXPECT_EQ(0x3088, buffer[0]);
        EXPECT_EQ(0x308A, buffer[1]);
        EXPECT_EQ(0, buffer[2]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::VERTICAL;
        EXPECT_EQ("VERTICAL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::SQUARE, unicode::getDecompositionMappingTag(0x3250)); {
        auto decomposition = unicode::getDecompositionMapping(0x3250);
        EXPECT_EQ(3u, decomposition.size());
        EXPECT_EQ(0x0050, decomposition[0]);
        EXPECT_EQ(0x0054, decomposition[1]);
        EXPECT_EQ(0x0045, decomposition[2]);
        unicode::getDecompositionMapping(0x3250, buffer);
        EXPECT_EQ(0x0050, buffer[0]);
        EXPECT_EQ(0x0054, buffer[1]);
        EXPECT_EQ(0x0045, buffer[2]);
        EXPECT_EQ(0, buffer[3]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::SQUARE;
        EXPECT_EQ("SQUARE", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::ISOLATED, unicode::getDecompositionMappingTag(0xFB50)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB50);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0671, decomposition[0]);
        unicode::getDecompositionMapping(0xFB50, buffer);
        EXPECT_EQ(0x0671, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::ISOLATED;
        EXPECT_EQ("ISOLATED", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::FINAL, unicode::getDecompositionMappingTag(0xFB51)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB51);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x0671, decomposition[0]);
        unicode::getDecompositionMapping(0xFB51, buffer);
        EXPECT_EQ(0x0671, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::FINAL;
        EXPECT_EQ("FINAL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::INITIAL, unicode::getDecompositionMappingTag(0xFB54)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB54);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x067B, decomposition[0]);
        unicode::getDecompositionMapping(0xFB54, buffer);
        EXPECT_EQ(0x067B, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::INITIAL;
        EXPECT_EQ("INITIAL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::MEDIAL, unicode::getDecompositionMappingTag(0xFB55)); {
        auto decomposition = unicode::getDecompositionMapping(0xFB55);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x067B, decomposition[0]);
        unicode::getDecompositionMapping(0xFB55, buffer);
        EXPECT_EQ(0x067B, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::MEDIAL;
        EXPECT_EQ("MEDIAL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::SMALL, unicode::getDecompositionMappingTag(0xFE50)); {
        auto decomposition = unicode::getDecompositionMapping(0xFE50);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x002C, decomposition[0]);
        unicode::getDecompositionMapping(0xFE50, buffer);
        EXPECT_EQ(0x002C, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::SMALL;
        EXPECT_EQ("SMALL", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
    EXPECT_EQ(unicode::DecompositionMappingTag::NARROW, unicode::getDecompositionMappingTag(0xFF61)); {
        auto decomposition = unicode::getDecompositionMapping(0xFF61);
        EXPECT_EQ(1u, decomposition.size());
        EXPECT_EQ(0x3002, decomposition[0]);
        unicode::getDecompositionMapping(0xFF61, buffer);
        EXPECT_EQ(0x3002, buffer[0]);
        EXPECT_EQ(0, buffer[1]);
        std::stringstream ss;
        ss << unicode::DecompositionMappingTag::NARROW;
        EXPECT_EQ("NARROW", toUpper(ss.str()));
        ss.str("");
        ss.clear();
    }
}
