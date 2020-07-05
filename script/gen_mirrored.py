with open('UnicodeData.txt', 'r') as reader:
    last, codes, mirrors = '', [], []
    for line in reader:
        parts = line.strip().split(';')
        if parts[9] != last:
            last = parts[9]
            codes.append(parts[0])
            mirrors.append(parts[9])

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the mirrored information. */\n')
    writer.write('const int MIRRORED_NUM = {};\n'.format(len(codes)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int MIRRORED_INDEX[];\n')
    writer.write('/** The mirrored information data. */\n')
    writer.write('extern const bool MIRRORED_VALUE[];\n\n')

with open('src/mirrored.cpp', 'w') as writer:
    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('\nconst int MIRRORED_INDEX[] = {')
    for i, code in enumerate(codes):
        if i == 0:
            writer.write('\n    ')
        elif i % 8 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write('0x' + code)
    writer.write('\n};\n')

    writer.write('\nconst bool MIRRORED_VALUE[] = {')
    for i, mirror in enumerate(mirrors):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        if mirror == 'Y':
            writer.write('true')
        else:
            writer.write('false')
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')
