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


int findLowerBound(const int array[], int total, int target) {
    if (target < array[0]) {
        return -1;
    }
    if (target > array[total - 1]) {
        return total - 1;
    }
    int l = 0, r = total - 1, index = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
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

int getCodeIndex(int code) {
    if (code <= CONTINUOUS_NUM) {
        return code;
    }
    return findLowerBound(CODE_VALUE, CODE_NUM, code);
}

unicode::GeneralCategory unicode::getGeneralCategory(int code) {
    return GENERAL_CATEGORY[getCodeIndex(code)];
}

int unicode::getCanonicalCombiningClass(int code) {
    int index = findLowerBound(CANONICAL_COMBINING_INDEX, CANONICAL_COMBINING_NUM, code);
    if (index == -1) {
        return 0;
    }
    return index == -1 ? 0 : CANONICAL_COMBINING_CLASS[index];
}

unicode::BidirectionalCategory unicode::getBidirectionalCategory(int code) {
    return BIDIRECTIONAL_CATEGORY[getCodeIndex(code)];
}

unicode::DecompositionMappingTag unicode::getDecompositionMappingTag(int code) {
    int index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return unicode::DecompositionMappingTag::NO_MAPPING;
    }
    return DECOMPOSITION_MAPPING_TAG[index];
}

std::vector<int> unicode::getDecompositionMapping(int code) {
    int index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return {code};
    }
    int start = DECOMPOSITION_MAPPING_OFFSET[index];
    int stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    std::vector<int> decomposition(stop - start);
    for (int i = start; i < stop; ++i) {
        decomposition[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    return decomposition;
}

void unicode::getDecompositionMapping(int code, int buffer[]) {
    int index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        buffer[0] = code;
        buffer[1] = 0;
    }
    int start = DECOMPOSITION_MAPPING_OFFSET[index];
    int stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    for (int i = start; i < stop; ++i) {
        buffer[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    buffer[stop - start] = 0;
}

int unicode::getDecimalDigitValue(int code) {
    int index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DECIMAL[index];
}

int unicode::getDigitValue(int code) {
    int index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DIGIT[index];
}

double unicode::getNumericValue(int code) {
    int index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code || NUMERICS_DENOMINATOR[index] == 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return 1.0 * NUMERICS_NUMERATOR[index] / NUMERICS_DENOMINATOR[index];
}

std::pair<int64_t, int64_t> unicode::getNumericFraction(int code) {
    int index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return {-1, 0};
    }
    return {NUMERICS_NUMERATOR[index], static_cast<int64_t>(NUMERICS_DENOMINATOR[index])};
}

int getCase(const int indices[], const int cases[], int total, int code) {
    int index = findLowerBound(indices, total, code);
    if (index == -1 || indices[index] != code) {
        return code;
    }
    return cases[index];
}

int unicode::getUpperCase(int code) {
    return getCase(UPPER_INDEX, UPPER_CASE, UPPER_NUM, code);
}

int unicode::getLowerCase(int code) {
    return getCase(LOWER_INDEX, LOWER_CASE, LOWER_NUM, code);
}

int unicode::getTitleCase(int code) {
    return getCase(TITLE_INDEX, TITLE_CASE, TITLE_NUM, code);
}
