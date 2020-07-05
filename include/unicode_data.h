#ifndef INCLUDE_UNICODE_DATA_H_
#define INCLUDE_UNICODE_DATA_H_

/**
 * @file
 * @brief Unicode information about a character.
 */

#include "unicode_char.h"

namespace unicode {

/** The total number of codes. */
extern const int CODE_NUM;
/** The maximum offset that has a definition in the data file. */
extern const int CONTINUOUS_NUM;
/** The integer values of the characters. */
extern const UChar CODE_VALUE[];

/** The general category data. */
extern const GeneralCategory GENERAL_CATEGORY[];
/** The base general category data. */
extern const BaseGeneralCategory BASE_GENERAL_CATEGORY[];

/** The total number of indices used to store the canonical combing class. */
constexpr int CANONICAL_COMBINING_NUM = 592;
/** The indices of the first character that have a different type. */
extern const int CANONICAL_COMBINING_INDEX[];
/** The canonical combining class data. */
extern const int CANONICAL_COMBINING_CLASS[];

/** The types of bidirectional category. */
extern const BidirectionalCategory BIDIRECTIONAL_CATEGORY[];

/** The total number of indices used to store the decomposition mappings. */
constexpr int DECOMPOSITION_MAPPING_NUM = 5914;
/** The indices of the first character that have a different type. */
extern const int DECOMPOSITION_MAPPING_INDEX[];
/** The decomposition mapping tags data. */
extern const DecompositionMappingTag DECOMPOSITION_MAPPING_TAG[];
/** The start indices of decomposition mappings. */
extern const int DECOMPOSITION_MAPPING_OFFSET[];
/** The decomposition mapping characters data. */
extern const UChar DECOMPOSITION_MAPPING_CHARS[];

/** The total number of indices used to store the numeric information. */
constexpr int NUMERICS_NUM = 1940;
/** The indices of the first character that have a different type. */
extern const int NUMERICS_INDEX[];
/** The decimal data. */
extern const int NUMERICS_DECIMAL[];
/** The digit data. */
extern const int NUMERICS_DIGIT[];
/** The numerator data. */
extern const int64_t NUMERICS_NUMERATOR[];
/** The denominator data. */
extern const int NUMERICS_DENOMINATOR[];

/** The total number of indices used to store the mirrored information. */
constexpr int MIRRORED_NUM = 229;
/** The indices of the first character that have a different type. */
extern const int MIRRORED_INDEX[];
/** The mirrored information data. */
extern const bool MIRRORED_VALUE[];

/** The total number of indices used to store the upper cases. */
constexpr int UPPER_NUM = 1505;
/** The indices of the first character that have a different type. */
extern const int UPPER_INDEX[];
/** The upper cases data. */
extern const UChar UPPER_CASE[];
/** The total number of indices used to store the lower cases. */
constexpr int LOWER_NUM = 1488;
/** The indices of the first character that have a different type. */
extern const int LOWER_INDEX[];
/** The lower cases data. */
extern const UChar LOWER_CASE[];
/** The total number of indices used to store the title cases. */
constexpr int TITLE_NUM = 1509;
/** The indices of the first character that have a different type. */
extern const int TITLE_INDEX[];
/** The title cases data. */
extern const UChar TITLE_CASE[];

}  // namespace unicode

#endif  // INCLUDE_UNICODE_DATA_H_
