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
#include "unicode_data.h"

using unicode::GeneralCategory;


int findLowerBound(const int array[], int total, int target) {
    if (target < array[0]) {
        return -1;
    }
    if (target > array[total - 1]) {
        return total - 1;
    }
    int l = 0, r = total - 1, index = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] < target) {
            l = mid + 1;
            if (mid > index) {
                index = mid;
            }
        } else {
            r = mid - 1;
        }
    }
    return index;
}

int getCodeIndex(int code) {
    if (code <= CONTINUOUS_NUM) {
        return code;
    }
    return findLowerBound(CODE_VALUE, CODE_NUM, code);
}

GeneralCategory unicode::getGeneralCategory(int code) {
    return GENERAL_CATEGORY[getCodeIndex(code)];
}

int getCase(const int indices[], const int cases[], int total, int code) {
    int index = findLowerBound(indices, total, code);
    if (index == -1 || indices[index] != code) {
        return code;
    }
    return cases[index];
}

int unicode::getUpperCase(int code) {
    return getCase(UPPER_INDEX, UPPER_CASE, UPPER_NUM, code);
}

int unicode::getLowerCase(int code) {
    return getCase(LOWER_INDEX, LOWER_CASE, LOWER_NUM, code);
}

int unicode::getTitleCase(int code) {
    return getCase(TITLE_INDEX, TITLE_CASE, TITLE_NUM, code);
}
