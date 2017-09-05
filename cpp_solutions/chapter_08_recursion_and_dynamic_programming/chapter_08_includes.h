//
// Created by Alex Hagiopol on 8/6/17.
//

#pragma once
#include "problem_08_01_tripleStep.h"
#include "problem_08_02_robotGrid.h"
#include "problem_08_03_magicIndex.h"
#include "problem_08_04_powerSet.cpp"
#include "problem_08_05_recursiveMultiply.cpp"
#include "problem_08_10_paintFill.cpp"

namespace chapter_08{
    void createPowerSet(std::vector<int> set, std::vector<std::vector<int>>& powerSet);  // problem 08-04
    int recursiveMultiply(int a, int b);  // problem 08-05
    void paintFill(Eigen::MatrixXi& image, Eigen::Vector2i location, uint8_t targetColor);  // problem 08-10
}