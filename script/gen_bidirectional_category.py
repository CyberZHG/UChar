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
    writer.write('#include "unicode_data.h"\n\n')
    writer.write('namespace unicode {\n\n')

    for category in unique_categories:
        writer.write('constexpr auto {} = BidirectionalCategory::{};\n'.format(category, category))
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
    writer.write("""#include <gtest/gtest.h>
#include <sstream>
#include "unicode_char.h"

TEST(BidirectionalCategoryGenTest, test_cats) {
    std::stringstream ss;
""")
    appeared = set()
    with open('UnicodeData.txt', 'r') as reader:
        for line in reader:
            parts = line.strip().split(';')
            category = parts[4]
            if category not in appeared:
                appeared.add(category)
                writer.write(f"    EXPECT_EQ(unicode::BidirectionalCategory::{category}, "
                             f"unicode::getBidirectionalCategory(0x{parts[0]}));\n")
                writer.write(f"""    ss << unicode::BidirectionalCategory::{category};
    EXPECT_EQ("{category}", ss.str());
    ss.str("");
    ss.clear();
""")
    writer.write('}\n')
