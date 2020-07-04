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
#include "unicode_data.h"

namespace unicode {


const int32_t MIRRORED_INDEX[] = {
    0x0000, 0x0028, 0x002A, 0x003C, 0x003D, 0x003E, 0x003F, 0x005B,
    0x005C, 0x005D, 0x005E, 0x007B, 0x007C, 0x007D, 0x007E, 0x00AB,
    0x00AC, 0x00BB, 0x00BC, 0x0F3A, 0x0F3E, 0x169B, 0x16A0, 0x2039,
    0x203B, 0x2045, 0x2047, 0x207D, 0x207F, 0x208D, 0x2090, 0x2140,
    0x2141, 0x2201, 0x2205, 0x2208, 0x220E, 0x2211, 0x2212, 0x2215,
    0x2217, 0x221A, 0x221E, 0x221F, 0x2223, 0x2224, 0x2225, 0x2226,
    0x2227, 0x222B, 0x2234, 0x2239, 0x223A, 0x223B, 0x224D, 0x2252,
    0x2256, 0x225F, 0x2261, 0x2262, 0x2263, 0x2264, 0x226C, 0x226E,
    0x228D, 0x228F, 0x2293, 0x2298, 0x2299, 0x22A2, 0x22A4, 0x22A6,
    0x22B9, 0x22BE, 0x22C0, 0x22C9, 0x22CE, 0x22D0, 0x22D2, 0x22D6,
    0x22EE, 0x22F0, 0x2300, 0x2308, 0x230C, 0x2320, 0x2322, 0x2329,
    0x232B, 0x2768, 0x2776, 0x27C0, 0x27C1, 0x27C3, 0x27C7, 0x27C8,
    0x27CA, 0x27CB, 0x27CE, 0x27D3, 0x27D7, 0x27DC, 0x27DF, 0x27E2,
    0x27F0, 0x2983, 0x2999, 0x299B, 0x29A1, 0x29A2, 0x29B0, 0x29B8,
    0x29B9, 0x29C0, 0x29C6, 0x29C9, 0x29CA, 0x29CE, 0x29D3, 0x29D4,
    0x29D6, 0x29D8, 0x29DD, 0x29E1, 0x29E2, 0x29E3, 0x29E6, 0x29E8,
    0x29EA, 0x29F4, 0x29FA, 0x29FC, 0x29FE, 0x2A0A, 0x2A1D, 0x2A1E,
    0x2A22, 0x2A24, 0x2A25, 0x2A26, 0x2A27, 0x2A29, 0x2A2A, 0x2A2B,
    0x2A2F, 0x2A34, 0x2A36, 0x2A3C, 0x2A3F, 0x2A57, 0x2A59, 0x2A64,
    0x2A66, 0x2A6A, 0x2A6E, 0x2A6F, 0x2A71, 0x2A73, 0x2A75, 0x2A79,
    0x2AA4, 0x2AA6, 0x2AAE, 0x2AAF, 0x2AD7, 0x2ADC, 0x2ADD, 0x2ADE,
    0x2ADF, 0x2AE2, 0x2AE7, 0x2AEC, 0x2AEF, 0x2AF3, 0x2AF4, 0x2AF7,
    0x2AFC, 0x2AFD, 0x2AFE, 0x2BFE, 0x2BFF, 0x2E02, 0x2E06, 0x2E09,
    0x2E0B, 0x2E0C, 0x2E0E, 0x2E1C, 0x2E1E, 0x2E20, 0x2E2A, 0x3008,
    0x3012, 0x3014, 0x301C, 0xFE59, 0xFE5F, 0xFE64, 0xFE66, 0xFF08,
    0xFF0A, 0xFF1C, 0xFF1D, 0xFF1E, 0xFF1F, 0xFF3B, 0xFF3C, 0xFF3D,
    0xFF3E, 0xFF5B, 0xFF5C, 0xFF5D, 0xFF5E, 0xFF5F, 0xFF61, 0xFF62,
    0xFF64, 0x1D6DB, 0x1D6DC, 0x1D715, 0x1D716, 0x1D74F, 0x1D750, 0x1D789,
    0x1D78A, 0x1D7C3, 0x1D7C4
};

const bool MIRRORED_VALUE[] = {
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false, true, false, true,
    false, true, false, true, false, true, false
};

}  // namespace unicode
