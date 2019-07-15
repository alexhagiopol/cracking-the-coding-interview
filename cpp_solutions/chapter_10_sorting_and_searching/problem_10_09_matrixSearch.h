#pragma once
#include <Eigen/Dense>

namespace chapter_10 {
    template <typename Type, int Rows, int Cols>
    std::pair<int, int> matrixSearch(const Eigen::Matrix<Type, Rows, Cols>& matrix, const Type& query) {
        std::pair<int, int> coordinates(0,0);
        return coordinates;
    }
}
