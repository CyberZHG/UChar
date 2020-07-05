with open('UnicodeData.txt', 'r') as reader:
    last, indices, canonicals, classes = '', [], [], {}
    for line in reader:
        parts = line.strip().split(';')
        if parts[3] != last:
            last = parts[3]
            indices.append(parts[0])
            canonicals.append(parts[3])
            classes[parts[3]] = parts[0]

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the canonical combing class. */\n')
    writer.write('const int32_t CANONICAL_COMBINING_NUM = {};\n'.format(len(indices)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t CANONICAL_COMBINING_INDEX[];\n')
    writer.write('/** The canonical combining class data. */\n')
    writer.write('extern const int32_t CANONICAL_COMBINING_CLASS[];\n\n')

with open('src/canonical_combining_class.cpp', 'w') as writer:
    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('\nconst int32_t CANONICAL_COMBINING_INDEX[] = {')
    for i, index in enumerate(indices):
        if i == 0:
            writer.write('\n    ')
        elif i % 8 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write('0x' + index)
    writer.write('\n};\n')

    writer.write('\nconst int32_t CANONICAL_COMBINING_CLASS[] = {')
    for i, canonical in enumerate(canonicals):
        if i == 0:
            writer.write('\n    ')
        elif i % 8 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(canonical)
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')

with open('tests/test_canonical_combining_class_gen.cpp', 'w') as writer:
    writer.write('#include <gtest/gtest.h>\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('TEST(CanonicalCombiningClassGenTest, test_classes) {\n')
    for canonical, code in classes.items():
        writer.write('    EXPECT_EQ({}, unicode::getCanonicalCombiningClass({}));\n'.format(
            canonical, '0x' + code
        ))
    writer.write('}\n')
