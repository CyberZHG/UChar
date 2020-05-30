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

#include <cstdint>

#include <utility>

namespace unicode {

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

GeneralCategory getGeneralCategory(int code);
int getCanonicalCombiningClass(int code);
BidirectionalCategory getBidirectionalCategory(int code);
DecompositionMappingTag getDecompositionMappingTag(int code);
std::vector<int> getDecompositionMapping(int code);
void getDecompositionMapping(int code, int buffer[]);
int getDecimalDigitValue(int code);
int getDigitValue(int code);
double getNumericValue(int code);
std::pair<int64_t, int64_t> getNumericFraction(int code);
int getUpperCase(int code);
int getLowerCase(int code);
int getTitleCase(int code);

}  // namespace unicode

#endif  // INCLUDE_UNICODE_CHAR_H_
