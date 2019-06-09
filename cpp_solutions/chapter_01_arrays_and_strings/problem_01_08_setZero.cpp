/*
Chapter 01 - Problem 08 - Set Zero - CTCI 6th Edition page 91

Problem Statement:
Write an algorithm such that if an element in an MxN matrix is 0, its entire
row and column are set to 0.

Example:
[1, 2, 0, 4,      [0, 0, 0, 0,
 1, 2, 3, 4,  ->   0, 2, 0, 4,
 0, 2, 3, 4]       0, 0, 0, 0]

Solution:
We will implement this with allocating constant additional space. Use two boolean
variables firstZeroRow and firstZeroCol that indicate whether the first row and column
must be zeroed out. Search the first row and column for zeros to determine the value of
these boolean values. Next, use the first row as storage to note which columns must be zeroed.
Use the first column as storage to determine which rows must be zeroed. In Gayle's words
"iterate through the rest of the matrix, setting matrix[i][0] and matrix[0][j] to zero
whenever there's a zero in matrix[i][j]." Finally, iterate through the first row and column
to zero out the rows and columns indicated.

Time complexity: O(MxN).
Space complexity: O(1).
*/
#include "problem_01_08_setZero.h"
#include <iostream>
void chapter_01::setZero(Eigen::MatrixXi& m){
    int R = m.rows();
    int C = m.cols();
    // determine if first row and column contain zeros
    bool firstZeroRow = false;
    bool firstZeroCol = false;
    for (int r = 0; r < R; r++){
        if (m(r,0) == 0){
            firstZeroCol = true;
            break;
        }
    }
    for (int c = 0; c < C; c++){
        if (m(0,c) == 0){
            firstZeroRow = true;
            break;
        }
    }
    // check the rest of the matrix for zeros and use first row and col to
    // store this information
    for (int c = 1; c < C; c++){
        for (int r = 1; r < R; r++){
            if (m(r, c) == 0){
                m(0, c) = 0;
                m(r, 0) = 0;
            }
        }
    }
    // look at storage and apply zeros to appropriate rows and columns
    for (int r = 1; r < R; r++){
        if (m(r,0) == 0){
            m.row(r) *= 0;
        }
    }
    for (int c = 1; c < C; c++){
        if (m(0,c) == 0){
            m.col(c) *= 0;
        }
    }
    // look at first row and first col booleans to zero out first row and col
    if (firstZeroRow){
        m.row(0) *= 0;
    }
    if (firstZeroCol){
        m.col(0) *= 0;
    }
}
