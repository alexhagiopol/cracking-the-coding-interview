#include "problem_16_19_pondSizes.h"
#include <iostream>

namespace chapter_16 {
    int dfsHelper(std::vector<std::vector<int>>& plot, const int r, const int c, const int rows, const int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || plot[r][c] != 0) return 0;  //  out of bounds check
        plot[r][c] = -1;
        int count = 1;
        for (int newR = r - 1; newR <= r + 1; newR++) {
            for (int newC = c - 1; newC <= c + 1; newC++) {
                count += dfsHelper(plot, newR, newC, rows, cols);
            }
        }
        return count;
    }

    std::multiset<int> pondSizes(std::vector<std::vector<int>> plot) {
        const int rows = plot.size();
        if (rows < 1) return {};  // check for empty plot
        const int cols = plot[0].size();
        std::multiset<int> result = {};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (plot[r][c] == 0) {
                    // spawn a DFS and add counter to multiset
                    int pondSize = dfsHelper(plot, r, c, rows, cols);
                    result.insert(pondSize);
                }
            }
        }
        return result;
    }
}
