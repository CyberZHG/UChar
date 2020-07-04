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
#ifndef INCLUDE_UNICODE_DATA_H_
#define INCLUDE_UNICODE_DATA_H_

#include "unicode_char.h"

namespace unicode {

extern const int32_t CODE_NUM;
extern const int32_t CONTINUOUS_NUM;
extern const UChar CODE_VALUE[];

extern const GeneralCategory GENERAL_CATEGORY[];

const int32_t CANONICAL_COMBINING_NUM = 536;
extern const int32_t CANONICAL_COMBINING_INDEX[];
extern const int32_t CANONICAL_COMBINING_CLASS[];

extern const BidirectionalCategory BIDIRECTIONAL_CATEGORY[];

const int32_t DECOMPOSITION_MAPPING_NUM = 5736;
extern const int32_t DECOMPOSITION_MAPPING_INDEX[];
extern const DecompositionMappingTag DECOMPOSITION_MAPPING_TAG[];
extern const int32_t DECOMPOSITION_MAPPING_OFFSET[];
extern const UChar DECOMPOSITION_MAPPING_CHARS[];

const int32_t NUMERICS_NUM = 1789;
extern const int32_t NUMERICS_INDEX[];
extern const int32_t NUMERICS_DECIMAL[];
extern const int32_t NUMERICS_DIGIT[];
extern const int64_t NUMERICS_NUMERATOR[];
extern const int32_t NUMERICS_DENOMINATOR[];

const int32_t MIRRORED_NUM = 227;
extern const int32_t MIRRORED_INDEX[];
extern const bool MIRRORED_VALUE[];

const int32_t UPPER_NUM = 1410;
extern const int32_t UPPER_INDEX[];
extern const UChar UPPER_CASE[];
const int32_t LOWER_NUM = 1393;
extern const int32_t LOWER_INDEX[];
extern const UChar LOWER_CASE[];
const int32_t TITLE_NUM = 1414;
extern const int32_t TITLE_INDEX[];
extern const UChar TITLE_CASE[];

}  // namespace unicode

#endif  // INCLUDE_UNICODE_DATA_H_
