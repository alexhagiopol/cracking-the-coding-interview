/*
 * PROBLEM:
 * Implement matrix - kernel convolution as for image processing as explained here:
 * https://docs.gimp.org/2.8/en/plug-in-convmatrix.html
 */
#pragma once
#include <Eigen/Dense>
#include <memory>

namespace misc {
    std::shared_ptr<Eigen::MatrixXd> kernelConvolution(const Eigen::MatrixXd& image, const Eigen::MatrixXd& kernel);
}
