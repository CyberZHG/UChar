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
with open('include/unicode_data.h', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())
    writer.write('#ifndef INCLUDE_UNICODE_DATA_H_\n')
    writer.write('#define INCLUDE_UNICODE_DATA_H_\n\n')
    writer.write('/**\n * @file\n * @brief Unicode information about a character.\n */\n\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('namespace unicode {\n\n')

with open('include/unicode_char.h', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())
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
