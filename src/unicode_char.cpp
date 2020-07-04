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
#include <limits>
#include "unicode_char.h"
#include "unicode_data.h"

namespace unicode {

int32_t findLowerBound(const int32_t array[], int32_t total, int32_t target) {
    if (target < array[0]) {
        return -1;
    }
    if (target > array[total - 1]) {
        return total - 1;
    }
    int32_t l = 0, r = total - 1, index = 0;
    while (l <= r) {
        int32_t mid = l + (r - l) / 2;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            l = mid + 1;
            if (mid > index) {
                index = mid;
            }
        } else {
            r = mid - 1;
        }
    }
    return index;
}

int32_t getCodeIndex(UChar code) {
    if (code <= CONTINUOUS_NUM) {
        return code;
    }
    return findLowerBound(CODE_VALUE, CODE_NUM, code);
}

GeneralCategory getGeneralCategory(UChar code) {
    return GENERAL_CATEGORY[getCodeIndex(code)];
}

BaseGeneralCategory getBaseGeneralCategory(UChar code) {
    return BASE_GENERAL_CATEGORY[getCodeIndex(code)];
}

int32_t getCanonicalCombiningClass(UChar code) {
    int32_t index = findLowerBound(CANONICAL_COMBINING_INDEX, CANONICAL_COMBINING_NUM, code);
    if (index == -1) {
        return 0;
    }
    return index == -1 ? 0 : CANONICAL_COMBINING_CLASS[index];
}

BidirectionalCategory getBidirectionalCategory(UChar code) {
    return BIDIRECTIONAL_CATEGORY[getCodeIndex(code)];
}

DecompositionMappingTag getDecompositionMappingTag(UChar code) {
    int32_t index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return DecompositionMappingTag::NO_MAPPING;
    }
    return DECOMPOSITION_MAPPING_TAG[index];
}

std::vector<UChar> getDecompositionMapping(UChar code) {
    int32_t index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return {code};
    }
    int32_t start = DECOMPOSITION_MAPPING_OFFSET[index];
    int32_t stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    std::vector<UChar> decomposition(stop - start);
    for (int32_t i = start; i < stop; ++i) {
        decomposition[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    return decomposition;
}

void getDecompositionMapping(UChar code, UChar buffer[]) {
    int32_t index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        buffer[0] = code;
        buffer[1] = 0;
    }
    int32_t start = DECOMPOSITION_MAPPING_OFFSET[index];
    int32_t stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    for (int32_t i = start; i < stop; ++i) {
        buffer[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    buffer[stop - start] = 0;
}

int32_t getDecimalDigitValue(UChar code) {
    int32_t index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DECIMAL[index];
}

int32_t getDigitValue(UChar code) {
    int32_t index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DIGIT[index];
}

double getNumericValue(UChar code) {
    int32_t index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code || NUMERICS_DENOMINATOR[index] == 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return 1.0 * NUMERICS_NUMERATOR[index] / NUMERICS_DENOMINATOR[index];
}

std::pair<int64_t, int64_t> getNumericFraction(UChar code) {
    int32_t index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return {-1, 0};
    }
    return {NUMERICS_NUMERATOR[index], static_cast<int64_t>(NUMERICS_DENOMINATOR[index])};
}

bool isMirrored(UChar code) {
    int32_t index = findLowerBound(MIRRORED_INDEX, MIRRORED_NUM, code);
    if (index == -1) {
        return false;
    }
    return MIRRORED_VALUE[index];
}

int32_t getCase(const int32_t indices[], const int32_t cases[], int32_t total, UChar code) {
    int32_t index = findLowerBound(indices, total, code);
    if (index == -1 || indices[index] != code) {
        return code;
    }
    return cases[index];
}

UChar getUpperCase(UChar code) {
    return getCase(UPPER_INDEX, UPPER_CASE, UPPER_NUM, code);
}

UChar getLowerCase(UChar code) {
    return getCase(LOWER_INDEX, LOWER_CASE, LOWER_NUM, code);
}

UChar getTitleCase(int32_t code) {
    return getCase(TITLE_INDEX, TITLE_CASE, TITLE_NUM, code);
}

}  // namespace unicode
