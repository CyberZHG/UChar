GeneralCategory getGeneralCategory(int code);
int getCanonicalCombiningClass(int code);
BidirectionalCategory getBidirectionalCategory(int code);
DecompositionMappingTag getDecompositionMappingTag(int code);
std::vector<int> getDecompositionMapping(int code);
void getDecompositionMapping(int code, int buffer[]);
int getUpperCase(int code);
int getLowerCase(int code);
int getTitleCase(int code);
