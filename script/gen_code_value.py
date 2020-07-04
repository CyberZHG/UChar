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
    code_values = [line.strip().split(';')[0] for line in reader]
    for i, code in enumerate(code_values):
        if i != int(code, 16):
            max_continuous = i - 1
            break

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of codes. */\n')
    writer.write('extern const int32_t CODE_NUM;\n')
    writer.write('/** The maximum offset that has a definition in the data file. */\n')
    writer.write('extern const int32_t CONTINUOUS_NUM;\n')
    writer.write('/** The integer values of the characters. */\n')
    writer.write('extern const UChar CODE_VALUE[];\n\n')

with open('src/code_value.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('const int32_t CODE_NUM = %d;\n' % len(code_values))
    writer.write('const int32_t CONTINUOUS_NUM = %d;\n' % max_continuous)
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
