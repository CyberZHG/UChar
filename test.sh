#!/usr/bin/env bash
cd tests && \
    find . -name "*.gcda" -delete && \
    cmake . && \
    make all && \
    ./test && \
    mkdir -p coverage && \
    lcov --directory . --capture --output-file ./coverage/coverage.info && \
    lcov --remove ./coverage/coverage.info "/usr/*" "/Applications/*" "*v1*" "*/deps/*" "tests" -o ./coverage/filtered.info && \
    genhtml ./coverage/filtered.info --branch-coverage --output-directory ./coverage/report
