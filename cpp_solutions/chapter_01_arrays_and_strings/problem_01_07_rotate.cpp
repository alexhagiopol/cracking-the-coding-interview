//
// Created by Alex Hagiopol on 8/24/17.
//

#include <Eigen/Dense>

namespace chapter_01{
    void rotate(Eigen::MatrixXi& matrix){
        assert(matrix.rows() == matrix.cols());
        int N = matrix.rows();
        for (int l = 0; l < N / 2; l ++){
            for (int i = l; i < N - l - 1; i ++){
                //right col cache
                int rightColCache = matrix(i, N - l - 1);
                //right col = top row
                matrix(i, N - l - 1) = matrix(l, i);
                //top row = left col
                matrix(l, i) = matrix(N - 1 - i, l);
                //left col = bottom row
                matrix(N - 1 - i, l) = matrix(N - 1 - l, N - 1 - i);
                //bottom row = right col
                matrix(N - 1 - l, N - 1 - i) = rightColCache;
            }
        }
    }
}