#include <Eigen/Dense>

namespace chapter_08{
    std::vector<std::tuple<int, int>> robotGrid(Eigen::MatrixXd& maze){
        std::vector<std::tuple<int, int>> path;
        path.push_back(std::tuple<int, int>(0, 0));
        return path;
    }
}