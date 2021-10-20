cmake_minimum_required(VERSION 3.5)

add_library(FizzBuzz
    FizzBuzzGame.cpp
    FizzBuzzGame.hpp
    )

add_subdirectory(tests)
