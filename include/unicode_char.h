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
#ifndef INCLUDE_UNICODE_CHAR_H_
#define INCLUDE_UNICODE_CHAR_H_

#include <iostream>
#include <vector>
#include <string>
#include <cstdint>
#include <utility>

namespace unicode {

using UChar = int32_t;

enum class GeneralCategory {
    Cc, Cf, Co, Cs, Ll, Lm, Lo, Lt, Lu, Mc,
    Me, Mn, Nd, Nl, No, Pc, Pd, Pe, Pf, Pi,
    Po, Ps, Sc, Sk, Sm, So, Zl, Zp, Zs
};

std::ostream& operator<<(std::ostream&, GeneralCategory);

enum class BidirectionalCategory {
    AL, AN, B, BN, CS, EN, ES, ET, FSI, L,
    LRE, LRI, LRO, NSM, ON, PDF, PDI, R, RLE, RLI,
    RLO, S, WS
};

std::ostream& operator<<(std::ostream&, BidirectionalCategory);

enum class DecompositionMappingTag {
    NO_MAPPING, CANONICAL, CIRCLE, COMPAT, FINAL, FONT, FRACTION, INITIAL, ISOLATED, MEDIAL,
    NARROW, NOBREAK, SMALL, SQUARE, SUB, SUPER, VERTICAL, WIDE
};

std::ostream& operator<<(std::ostream&, DecompositionMappingTag);

GeneralCategory getGeneralCategory(UChar code);

int32_t getCanonicalCombiningClass(UChar code);

BidirectionalCategory getBidirectionalCategory(UChar code);

DecompositionMappingTag getDecompositionMappingTag(UChar code);
std::vector<UChar> getDecompositionMapping(UChar code);
void getDecompositionMapping(UChar code, UChar buffer[]);

int32_t getDecimalDigitValue(UChar code);
int32_t getDigitValue(UChar code);
double getNumericValue(UChar code);
std::pair<int64_t, int64_t> getNumericFraction(UChar code);

bool isMirrored(UChar code);

int32_t getUpperCase(UChar code);
int32_t getLowerCase(UChar code);
int32_t getTitleCase(UChar code);

std::string toUTF8(UChar code);
std::string toUTF8(const std::vector<UChar> codes);
UChar fromUTF8Char(const std::string& str);
std::vector<UChar> fromUTF8(const std::string& str);

std::u16string toUTF16(const std::vector<UChar> codes);
std::vector<UChar> fromUTF16(const std::u16string& str);

}  // namespace unicode

#endif  // INCLUDE_UNICODE_CHAR_H_
