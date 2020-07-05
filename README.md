# UChar

## Basic Information

### General Category

Get the type of a character:

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(getGeneralCategory(0x370) == GeneralCategory::Lu);
assert(getBaseGeneralCategory(0x21) == BaseGeneralCategory::P);
```

### Canonical Combining Classes

The canonical combining classes are integers, as they are defined as integer values:

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(getCanonicalCombiningClass(0x302C) == 232);
```

### Bidirectional Category

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(getBidirectionalCategory(0x0030) == BidirectionalCategory::EN);
```

### Decimal/Digit/Numeric Values

If the character has any numeric properties:

```cpp
#include <cmath>
#include "unicode_char.h"
using namespace unicode;

UChar code = static_cast<UChar>('3')
assert(getDecimalDigitValue(code) == 3);
assert(getDigitValue(code) == 3);
assert(fabs(getNumericValue(code) - 3.0) <= 1e-8));
auto fraction = getNumericFraction(code);
assert(fraction.first == 3);
assert(fraction.second == 1);
```

`༳` represents `-1/2`:

```cpp
#include <cmath>
#include "unicode_char.h"
using namespace unicode;

UChar code = 0x0F33;
assert(fabs(getNumericValue(code) - (-0.5)) <= 1e-8));
auto fraction = getNumericFraction(code);
assert(fraction.first == -1);
assert(fraction.second == 2);
```

### Mirrored

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(isMirrored(0x3C));
```

### Upper/Lower/Title Cases

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(getUpperCase(static_cast<UChar>('a') == static_cast<UChar>('A'));
assert(getLowerCase(static_cast<UChar>('A') == static_cast<UChar>('a'));
assert(getTitleCase(static_cast<UChar>('a') == static_cast<UChar>('A'));
```

### Decomposition Mapping

The character `㉐` is the partnership sign, and its decomposition is `PTE`:

```cpp
#include "unicode_char.h"
using namespace unicode;

assert(getDecompositionMappingTag(0x3250)) == DecompositionMappingTag::SQUARE);
auto decomposition = getDecompositionMapping(0x3250);
assert(decomposition.size() == 3u);
assert(decomposition[0] == 0x50);
assert(decomposition[1] == 0x54);
assert(decomposition[2] == 0x45);

UChar buffer[16];
getDecompositionMapping(0x3250, buffer);
assert(buffer[0] == 0x50);
assert(buffer[1] == 0x54);
assert(buffer[2] == 0x45);
assert(buffer[3] == 0);
```

## Encoding & Decoding

Code points can be converted to UTF-8 or UTF-16 strings, and vice versa.

Here is an example of converting a UTF-8 encoded string to code points:

```cpp
#include "unicode_char.h"

auto codes = unicode::fromUTF8("你好，世界！");
std::cout << std::hex;
for (auto code : codes) {
    std::cout << "0x" << code << " ";
}
std::cout << std::endl;
// Outputs should be: "0x4f60 0x597d 0xff0c 0x4e16 0x754c 0xff01 "
```

You can also convert it back to a UTF-8 string:

```cpp
auto str = unicode::toUTF8(codes);
std::cout << str << std::endl;
// Outputs should be: "你好，世界！"
```

The same applies to UTF-16 strings, but the related functions use `std::u16string` as both input and output.
