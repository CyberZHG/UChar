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

/**
 * @file
 * @brief Unicode information about a character.
 */

#include "unicode_char.h"

namespace unicode {

/** The total number of codes. */
extern const int32_t CODE_NUM;
/** The maximum offset that has a definition in the data file. */
extern const int32_t CONTINUOUS_NUM;
/** The integer values of the characters. */
extern const UChar CODE_VALUE[];

/** The general category data. */
extern const GeneralCategory GENERAL_CATEGORY[];
/** The base general category data. */
extern const BaseGeneralCategory BASE_GENERAL_CATEGORY[];

/** The total number of indices used to store the canonical combing class. */
const int32_t CANONICAL_COMBINING_NUM = 536;
/** The indices of the first character that have a different type. */
extern const int32_t CANONICAL_COMBINING_INDEX[];
/** The canonical combining class data. */
extern const int32_t CANONICAL_COMBINING_CLASS[];

/** The types of bidirectional category. */
extern const BidirectionalCategory BIDIRECTIONAL_CATEGORY[];

/** The total number of indices used to store the decomposition mappings. */
const int32_t DECOMPOSITION_MAPPING_NUM = 5736;
/** The indices of the first character that have a different type. */
extern const int32_t DECOMPOSITION_MAPPING_INDEX[];
/** The decomposition mapping tags data. */
extern const DecompositionMappingTag DECOMPOSITION_MAPPING_TAG[];
/** The start indices of decomposition mappings. */
extern const int32_t DECOMPOSITION_MAPPING_OFFSET[];
/** The decomposition mapping characters data. */
extern const UChar DECOMPOSITION_MAPPING_CHARS[];

/** The total number of indices used to store the numeric information. */
const int32_t NUMERICS_NUM = 1789;
/** The indices of the first character that have a different type. */
extern const int32_t NUMERICS_INDEX[];
/** The decimal data. */
extern const int32_t NUMERICS_DECIMAL[];
/** The digit data. */
extern const int32_t NUMERICS_DIGIT[];
/** The numerator data. */
extern const int64_t NUMERICS_NUMERATOR[];
/** The denominator data. */
extern const int32_t NUMERICS_DENOMINATOR[];

/** The total number of indices used to store the mirrored information. */
const int32_t MIRRORED_NUM = 227;
/** The indices of the first character that have a different type. */
extern const int32_t MIRRORED_INDEX[];
/** The mirrored information data. */
extern const bool MIRRORED_VALUE[];

/** The total number of indices used to store the upper cases. */
const int32_t UPPER_NUM = 1410;
/** The indices of the first character that have a different type. */
extern const int32_t UPPER_INDEX[];
/** The upper cases data. */
extern const UChar UPPER_CASE[];
/** The total number of indices used to store the lower cases. */
const int32_t LOWER_NUM = 1393;
/** The indices of the first character that have a different type. */
extern const int32_t LOWER_INDEX[];
/** The lower cases data. */
extern const UChar LOWER_CASE[];
/** The total number of indices used to store the title cases. */
const int32_t TITLE_NUM = 1414;
/** The indices of the first character that have a different type. */
extern const int32_t TITLE_INDEX[];
/** The title cases data. */
extern const UChar TITLE_CASE[];

}  // namespace unicode

#endif  // INCLUDE_UNICODE_DATA_H_
