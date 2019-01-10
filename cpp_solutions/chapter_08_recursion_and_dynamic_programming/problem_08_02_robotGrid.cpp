#include "problem_08_02_robotGrid.h"
#include <unordered_map>
#include <iostream>

namespace chapter_08{
    int linearIndex(Eigen::Vector2d coords, int cols){
        if (coords[0] >= 0 && coords[1] >= 0){
            return coords[0] * cols + coords[1];
        }
        return -1;
    }

    void printPath(std::vector<Eigen::Vector2d>& path){
        std::cout << "printing path" << std::endl;
        for (Eigen::Vector2d vector : path){
            std::cout << vector[0] << " " << vector[1];
        }
        std::cout << std::endl;
    }

    bool getPath(const Eigen::MatrixXd& maze, std::vector<Eigen::Vector2d>& path,
                 Eigen::Vector2d start, Eigen::Vector2d end,
                 std::unordered_map<int, bool> visited){
        if (start == end){
            path.push_back(end);
            return true;
        }
        if (visited.count(linearIndex(end, maze.rows())) || end[0] < 0 || end[0] >= maze.rows() || end[1] < 0 || end[1] >= maze.cols() || !maze(end[0], end[1])){
            return false;
        }
        if (getPath(maze, path, start, Eigen::Vector2d(end[0] - 1, end[1]), visited) || getPath(maze, path, start, Eigen::Vector2d(end[0], end[1] - 1), visited)){
            path.push_back(end);
            return true;
        }
        visited[linearIndex(end, maze.cols())] = true;
        return false;
    }

    bool robotGrid(const Eigen::MatrixXd& maze, std::vector<Eigen::Vector2d>& path){
        assert(maze.rows() == maze.cols());
        Eigen::Vector2d start(0, 0);
        Eigen::Vector2d end(maze.rows() - 1, maze.cols() - 1);
        std::unordered_map<int, bool> visited;
        return getPath(maze, path, start, end, visited);
    }
}