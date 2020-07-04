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
