//
// Created by Alex Hagiopol on 8/6/17.
//

#pragma once
#include "problem_08_01_tripleStep.cpp"
#include "problem_08_02_robotGrid.cpp"
#include "problem_08_03_magicIndex.cpp"
#include "problem_08_04_powerSet.cpp"
#include "problem_08_05_recursiveMultiply.cpp"
#include "problem_08_06_hanoiTowers.cpp"
#include "problem_08_07_permutationsNoDups.cpp"
#include "problem_08_08_permutationsWithDups.cpp"
#include "problem_08_09_parens.cpp"
#include "problem_08_10_paintFill.cpp"
#include "problem_08_11_coins.cpp"
#include "problem_08_12_eightQueens.cpp"
#include "problem_08_13_stackOfBoxes.cpp"
#include "problem_08_14_booleanEvaluation.cpp"

namespace chapter_08{
    int tripleStep(int n);  // problem 08-01
    bool robotGrid(const Eigen::MatrixXd& maze, std::vector<Eigen::Vector2d>& path);  // problem 08-02
    int magicIndex(const std::vector<int>& array);  // problem 08-03
    void createPowerSet(std::vector<int> set, std::vector<std::vector<int>>& powerSet);  // problem 08-04
    int recursiveMultiply(int a, int b);  // problem 08-05
    void paintFill(Eigen::MatrixXi& image, Eigen::Vector2i location, uint8_t targetColor);  // problem 08-10
}