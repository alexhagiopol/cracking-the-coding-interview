//
// Created by alex on 7/31/17.
//

#include "cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.h"
#include "cpp_solutions/chapter_05_bit_manipulation/problem_05_01_insertion.h"
#include "cpp_solutions/chapter_05_bit_manipulation/problem_05_02_binaryToString.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(isUnique("alex"));
    REQUIRE(!isUnique("aalex"));
}

TEST_CASE("Chapter 05 - Problem 01 - insertion()", "test"){
    REQUIRE(insertion(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
}

TEST_CASE("Chapter 05 - Problem 02 - binaryToString()", "test") {
    std::string binary_string_1 = "";
    std::string binary_string_2 = "";
    std::string binary_string_3 = "";
    std::string binary_string_4 = "";
    REQUIRE(binaryToString(0.5, binary_string_1) == 0);
    REQUIRE(binaryToString(0.25, binary_string_2) == 0);
    REQUIRE(binaryToString(1.5, binary_string_3) == -1);
    REQUIRE(binaryToString(0.722, binary_string_4) == 0);
    REQUIRE(binary_string_1 == "0.1");
    REQUIRE(binary_string_2 == "0.01");
    REQUIRE(binary_string_3 == "");
    REQUIRE(binary_string_4 == "0.10111000110101001111110111110011"); // needs double precision to work
}


