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
    categories = [line.strip().split(';')[4] for line in reader]
    unique_categories = list(sorted(list(set(categories))))

with open('include/unicode_char.h', 'a') as writer:
    writer.write('enum class BidirectionalCategory {')
    for i, category in enumerate(unique_categories):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(category)
    writer.write('\n};\n\n')

    writer.write('/** Outputs the bidirectional category with its name. */\n')
    writer.write('std::ostream& operator<<(std::ostream&, BidirectionalCategory);\n\n')

with open('include/unicode_data.h', 'a') as writer:
    writer.write('/** The types of bidirectional category. */\n')
    writer.write('extern const BidirectionalCategory BIDIRECTIONAL_CATEGORY[];\n\n')

with open('src/bidirectional_category.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    for category in unique_categories:
        writer.write('const BidirectionalCategory {} = BidirectionalCategory::{};\n'.format(category, category))
    writer.write("\n")

    writer.write('std::ostream& operator<<(std::ostream& os, BidirectionalCategory c) {\n')
    writer.write('    switch (c) {\n')
    for category in unique_categories:
        writer.write('    case {}: os << "{}"; break;\n'.format(category, category))
    writer.write('    }\n')
    writer.write('    return os;\n')
    writer.write('}\n\n')

    writer.write('\nconst BidirectionalCategory BIDIRECTIONAL_CATEGORY[] = {')
    for i, category in enumerate(categories):
        if i == 0:
            writer.write('\n    ')
        elif i % 10 == 0:
            writer.write(',\n    ')
        else:
            writer.write(', ')
        writer.write(category)
    writer.write('\n};\n\n')

    writer.write('}  // namespace unicode\n')

with open('tests/test_bidirectional_category_gen.cpp', 'w') as writer:
    with open('copyright.txt', 'r') as reader:
        writer.write(reader.read())

    writer.write('#include "test.h"\n')
    writer.write('#include "unicode_char.h"\n\n')
    writer.write('namespace test {\n\n')

    writer.write('class BidirectionalCategoryGenTest : public UnitTest {};\n\n')

    writer.write('__TEST_U(BidirectionalCategoryGenTest, test_cats) {\n')
    appeared = set()
    with open('UnicodeData.txt', 'r') as reader:
        for line in reader:
            parts = line.strip().split(';')
            category = parts[4]
            if category not in appeared:
                appeared.add(category)
                writer.write('    __ASSERT_EQ(unicode::BidirectionalCategory::{}, '
                             'unicode::getBidirectionalCategory({}));\n'.format(
                                category, '0x' + parts[0]))
    writer.write('}\n\n')

    writer.write('}  // namespace test\n')
