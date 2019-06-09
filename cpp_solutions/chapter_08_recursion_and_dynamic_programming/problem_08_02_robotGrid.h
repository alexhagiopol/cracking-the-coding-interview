#pragma once
#include <Eigen/Dense>
#include <vector>

namespace chapter_08{
    bool robotGrid(const Eigen::MatrixXd& maze, std::vector<Eigen::Vector2d>& path);
}
