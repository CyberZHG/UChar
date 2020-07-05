with open('include/unicode_data.h', 'w') as writer:
    writer.write('#ifndef INCLUDE_UNICODE_DATA_H_\n')
    writer.write('#define INCLUDE_UNICODE_DATA_H_\n\n')
    writer.write('/**\n * @file\n * @brief Unicode information about a character.\n */\n\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('namespace unicode {\n\n')

with open('include/unicode_char.h', 'w') as writer:
    writer.write('#ifndef INCLUDE_UNICODE_CHAR_H_\n')
    writer.write('#define INCLUDE_UNICODE_CHAR_H_\n\n')
    writer.write('/**\n * @file\n * @brief The data file that stores the information.\n */\n\n')
    writer.write('#include <iostream>\n')
    writer.write('#include <vector>\n')
    writer.write('#include <string>\n')
    writer.write('#include <cstdint>\n')
    writer.write('#include <utility>\n\n')
    writer.write('namespace unicode {\n\n')
    writer.write('using UChar = int32_t;\n\n')
