//
// Created by alex on 7/31/17.
//

#include "cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.h"
#include "cpp_solutions/chapter_05_bit_manipulation/problem_05_01_insertion.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(isUnique("alex"));
    REQUIRE(!isUnique("aalex"));
}

TEST_CASE("Chapter 05 - Problem 01 - insertion()", "test"){
    REQUIRE(insertion(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
}

