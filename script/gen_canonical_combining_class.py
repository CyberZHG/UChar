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
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

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
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "test.h"\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('namespace test {\n\n')

    writer.write('class CanonicalCombiningClassGenTest : public UnitTest {};\n\n')

    writer.write('__TEST_U(CanonicalCombiningClassGenTest, test_classes) {\n')
    for canonical, code in classes.items():
        writer.write('    __ASSERT_EQ({}, unicode::getCanonicalCombiningClass({}));\n'.format(
            canonical, '0x' + code
        ))
    writer.write('}\n\n')

    writer.write('}  // namespace test\n')
