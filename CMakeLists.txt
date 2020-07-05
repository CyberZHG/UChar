cmake_minimum_required(VERSION 4.0)
project(UChar)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

option(UCHAR_ENABLE_TESTS "Build tests" OFF)
option(UCHAR_ENABLE_STRICT "Use strict compile options" OFF)
option(UCHAR_ENABLE_COVERAGE "Enable coverage reporting" OFF)

if(APPLE)
    set(ENV{PKG_CONFIG_PATH} "/opt/homebrew/lib/pkgconfig:$ENV{PKG_CONFIG_PATH}")
endif()

if(UCHAR_ENABLE_STRICT)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        add_compile_options(
                -Wall
                -Wextra
                -Werror
                -Wpedantic
                -Wmissing-include-dirs
                -Wundef
                -Wredundant-decls
        )
    endif()
endif()

if(UCHAR_ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        add_compile_options(--coverage -O0 -g -fno-elide-constructors -fno-default-inline)
        add_link_options(--coverage)
    endif()
endif()

add_library(UChar STATIC
        include/unicode_char.h
        src/unicode_char.cpp
        include/unicode_data.h
        src/bidirectional_category.cpp
        src/canonical_combining_class.cpp
        src/cases.cpp
        src/code_value.cpp
        src/decomposition_mapping.cpp
        src/encode.cpp
        src/general_category.cpp
        src/mirrored.cpp
        src/numeric.cpp
)

target_include_directories(UChar
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(UCHAR_ENABLE_TESTS)
    enable_testing()

    include(FetchContent)

    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.17.0
    )

    FetchContent_MakeAvailable(googletest)

    add_executable(runTests
            tests/main.cpp
            tests/test_bidirectional_category_gen.cpp
            tests/test_canonical_combining_class.cpp
            tests/test_canonical_combining_class_gen.cpp
            tests/test_cases.cpp
            tests/test_decomposition_mapping_gen.cpp
            tests/test_encode.cpp
            tests/test_general_category.cpp
            tests/test_general_category_gen.cpp
            tests/test_mirrored.cpp
            tests/test_numeric.cpp
    )

    target_link_libraries(runTests
            PRIVATE UChar
            PRIVATE gtest gtest_main
    )

    add_test(NAME UCharTests COMMAND runTests)
endif ()
