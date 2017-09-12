#pragma once
#include <Eigen/Dense>

namespace misc{
    Eigen::MatrixXd makeIntegralImage(const Eigen::MatrixXd& input);
    Eigen::MatrixXd boxFilter(const Eigen::MatrixXd& input, int k);  // assume k x k box filter with all values = to 1
}

