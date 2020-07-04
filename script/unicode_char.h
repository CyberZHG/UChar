/** Get the general category of a code point. */
GeneralCategory getGeneralCategory(UChar code);
/** Get the base general category of a code point. */
BaseGeneralCategory getBaseGeneralCategory(UChar code);

/** Get the canonical combining class of a code point. */
int32_t getCanonicalCombiningClass(UChar code);

/** Get the bidirectional category of a code point. */
BidirectionalCategory getBidirectionalCategory(UChar code);

/** Get the decomposition mapping tag of a code point. */
DecompositionMappingTag getDecompositionMappingTag(UChar code);
/** Get the mapped decomposition of a code point. */
std::vector<UChar> getDecompositionMapping(UChar code);
/** Get the mapped decomposition of a code point. */
void getDecompositionMapping(UChar code, UChar buffer[]);

/** Get the decimal digit value of a code point.
 *
 * @return -1 will be returned if it is not a decimal digit.
 */
int32_t getDecimalDigitValue(UChar code);
/** Get the digit value of a code point.
 *
 * @return -1 will be returned if it is not a digit.
 */
int32_t getDigitValue(UChar code);
/** Get the numeric value of a code point.
 *
 * @return nan will be returned if it is not a numeric.
 */
double getNumericValue(UChar code);
/** Get the numeric value of a code point in fraction form.
 *
 * @return {-1, 0} will be returned if it is not a numeric.
 */
std::pair<int64_t, int64_t> getNumericFraction(UChar code);

/** Whether the code point is mirrored. */
bool isMirrored(UChar code);

/** Get the upper case of a code point.
 *
 * @return The original code point will be returned
 *         if it doesn't have a upper case.
 */
UChar getUpperCase(UChar code);
/** Get the lower case of a code point.
 *
 * @return The original code point will be returned
 *         if it doesn't have a lower case.
 */
UChar getLowerCase(UChar code);
/** Get the title case of a code point.
 *
 * @return The original code point will be returned
 *         if it doesn't have a title case.
 */
UChar getTitleCase(UChar code);

/** Convert a code point to UTF-8 string. */
std::string toUTF8(UChar code);
/** Convert code points to UTF-8 string. */
std::string toUTF8(const std::vector<UChar> codes);
/** Convert a UTF-8 string to a code point. */
UChar fromUTF8Char(const std::string& str);
/** Convert a UTF-8 string to code points. */
std::vector<UChar> fromUTF8(const std::string& str);

/** Convert code points to UTF-16 string. */
std::u16string toUTF16(const std::vector<UChar> codes);
/** Convert UTF-16 string to code points. */
std::vector<UChar> fromUTF16(const std::u16string& str);
