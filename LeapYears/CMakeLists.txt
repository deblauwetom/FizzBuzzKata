cmake_minimum_required(VERSION 3.5)

add_library(LeapYears
    LeapYears.hpp
    LeapYears.cpp
    )

add_subdirectory(tests)
