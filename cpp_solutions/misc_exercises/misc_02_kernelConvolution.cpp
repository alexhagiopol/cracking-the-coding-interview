#include "misc_02_kernelConvolution.h"

namespace misc {
    std::shared_ptr<Eigen::MatrixXd> kernelConvolution(const Eigen::MatrixXd& image, const Eigen::MatrixXd& kernel){
        std::shared_ptr<Eigen::MatrixXd> output = std::shared_ptr<Eigen::MatrixXd>(new Eigen::MatrixXd(image));
        // support only odd width square kernels
        if (kernel.rows() != kernel.cols() || kernel.rows() % 2 != 1) {
            return output;
        }
        // perform convolution computation
        const int kernelHalfWidth = kernel.rows() / 2;
        for (int imageR = 0; imageR < image.rows(); imageR ++) {
            for (int imageC = 0; imageC < image.cols(); imageC++) {
                const int startR = imageR - kernelHalfWidth;
                const int startC = imageC - kernelHalfWidth;
                double accumulator = 0.0f;
                for (int kernelR = 0; kernelR < kernel.rows(); kernelR ++) {
                    for (int kernelC = 0; kernelC < kernel.cols(); kernelC ++) {
                        const int accumulatorR = startR + kernelR;
                        const int accumulatorC = startC + kernelC;
                        // check bounds conditions - implicitly this means image is zero padded
                        if (accumulatorR >= 0 && accumulatorR < image.rows() && accumulatorC >= 0 && accumulatorC < image.cols()) {
                            accumulator += image(accumulatorR, accumulatorC) * kernel(kernelR, kernelC);
                        }
                    }
                }
                (*output)(imageR, imageC) = accumulator;
            }
        }
        return output;
    }
}
