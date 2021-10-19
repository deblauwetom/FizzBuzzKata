cmake_minimum_required(VERSION 3.5)

project(katas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
include(${CMAKE_CURRENT_LIST_DIR}/conan.cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

conan_cmake_configure(REQUIRES gtest/cci.20210126
                      GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})

add_library(katas
    game.cpp
    game.hpp
    )

add_executable(katasTest test.cpp)

find_package(GTest REQUIRED)
target_link_libraries(katasTest PUBLIC katas GTest::gtest GTest::gtest_main)
add_test(NAME katasTest COMMAND katasTest)
