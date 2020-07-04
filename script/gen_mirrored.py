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
    last, codes, mirrors = '', [], []
    for line in reader:
        parts = line.strip().split(';')
        if parts[9] != last:
            last = parts[9]
            codes.append(parts[0])
            mirrors.append(parts[9])

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the mirrored information. */\n')
    writer.write('const int32_t MIRRORED_NUM = {};\n'.format(len(codes)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t MIRRORED_INDEX[];\n')
    writer.write('/** The mirrored information data. */\n')
    writer.write('extern const bool MIRRORED_VALUE[];\n\n')

with open('src/mirrored.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    writer.write('\nconst int32_t MIRRORED_INDEX[] = {')
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
