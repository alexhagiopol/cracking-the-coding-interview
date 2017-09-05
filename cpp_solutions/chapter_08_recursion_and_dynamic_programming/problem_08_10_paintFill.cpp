#include "problem_08_10_paintFill.h"
#include <tuple>

namespace chapter_08{
    void paintFill(Eigen::MatrixXi& image, Eigen::Vector2i location, uint8_t targetColor, uint8_t initColor){
        Eigen::Vector2i dimensions(image.rows(), image.cols());
        if (location(0) < 0 || location(0) >= dimensions(0) || location(1) < 0 || location(1) >= dimensions(1)) return;
        if (image(location(0), location(1)) == targetColor || image(location(0), location(1)) != initColor) return;
        image(location(0), location(1)) = targetColor;
        paintFill(image, Eigen::Vector2i(location(0) - 1, location(1)), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0) + 1, location(1)), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0), location(1) - 1), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0), location(1) + 1), targetColor, initColor);
    }

    void paintFill(Eigen::MatrixXi& image, Eigen::Vector2i location, uint8_t targetColor){
        Eigen::Vector2i dimensions(image.rows(), image.cols());
        if (location(0) < 0 || location(0) >= dimensions(0) || location(1) < 0 || location(1) >= dimensions(1)) return;
        uint8_t initColor = image(location(0), location(1));
        image(location(0), location(1)) = targetColor;
        paintFill(image, Eigen::Vector2i(location(0) - 1, location(1)), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0) + 1, location(1)), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0), location(1) - 1), targetColor, initColor);
        paintFill(image, Eigen::Vector2i(location(0), location(1) + 1), targetColor, initColor);
    }
}
