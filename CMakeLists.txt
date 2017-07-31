cmake_minimum_required(VERSION 3.5)
project(cracking_the_coding_interview)

set(CMAKE_CXX_STANDARD 11)

include_directories(cpp_solutions)

set(SOURCE_FILES
        tests.cpp
        )

add_executable(tests ${SOURCE_FILES})