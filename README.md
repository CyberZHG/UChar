UChar
=====

## Encoding & Decoding

The code points can be converted to UTF-8 or UTF-16 string, and vice versa.

An example to convert a UTF-8 encoded string to the code points:

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

And you can convert it back to the UTF-8 string:

```cpp
auto str = unicode::toUTF8(codes);
std::cout << str << std::endl;
// Outputs should be: "你好，世界！"
```

It's the same with UTF-16 string, but the related functions uses `std::u16string` as input and output.
