cmake_minimum_required(VERSION 3.5)

add_executable(FizzBuzzTests
    FizzBuzzTests.cpp
    )

find_package(GTest REQUIRED)
target_link_libraries(FizzBuzzTests PUBLIC FizzBuzz GTest::gtest GTest::gtest_main)
target_include_directories(FizzBuzzTests PRIVATE ..)

add_test(NAME FizzBuzzTests COMMAND FizzBuzzTests)
