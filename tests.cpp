//
// Created by alex on 7/31/17.
//

#include "cpp_solutions/chapter_01_arrays_and_strings/chapter_01_includes.h"
#include "cpp_solutions/chapter_05_bit_manipulation/chapter_05_includes.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(chapter_01::isUnique("alex"));
    REQUIRE(!chapter_01::isUnique("aalex"));
}

TEST_CASE("Chapter 05 - Problem 01 - insertion()", "test"){
    REQUIRE(chapter_05::insertion(0b10000000000, 0b10011, 2, 6) == 0b10001001100);
}

TEST_CASE("Chapter 05 - Problem 02 - binaryToString()", "test") {
    std::string binary_string_1 = "";
    std::string binary_string_2 = "";
    std::string binary_string_3 = "";
    std::string binary_string_4 = "";
    REQUIRE(chapter_05::binaryToString(0.5, binary_string_1) == 0);
    REQUIRE(chapter_05::binaryToString(0.25, binary_string_2) == 0);
    REQUIRE(chapter_05::binaryToString(1.5, binary_string_3) == -1);
    REQUIRE(chapter_05::binaryToString(0.722, binary_string_4) == 0);
    REQUIRE(binary_string_1 == "0.1");
    REQUIRE(binary_string_2 == "0.01");
    REQUIRE(binary_string_3 == "");
    REQUIRE(binary_string_4 == "0.10111000110101001111110111110011"); // needs double precision to work
}

TEST_CASE("Chapter 05 - Problem 06 - conversion()", "test"){
    REQUIRE(chapter_05::conversion(0b11001100, 0b11110000) == 4);
    REQUIRE(chapter_05::conversion(29, 15) == 2);
}

