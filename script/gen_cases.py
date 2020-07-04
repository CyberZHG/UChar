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
    uppers, lowers, titles = [], [], []
    for line in reader:
        parts = line.strip().split(';')
        if parts[12]:
            uppers.append((parts[0], parts[12]))
        if parts[13]:
            lowers.append((parts[0], parts[13]))
        if parts[14]:
            titles.append((parts[0], parts[14]))

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The total number of indices used to store the upper cases. */\n')
    writer.write('const int32_t UPPER_NUM = {};\n'.format(len(uppers)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t UPPER_INDEX[];\n')
    writer.write('/** The upper cases data. */\n')
    writer.write('extern const UChar UPPER_CASE[];\n')
    writer.write('/** The total number of indices used to store the lower cases. */\n')
    writer.write('const int32_t LOWER_NUM = {};\n'.format(len(lowers)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t LOWER_INDEX[];\n')
    writer.write('/** The lower cases data. */\n')
    writer.write('extern const UChar LOWER_CASE[];\n')
    writer.write('/** The total number of indices used to store the title cases. */\n')
    writer.write('const int32_t TITLE_NUM = {};\n'.format(len(titles)))
    writer.write('/** The indices of the first character that have a different type. */\n')
    writer.write('extern const int32_t TITLE_INDEX[];\n')
    writer.write('/** The title cases data. */\n')
    writer.write('extern const UChar TITLE_CASE[];\n\n')

with open('src/cases.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    for name, cases in zip(['UPPER', 'LOWER', 'TITLE'],
                           [uppers, lowers, titles]):
        writer.write('\nconst int32_t {}_INDEX[] = {{'.format(name))
        for i, case in enumerate(cases):
            if i == 0:
                writer.write('\n    ')
            elif i % 8 == 0:
                writer.write(',\n    ')
            else:
                writer.write(', ')
            writer.write('0x' + case[0])
        writer.write('\n};\n')

        writer.write('\nconst int32_t {}_CASE[] = {{'.format(name))
        for i, case in enumerate(cases):
            if i == 0:
                writer.write('\n    ')
            elif i % 8 == 0:
                writer.write(',\n    ')
            else:
                writer.write(', ')
            writer.write('0x' + case[1])
        writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')
