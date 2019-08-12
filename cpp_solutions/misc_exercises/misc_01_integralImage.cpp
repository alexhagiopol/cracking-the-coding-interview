#include "misc_01_integralImage.h"

namespace misc{
    std::shared_ptr<Eigen::MatrixXd> makeIntegralImage(const Eigen::MatrixXd& input){
        auto output = std::shared_ptr<Eigen::MatrixXd>(new Eigen::MatrixXd(input.rows(), input.cols()));
        (*output) << Eigen::MatrixXd::Zero(input.rows(), input.cols());
        for (int r = 0; r < input.rows(); r++){
            for (int c = 0; c < input.cols(); c++){
                if (r == 0 && c == 0){
                    (*output)(r, c) = input(r, c);
                } else if (r == 0) {
                    (*output)(r, c) = input(r, c) + (*output)(r, c - 1);
                } else if (c == 0){
                    (*output)(r, c) = input(r, c) + (*output)(r - 1, c);
                } else {
                    (*output)(r, c) = input(r, c) + (*output)(r, c - 1) + (*output)(r - 1, c) - (*output)(r - 1, c - 1);
                }
            }
        }
        return output;
    }
}
