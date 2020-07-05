with open('UnicodeData.txt', 'r') as reader:
    codes, decimals, digits, numerics = [], [], [], []
    for line in reader:
        parts = line.strip().split(';')
        if parts[6] or parts[7] or parts[8]:
            codes.append(parts[0])
            decimals.append(parts[6])
            digits.append(parts[7])
            numerics.append(parts[8])

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the numeric information. */\n')
    writer.write('constexpr int NUMERICS_NUM = {};\n'.format(len(codes)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int NUMERICS_INDEX[];\n')
    writer.write('/** The decimal data. */\n')
    writer.write('extern const int NUMERICS_DECIMAL[];\n')
    writer.write('/** The digit data. */\n')
    writer.write('extern const int NUMERICS_DIGIT[];\n')
    writer.write('/** The numerator data. */\n')
    writer.write('extern const int64_t NUMERICS_NUMERATOR[];\n')
    writer.write('/** The denominator data. */\n')
    writer.write('extern const int NUMERICS_DENOMINATOR[];\n\n')

with open('src/numeric.cpp', 'w') as writer:
    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('\nconst int NUMERICS_INDEX[] = {')
    for i, code in enumerate(codes):
        if i == 0:
            writer.write('\n    ')
        elif i % 8 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write('0x' + code)
    writer.write('\n};\n')

    writer.write('\nconst int NUMERICS_DECIMAL[] = {')
    for i, decimal in enumerate(decimals):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        if decimal:
            writer.write(decimal)
        else:
            writer.write('-1')
    writer.write('\n};\n')

    writer.write('\nconst int NUMERICS_DIGIT[] = {')
    for i, digit in enumerate(digits):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        if digit:
            writer.write(digit)
        else:
            writer.write('-1')
    writer.write('\n};\n')

    writer.write('\nconst int64_t NUMERICS_NUMERATOR[] = {')
    for i, numeric in enumerate(numerics):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        if numeric:
            writer.write(numeric.split('/')[0] + 'LL')
        else:
            writer.write('-1LL')
    writer.write('\n};\n')

    writer.write('\nconst int NUMERICS_DENOMINATOR[] = {')
    for i, numeric in enumerate(numerics):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        if numeric:
            if '/' in numeric:
                writer.write(numeric.split('/')[1])
            else:
                writer.write('1')
        else:
            writer.write('0')
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')
