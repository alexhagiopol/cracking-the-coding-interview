//
// Created by alex on 7/31/17.
//

#pragma once
#include "problem_01_01_isUnique.cpp"
#include "problem_01_02_isPermutation.cpp"
#include "problem_01_07_rotate.cpp"

namespace chapter_01{
    bool isUnique(const std::string& input);  // problem 01-01
    bool isPermutation(const std::string& s1, const std::string& s2);  // problem 01-02
    void rotate(Eigen::MatrixXi& matrix);  // problem 01-07
}

