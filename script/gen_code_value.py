with open('UnicodeData.txt', 'r') as reader:
    code_values = [line.strip().split(';')[0] for line in reader]
    for i, code in enumerate(code_values):
        if i != int(code, 16):
            max_continuous = i - 1
            break

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of codes. */\n')
    writer.write('extern const int CODE_NUM;\n')
    writer.write('/** The maximum offset that has a definition in the data file. */\n')
    writer.write('extern const int CONTINUOUS_NUM;\n')
    writer.write('/** The integer values of the characters. */\n')
    writer.write('extern const UChar CODE_VALUE[];\n\n')

with open('src/code_value.cpp', 'w') as writer:
    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('const int CODE_NUM = %d;\n' % len(code_values))
    writer.write('const int CONTINUOUS_NUM = %d;\n' % max_continuous)
    writer.write('const UChar CODE_VALUE[] = {')
    for i, value in enumerate(code_values):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write('0x%s' % value)
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')
