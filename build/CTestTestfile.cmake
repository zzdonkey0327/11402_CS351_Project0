# CMake generated Testfile for 
# Source directory: E:/School/1142/AI-assisted/Repos/11402_CS351_Project0
# Build directory: E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[test_twosum]=] "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build/test_twosum.exe")
set_tests_properties([=[test_twosum]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;25;add_test;E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;0;")
add_test([=[case_basic]=] "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build/twosum_test.exe" "basic")
set_tests_properties([=[case_basic]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;26;add_test;E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;0;")
add_test([=[case_negative]=] "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build/twosum_test.exe" "negative")
set_tests_properties([=[case_negative]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;27;add_test;E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;0;")
add_test([=[case_duplicate]=] "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build/twosum_test.exe" "duplicate")
set_tests_properties([=[case_duplicate]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;28;add_test;E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;0;")
add_test([=[case_no_solution]=] "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/build/twosum_test.exe" "no_solution")
set_tests_properties([=[case_no_solution]=] PROPERTIES  _BACKTRACE_TRIPLES "E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;29;add_test;E:/School/1142/AI-assisted/Repos/11402_CS351_Project0/CMakeLists.txt;0;")
