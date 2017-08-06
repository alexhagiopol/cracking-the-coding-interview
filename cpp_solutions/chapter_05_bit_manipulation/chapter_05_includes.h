//
// Created by Alex Hagiopol on 8/5/17.
//

#pragma once

#include "problem_05_01_insertion.cpp"
#include "problem_05_02_binaryToString.cpp"
#include "problem_05_06_conversion.cpp"
#include "problem_05_07_pairwiseSwap.cpp"

namespace chapter_05{
    int insertion(int N, int M, int i, int j);  // problem 05-01
    int binaryToString(double fraction, std::string& binaryString);  // problem 05-02
    int conversion(int A, int B);  // problem 05-06
    int pairwiseSwap(int x);  // problem 05-07
}
