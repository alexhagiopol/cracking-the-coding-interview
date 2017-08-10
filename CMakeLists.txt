cmake_minimum_required(VERSION 3.2)
project(cracking_the_coding_interview)
set(CMAKE_CXX_STANDARD 11)
# source folder
include_directories(cpp_solutions)
# find Eigen installed on system
set(CMAKE_MODULE_PATH cpp_solutions/third_party/eigen/cmake)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
# set source files
set(SOURCE_FILES
        tests.cpp
        )
# create executable
add_executable(tests ${SOURCE_FILES})
