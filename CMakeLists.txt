cmake_minimum_required(VERSION 3.20)

project(11402_CS351_Project0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(twosum
    src/main.cpp
    src/twosum.cpp
)

add_executable(test_twosum
    tests/test_twosum.cpp
    src/twosum.cpp
)

add_executable(twosum_test
    tests/twosum_test.cpp
    src/twosum.cpp
)

enable_testing()
add_test(NAME test_twosum COMMAND test_twosum)
add_test(NAME case_basic COMMAND twosum_test basic)
add_test(NAME case_negative COMMAND twosum_test negative)
add_test(NAME case_duplicate COMMAND twosum_test duplicate)
add_test(NAME case_no_solution COMMAND twosum_test no_solution)
add_executable(twosum_tests tests/twosum_tests.cpp)
add_test(NAME TwoSumTests COMMAND twosum_tests)