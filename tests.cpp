//
// Created by alex on 7/31/17.
//

#include "cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.h"
//#include <iostream>
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(isUnique("alex"));
    REQUIRE(!isUnique("aalex"));
}

