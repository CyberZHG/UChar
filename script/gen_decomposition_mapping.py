#!/usr/bin/env python
""" Copyright 2020 Zhao HG

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
"""
with open('UnicodeData.txt', 'r') as reader:
    codes, tags, decompositions = [], [], []
    tag_map = {'NO_MAPPING': '', 'CANONICAL': 'canonical'}
    for line in reader:
        parts = line.strip().split(';')
        code, decomposition = parts[0], parts[5]
        if decomposition:
            decomposition = decomposition.split(' ')
            codes.append(code)
            if decomposition[0][0] == '<':
                tag = decomposition[0][1:-1]
                tag_map[tag.upper()] = tag
                tags.append(tag.upper())
                decompositions.append(decomposition[1:])
            else:
                tags.append('CANONICAL')
                decompositions.append(decomposition)
    unique_tags = ['NO_MAPPING'] + list(sorted(list(set(tags))))
    offsets, last_offset = [], 0
    for decomposition in decompositions:
        offsets.append(last_offset)
        last_offset += len(decomposition)
    offsets.append(last_offset)


with open('include/unicode_char.h', 'a') as writer:
    writer.write('/** The tags of decomposition mappingy. */\n')
    writer.write('enum class DecompositionMappingTag {')
    for i, tag in enumerate(unique_tags):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(tag)
    writer.write('\n};\n\n')

    writer.write('/** Outputs the decomposition mapping tag with its name. */\n')
    writer.write('std::ostream& operator<<(std::ostream&, DecompositionMappingTag);\n\n')

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the decomposition mappings. */\n')
    writer.write('const int32_t DECOMPOSITION_MAPPING_NUM = {};\n'.format(len(codes)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t DECOMPOSITION_MAPPING_INDEX[];\n')
    writer.write('/** The decomposition mapping tags data. */\n')
    writer.write('extern const DecompositionMappingTag DECOMPOSITION_MAPPING_TAG[];\n')
    writer.write('/** The start indices of decomposition mappings. */\n')
    writer.write('extern const int32_t DECOMPOSITION_MAPPING_OFFSET[];\n')
    writer.write('/** The decomposition mapping characters data. */\n')
    writer.write('extern const UChar DECOMPOSITION_MAPPING_CHARS[];\n\n')

with open('src/decomposition_mapping.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    for tag in unique_tags:
        writer.write('const DecompositionMappingTag {} = DecompositionMappingTag::{};\n'.format(tag, tag))
    writer.write("\n")

    writer.write('std::ostream& operator<<(std::ostream& os, DecompositionMappingTag tag) {\n')
    writer.write('    switch (tag) {\n')
    for tag, mapped in tag_map.items():
        writer.write('    case {}: os << "{}"; break;\n'.format(tag, mapped))
    writer.write('    }\n')
    writer.write('    return os;\n')
    writer.write('}\n\n')

    writer.write('\nconst int32_t DECOMPOSITION_MAPPING_INDEX[] = {')
    for i, code in enumerate(codes):
        if i == 0:
            writer.write('\n    ')
        elif i % 8 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write('0x' + code)
    writer.write('\n};\n')

    writer.write('\nconst DecompositionMappingTag DECOMPOSITION_MAPPING_TAG[] = {')
    for i, tag in enumerate(tags):
        if i == 0:
            writer.write('\n    ')
        elif i % 5 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(tag)
    writer.write('\n};\n')

    writer.write('\nconst int32_t DECOMPOSITION_MAPPING_OFFSET[] = {')
    for i, offset in enumerate(offsets):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(str(offset))
    writer.write('\n};\n')

    writer.write('\nconst int32_t DECOMPOSITION_MAPPING_CHARS[] = {')
    i = 0
    for decomposition in decompositions:
        for code in decomposition:
            if i == 0:
                writer.write('\n    ')
            elif i % 8 == 0:
                writer.write(',\n    ')
            else:
                writer.write(', ')
            writer.write('0x' + code)
            i += 1
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')

with open('tests/test_decomposition_mapping_gen.cpp', 'w') as writer:
    codes = ['0000'] + codes
    tags = ['NO_MAPPING'] + tags
    decompositions = [['0000']] + decompositions

    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "test.h"\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('namespace test {\n\n')

    writer.write('class DecompositionMappingGenTest : public UnitTest {};\n\n')

    writer.write('__TEST_U(DecompositionMappingGenTest, test_cats) {\n')
    writer.write('    unicode::UChar buffer[16];\n')
    appeared = set()
    for code, tag, decomposition in zip(codes, tags, decompositions):
        if tag not in appeared:
            appeared.add(tag)
            writer.write('    __ASSERT_EQ(unicode::DecompositionMappingTag::{}, '
                         'unicode::getDecompositionMappingTag({})); {{\n'.format(
                            tag, '0x' + code))
            writer.write('        auto decomposition = unicode::getDecompositionMapping({});\n'.format(
                '0x' + code))
            writer.write('        __ASSERT_EQ({}u, decomposition.size());\n'.format(len(decomposition)))
            for i in range(len(decomposition)):
                writer.write('        __ASSERT_EQ({}, decomposition[{}]);\n'.format('0x' + decomposition[i], i))
            writer.write('        unicode::getDecompositionMapping({}, buffer);\n'.format('0x' + code))
            for i in range(len(decomposition)):
                writer.write('        __ASSERT_EQ({}, buffer[{}]);\n'.format('0x' + decomposition[i], i))
            writer.write('        __ASSERT_EQ(0, buffer[{}]);\n'.format(len(decomposition)))
            writer.write('    }\n')
    writer.write('}\n\n')

    writer.write('}  // namespace test\n')
