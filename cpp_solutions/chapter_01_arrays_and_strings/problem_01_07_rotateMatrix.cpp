/*
Chapter 01 - Problem 07 - Rotate Matrix - CTCI 6th Edition page 91

Problem Statement:
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?

Example:
[1,2,3,       [7,4,1,
4,5,6,   ->   8,5,2,
7,8,9]        9,6,3]

Solution:
We rotate one matrix cell at a time in a counter clockwise pattern to achieve a clockwise rotation.
In Gayle's words: "We perform such a swap on each layer, starting from the outermost layer and working our way
inwards. (Alternatively, we could start from the inner layer and work outwards.)"

Time complexity: O(N^2). One operation per pixel in the image.
Space complexity: O(1). We only need to allocate enough space for one matrix cell.
*/

#include "problem_01_07_rotateMatrix.h"


void chapter_01::rotate(Eigen::MatrixXi& matrix){
    // assume clockwise rotation
    assert(matrix.rows() == matrix.cols());
    int N = matrix.rows();
    for (int l = 0; l < N / 2; l ++){
        for (int i = l; i < N - l - 1; i ++){
            // right column cache
            int rightColCache = matrix(i, N - l - 1);
            // right column = top row
            matrix(i, N - l - 1) = matrix(l, i);
            // top row = left column
            matrix(l, i) = matrix(N - 1 - i, l);
            // left column = bottom row
            matrix(N - 1 - i, l) = matrix(N - 1 - l, N - 1 - i);
            // bottom row = right column
            matrix(N - 1 - l, N - 1 - i) = rightColCache;
        }
    }
}
