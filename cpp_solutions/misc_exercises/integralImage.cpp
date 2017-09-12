#include "integralImage.h"
#include <iostream>

namespace misc{
    Eigen::MatrixXd makeIntegralImage(const Eigen::MatrixXd& input){
        Eigen::MatrixXd output(input.rows(), input.cols());
        output << Eigen::MatrixXd::Zero(input.rows(), input.cols());
        for (int r = 0; r < input.rows(); r++){
            for (int c = 0; c < input.cols(); c++){
                if (r == 0 && c == 0){
                    output(r, c) = input(r, c);
                } else if (r == 0) {
                    output(r, c) = input(r, c) + output(r, c - 1);
                } else if (c == 0){
                    output(r, c) = input(r, c) + output(r - 1, c);
                } else {
                    output(r, c) = input(r, c) + output(r, c - 1) + output(r - 1, c) - output(r - 1, c - 1);
                }
            }
        }
        return output;
    }

    Eigen::MatrixXd boxFilter(const Eigen::MatrixXd& input, int k){
        Eigen::MatrixXd output = Eigen::MatrixXd::Zero(input.rows(), input.cols());
        return output;
    }
}
