#include <limits>
#include "unicode_char.h"
#include "unicode_data.h"

namespace unicode {

int findLowerBound(const int array[], const int total, const int target) {
    if (target < array[0]) {
        return -1;
    }
    if (target > array[total - 1]) {
        return total - 1;
    }
    int l = 0, r = total - 1, index = 0;
    while (l <= r) {
        const auto mid = l + (r - l) / 2;
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

int getCodeIndex(const UChar code) {
    if (code <= CONTINUOUS_NUM) {
        return code;
    }
    return findLowerBound(CODE_VALUE, CODE_NUM, code);
}

GeneralCategory getGeneralCategory(const UChar code) {
    return GENERAL_CATEGORY[getCodeIndex(code)];
}

BaseGeneralCategory getBaseGeneralCategory(const UChar code) {
    return BASE_GENERAL_CATEGORY[getCodeIndex(code)];
}

int getCanonicalCombiningClass(const UChar code) {
    const auto index = findLowerBound(CANONICAL_COMBINING_INDEX, CANONICAL_COMBINING_NUM, code);
    return index == -1 ? 0 : CANONICAL_COMBINING_CLASS[index];
}

BidirectionalCategory getBidirectionalCategory(const UChar code) {
    return BIDIRECTIONAL_CATEGORY[getCodeIndex(code)];
}

DecompositionMappingTag getDecompositionMappingTag(const UChar code) {
    const auto index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return DecompositionMappingTag::NO_MAPPING;
    }
    return DECOMPOSITION_MAPPING_TAG[index];
}

std::vector<UChar> getDecompositionMapping(UChar code) {
    const auto index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        return {code};
    }
    const auto start = DECOMPOSITION_MAPPING_OFFSET[index];
    const auto stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    std::vector<UChar> decomposition(stop - start);
    for (auto i = start; i < stop; ++i) {
        decomposition[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    return decomposition;
}

void getDecompositionMapping(const UChar code, UChar buffer[]) {
    const auto index = findLowerBound(DECOMPOSITION_MAPPING_INDEX, DECOMPOSITION_MAPPING_NUM, code);
    if (index == -1 || DECOMPOSITION_MAPPING_INDEX[index] != code) {
        buffer[0] = code;
        buffer[1] = 0;
    }
    const auto start = DECOMPOSITION_MAPPING_OFFSET[index];
    const auto stop = DECOMPOSITION_MAPPING_OFFSET[index + 1];
    for (auto i = start; i < stop; ++i) {
        buffer[i - start] = DECOMPOSITION_MAPPING_CHARS[i];
    }
    buffer[stop - start] = 0;
}

int getDecimalDigitValue(const UChar code) {
    const auto index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DECIMAL[index];
}

int getDigitValue(const UChar code) {
    const auto index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return -1;
    }
    return NUMERICS_DIGIT[index];
}

double getNumericValue(const UChar code) {
    const auto index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code || NUMERICS_DENOMINATOR[index] == 0) {
        return std::numeric_limits<double>::quiet_NaN();
    }
    return 1.0 * static_cast<double>(NUMERICS_NUMERATOR[index]) / static_cast<double>(NUMERICS_DENOMINATOR[index]);
}

std::pair<int64_t, int64_t> getNumericFraction(const UChar code) {
    const auto index = findLowerBound(NUMERICS_INDEX, NUMERICS_NUM, code);
    if (index == -1 || NUMERICS_INDEX[index] != code) {
        return {-1, 0};
    }
    return {NUMERICS_NUMERATOR[index], static_cast<int64_t>(NUMERICS_DENOMINATOR[index])};
}

bool isMirrored(const UChar code) {
    const int32_t index = findLowerBound(MIRRORED_INDEX, MIRRORED_NUM, code);
    if (index == -1) {
        return false;
    }
    return MIRRORED_VALUE[index];
}

int getCase(const int indices[], const int cases[], const int total, const UChar code) {
    const auto index = findLowerBound(indices, total, code);
    if (index == -1 || indices[index] != code) {
        return code;
    }
    return cases[index];
}

UChar getUpperCase(const UChar code) {
    return getCase(UPPER_INDEX, UPPER_CASE, UPPER_NUM, code);
}

UChar getLowerCase(const UChar code) {
    return getCase(LOWER_INDEX, LOWER_CASE, LOWER_NUM, code);
}

UChar getTitleCase(const int32_t code) {
    return getCase(TITLE_INDEX, TITLE_CASE, TITLE_NUM, code);
}

}  // namespace unicode
