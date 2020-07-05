#!/usr/bin/env bash
if [[ ! -f "UnicodeData.txt" ]]; then
    wget ftp://ftp.unicode.org/Public/UNIDATA/UnicodeData.txt
fi
