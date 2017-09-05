//
// Created by alex on 7/31/17.
//

//#include "cpp_solutions/chapter_01_arrays_and_strings/problem_01_01_isUnique.h"
#include "cpp_solutions/chapter_01_arrays_and_strings/chapter_01_includes.h"
#include "cpp_solutions/chapter_02_linked_lists/chapter_02_includes.h"
#include "cpp_solutions/chapter_05_bit_manipulation/chapter_05_includes.h"
#include "cpp_solutions/chapter_08_recursion_and_dynamic_programming/chapter_08_includes.h"
#define CATCH_CONFIG_MAIN
#include "cpp_solutions/third_party/Catch/include/catch.hpp"
#include <vector>
#include <Eigen/Dense>

TEST_CASE("Chapter 01 - Problem 01 - isUnique()", "test"){
    REQUIRE(chapter_01::isUnique("alex"));
    REQUIRE(!chapter_01::isUnique("aalex"));
    //REQUIRE(isUnique("alex"));
    //REQUIRE(!isUnique("aalex"));

}

TEST_CASE("Chapter 01 - Problem 02 - isPermutation()", "test"){
    REQUIRE(!chapter_01::isPermutation("alex", "alexa"));
    REQUIRE(chapter_01::isPermutation("aa", "aa"));
    REQUIRE(chapter_01::isPermutation("alex", "lexa"));
    REQUIRE(chapter_01::isPermutation("alex", "xela"));
    REQUIRE(chapter_01::isPermutation("", ""));
    REQUIRE(!chapter_01::isPermutation("cat", "ctt"));
    REQUIRE(!chapter_01::isPermutation("alexxx", "xxxxxx"));
}

TEST_CASE("Chapter 01 - Problem 07 - rotate()", "test"){
    Eigen::MatrixXi input4x4(4,4);
    input4x4 << 1, 2, 3, 4,
                1, 2, 3, 4,
                1, 2, 3, 4,
                1, 2, 3, 4;

    Eigen::MatrixXi input5x5(5,5);
    input5x5 << 1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5,
                1, 2, 3, 4, 5;

    Eigen::MatrixXi output4x4(4,4);
    output4x4 << 1, 1, 1, 1,
                 2, 2, 2, 2,
                 3, 3, 3, 3,
                 4, 4, 4, 4;

    Eigen::MatrixXi output5x5(5,5);
    output5x5 << 1, 1, 1, 1, 1,
                 2, 2, 2, 2, 2,
                 3, 3, 3, 3, 3,
                 4, 4, 4, 4, 4,
                 5, 5, 5, 5, 5;

    chapter_01::rotate(input4x4);
    chapter_01::rotate(input5x5);
    REQUIRE(input4x4.isApprox(output4x4));
    REQUIRE(input5x5.isApprox(output5x5));
}

TEST_CASE("Chapter 02 - Basic LinkedList Functionality", "test"){
    std::vector<int> testVector = {1,2,3,4,5,6,7};
    REQUIRE(testVector == chapter_02::listToVector(chapter_02::vectorToList(testVector)));
}

TEST_CASE("Chapter 02 - Problem 01 - removeDups()", "test"){
    std::vector<int> noDups = {1,7,3,6,5,4,2};
    std::vector<int> dups = {2,2,1,5,6,2,5,2,7,7};
    std::vector<int> fixedDups = {2,1,5,6,7};
    std::vector<int> emptyVec;

    // check that remove dups function doesn't affect lists with no dups
    chapter_02::LinkedListNode<int>* noDupsHead = chapter_02::vectorToList(noDups);
    chapter_02::removeDups(noDupsHead);
    REQUIRE(noDups == chapter_02::listToVector(noDupsHead));

    // check case with duplicates
    chapter_02::LinkedListNode<int>* dupsHead = chapter_02::vectorToList(dups);
    chapter_02::removeDups(dupsHead);
    REQUIRE(fixedDups == chapter_02::listToVector(dupsHead));

    // check case with empty list
    chapter_02::LinkedListNode<int>* emptyHead = chapter_02::vectorToList(emptyVec);
    chapter_02::removeDups(emptyHead);
    REQUIRE(emptyVec == chapter_02::listToVector(emptyHead));
}

TEST_CASE("Chapter 02 - Problem 02 - returnKthToLast()", "test"){
    std::vector<int> vec1 = {1,7,3,6,5,4,2};
    std::vector<int> vec2 = {2,2,1,5,6,2,5,2,7,7};
    std::vector<int> vec3;
    chapter_02::LinkedListNode<int>* vec1Head = chapter_02::vectorToList(vec1);
    chapter_02::LinkedListNode<int>* vec2Head = chapter_02::vectorToList(vec2);
    chapter_02::LinkedListNode<int>* vec3Head = chapter_02::vectorToList(vec3);
    REQUIRE(5 == chapter_02::returnKthToLast(vec1Head, 3)->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(vec1Head, 1)->getValue());
    REQUIRE(1 == chapter_02::returnKthToLast(vec1Head, vec1.size())->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(vec2Head, 3)->getValue());
    REQUIRE(7 == chapter_02::returnKthToLast(vec2Head, 1)->getValue());
    REQUIRE(2 == chapter_02::returnKthToLast(vec2Head, vec2.size())->getValue());
    REQUIRE(nullptr == chapter_02::returnKthToLast(vec2Head, 0));
    REQUIRE(nullptr == chapter_02::returnKthToLast(vec1Head, 10));
    REQUIRE(nullptr == chapter_02::returnKthToLast(vec3Head, 10));
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

TEST_CASE("Chapter 05 - Problem 07 - pairwiseSwap()", "test"){
    REQUIRE(chapter_05::pairwiseSwap(0b10101010) == 0b01010101);
    REQUIRE(chapter_05::pairwiseSwap(0b11110000) == 0b11110000);
    REQUIRE(chapter_05::pairwiseSwap(0b110) == 0b1001);
}

TEST_CASE("Chapter 08 - Problem 01 - tripleStep()", "test"){
    REQUIRE(chapter_08::tripleStep(3) == 4);
    REQUIRE(chapter_08::tripleStep(4) == 7);
    REQUIRE(chapter_08::tripleStep(5) == 13);
}

TEST_CASE("Chapter 08 - Problem 02 - robotGrid()", "test"){

    Eigen::MatrixXd maze(5, 5);
    maze << 1, 1, 1, 0, 1,
            0, 0, 1, 1, 1,
            0, 1, 1, 0, 0,
            0, 1, 1, 0, 1,
            1, 1, 1, 1, 1;
    std::vector<Eigen::Vector2d> expectedPath = {Eigen::Vector2d(0,0),
                                                 Eigen::Vector2d(0,1),
                                                 Eigen::Vector2d(0,2),
                                                 Eigen::Vector2d(1,2),
                                                 Eigen::Vector2d(2,2),
                                                 Eigen::Vector2d(3,2),
                                                 Eigen::Vector2d(4,2),
                                                 Eigen::Vector2d(4,3),
                                                 Eigen::Vector2d(4,4)};
    std::vector<Eigen::Vector2d> path;
    REQUIRE(chapter_08::robotGrid(maze, path));
    REQUIRE(path == expectedPath);
}

TEST_CASE("Chapter 08 - Problem 03 - magicIndex()", "test"){
    std::vector<int> noMagicIndex = {-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> magicIndex5 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> magicIndex7 = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    REQUIRE(chapter_08::magicIndex(noMagicIndex) == -1);
    REQUIRE(chapter_08::magicIndex(magicIndex5) == 5);
    REQUIRE(chapter_08::magicIndex(magicIndex7) == 7);
}

TEST_CASE("Chapter 08 - Problem 04 - powerSet()", "test"){
    std::vector<int> set123 = {1, 2, 3};
    std::vector<int> set12 = {1, 2};
    std::vector<int> set13 = {1, 3};
    std::vector<int> set23 = {2, 3};
    std::vector<int> set1 = {1};
    std::vector<int> set2 = {2};
    std::vector<int> set3 = {3};
    std::vector<int> emptySet = {};

    std::vector<std::vector<int>> powerSet123 = {emptySet, set1, set2, set12, set3, set13, set23, set123};
    std::vector<std::vector<int>> powerSet12 = {emptySet, set1, set2, set12};
    std::vector<std::vector<int>> powerSet1 = {emptySet, set1};

    std::vector<std::vector<int>> testPowerSet = {};
    chapter_08::createPowerSet(set123, testPowerSet);
    REQUIRE(testPowerSet == powerSet123);
    testPowerSet = {};
    chapter_08::createPowerSet(set12, testPowerSet);
    REQUIRE(testPowerSet == powerSet12);
    testPowerSet = {};
    chapter_08::createPowerSet(set1, testPowerSet);
    REQUIRE(testPowerSet == powerSet1);
};

TEST_CASE("Chapter 08 - Problem 05 - recursiveMultiply()", "test"){
    REQUIRE(chapter_08::recursiveMultiply(1, 1) == 1);
    REQUIRE(chapter_08::recursiveMultiply(1, 2) == 2);
    REQUIRE(chapter_08::recursiveMultiply(0, 1) == 0);
    REQUIRE(chapter_08::recursiveMultiply(9, 10) == 90);
    REQUIRE(chapter_08::recursiveMultiply(9, 11) == 99);
    REQUIRE(chapter_08::recursiveMultiply(12, 12) == 144);
}

TEST_CASE("Chapter 08 - Problem 10 - paintFill()", "test"){
    Eigen::MatrixXi image(6, 6);
    image << 0, 1, 1, 0, 0, 3,
             1, 1, 1, 1, 0, 0,
             0, 1, 1, 0, 0, 2,
             0, 0, 0, 0, 2, 2,
             0, 2, 2, 2, 2, 2,
             0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi zerosFilled(6, 6);
    zerosFilled << 0, 1, 1, 5, 5, 3,
                   1, 1, 1, 1, 5, 5,
                   5, 1, 1, 5, 5, 2,
                   5, 5, 5, 5, 2, 2,
                   5, 2, 2, 2, 2, 2,
                   5, 5, 5, 2, 2, 2;
    Eigen::MatrixXi onesFilled(6, 6);
    onesFilled << 0, 5, 5, 0, 0, 3,
                  5, 5, 5, 5, 0, 0,
                  0, 5, 5, 0, 0, 2,
                  0, 0, 0, 0, 2, 2,
                  0, 2, 2, 2, 2, 2,
                  0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi twosFilled(6, 6);
    twosFilled << 0, 1, 1, 0, 0, 3,
                  1, 1, 1, 1, 0, 0,
                  0, 1, 1, 0, 0, 5,
                  0, 0, 0, 0, 5, 5,
                  0, 5, 5, 5, 5, 5,
                  0, 0, 0, 5, 5, 5;
    Eigen::MatrixXi threeFilled(6, 6);
    threeFilled << 0, 1, 1, 0, 0, 5,
                   1, 1, 1, 1, 0, 0,
                   0, 1, 1, 0, 0, 2,
                   0, 0, 0, 0, 2, 2,
                   0, 2, 2, 2, 2, 2,
                   0, 0, 0, 2, 2, 2;
    Eigen::MatrixXi expectedZerosFilled = image;
    Eigen::MatrixXi expectedOnesFilled = image;
    Eigen::MatrixXi expectedTwosFilled = image;
    Eigen::MatrixXi expectedThreeFilled = image;
    chapter_08::paintFill(expectedZerosFilled, Eigen::Vector2i(2, 0), 5);
    chapter_08::paintFill(expectedOnesFilled, Eigen::Vector2i(1, 2), 5);
    chapter_08::paintFill(expectedTwosFilled, Eigen::Vector2i(4, 3), 5);
    chapter_08::paintFill(expectedThreeFilled, Eigen::Vector2i(0, 5), 5);
    REQUIRE(zerosFilled.isApprox(expectedZerosFilled));
    REQUIRE(onesFilled.isApprox(expectedOnesFilled));
    REQUIRE(twosFilled.isApprox(expectedTwosFilled));
    REQUIRE(threeFilled.isApprox(expectedThreeFilled));
}