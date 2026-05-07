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

enable_testing()
add_test(NAME test_twosum COMMAND test_twosum)
