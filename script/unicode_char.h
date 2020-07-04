GeneralCategory getGeneralCategory(int32_t code);

int32_t getCanonicalCombiningClass(int32_t code);

BidirectionalCategory getBidirectionalCategory(int32_t code);

DecompositionMappingTag getDecompositionMappingTag(int32_t code);
std::vector<int32_t> getDecompositionMapping(int32_t code);
void getDecompositionMapping(int32_t code, int32_t buffer[]);

int32_t getDecimalDigitValue(int32_t code);
int32_t getDigitValue(int32_t code);
double getNumericValue(int32_t code);
std::pair<int64_t, int64_t> getNumericFraction(int32_t code);

bool isMirrored(int32_t code);

int32_t getUpperCase(int32_t code);
int32_t getLowerCase(int32_t code);
int32_t getTitleCase(int32_t code);

std::string toUTF8(int32_t code);
std::string toUTF8(const std::vector<int32_t> codes);
int32_t fromUTF8Char(const std::string& str);
std::vector<int32_t> fromUTF8(const std::string& str);

std::u16string toUTF16(const std::vector<int32_t> codes);
std::vector<int32_t> fromUTF16(const std::u16string& str);
