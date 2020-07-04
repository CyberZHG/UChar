/* Copyright 2020 Zhao HG

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
SOFTWARE. */
#include "unicode_char.h"

namespace unicode {

std::string toUTF8(int32_t code) {
    if (code < 0) {
        throw std::runtime_error("The Unicode value is invalid: " +
                                 std::to_string(code));
    }
    std::string str;
    char bytes[6];
    if (code <= 0x7f) {
        str += static_cast<char>(code);
    } else {
        int len = 0;
        if (code <= 0x7ff) {
            len = 2;
        } else if (code <= 0xffff) {
            len = 3;
        } else if (code <= 0x1fffff) {
            len = 4;
        } else if (code <= 0x3ffffff) {
            len = 5;
        } else {
            len = 6;
        }
        for (int i = 0; i < len - 1; ++i) {
            bytes[i] = static_cast<char>(128 | (code & 63));
            code >>= 6;
        }
        bytes[len - 1] = static_cast<char>((255 ^ (63 >> (len - 2))) | code);
        for (int i = len - 1; i >= 0; --i) {
            str.push_back(bytes[i]);
        }
    }
    return str;
}

int32_t fromUTF8(const std::string& str) {
    if (str.empty()) {
        throw std::runtime_error("The input UTF8 character cannot be empty");
    }
    if ((str[0] & 128) == 0) {
        return str[0];
    }
    size_t len = 2;
    for (int i = (1 << 5); (str[0] & i) > 0; i >>= 1) {
        ++len;
    }
    if (len > str.length()) {
        throw std::runtime_error("The input UTF8 character is too short, "
                                 "expect " + std::to_string(len) + ", "
                                 "got " + std::to_string(str.length()));
    }
    int32_t code = str[0] & (31 >> (len - 2));
    for (size_t k = 1; k < len; ++k) {
        code = (code << 6) | (str[k] & 63);
    }
    return code;
}

};  // namespace unicode
