cmake_minimum_required(VERSION 3.5)

add_executable(LeapYearsTests
    LeapYearsTests.cpp
    )

find_package(GTest REQUIRED)
target_link_libraries(LeapYearsTests PUBLIC LeapYears GTest::gtest GTest::gtest_main)
target_include_directories(LeapYearsTests PRIVATE ..)

add_test(NAME LeapYearsTests COMMAND LeapYearsTests)
