/*
 * PROBLEM:
 * Implement integral image computation as explained here:
 * https://en.wikipedia.org/wiki/Summed-area_table
 */

#pragma once
#include <Eigen/Dense>
#include <memory>

namespace misc{
    std::shared_ptr<Eigen::MatrixXd> makeIntegralImage(const Eigen::MatrixXd& input);
}
