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
