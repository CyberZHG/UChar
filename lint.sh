#!/usr/bin/env bash
pycodestyle --max-line-length=120 script/*.py && \
    cpplint --linelength=120 --filter=-build/include_subdir include/*.h src/*.cpp tests/*.cpp
