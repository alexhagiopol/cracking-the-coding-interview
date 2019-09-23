/*
PROBLEM:
Imagine a histogram (bar graph). Design an algorithm to compute the volume of water
it could hold if someone poured water across the top. You can assume that each histogram
bar has width 1.

ALGORITHM:
heights     [0,1,0,2,1,0,1,3,2,1,2,1]
maxFromLeft [0,1,1,2,2,2,2,3,3,3,3,3]
maxFromRight[3,3,3,3,3,3,3,3,2,2,2,1]

We observe that the accumulated water at position X is equal to min(max_to_left, max_to_right) - height(X)

TIME COMPLEXITY: O(N)
SPACE COMPLEXITY: O(N)
*/

#pragma once

#include <algorithm>
#include <vector>

namespace chapter_17 {
    template <typename T>
    T histogramVolume(const std::vector<T>& histogram) {
        std::vector<int> maxHeightsToLeft(histogram.size(), 0);
        std::vector<int> maxHeightsToRight(histogram.size(), 0);
        int maxHeightToLeft = 0;
        int maxHeightToRight = 0;
        int totalAccumulation = 0;
        // compute maxFromLeft for each position
        for (int i = 0; i < histogram.size(); i++) {
            if (histogram[i] > maxHeightToLeft) maxHeightToLeft = histogram[i];
            maxHeightsToLeft[i] = maxHeightToLeft;
        }
        // compute maxFromRight for each position
        for (int i = histogram.size() - 1; i >= 0; i--) {
            if (histogram[i] > maxHeightToRight) maxHeightToRight = histogram[i];
            maxHeightsToRight[i] = maxHeightToRight;
        }
        // compute water accumulation at each position
        for (int i = 0; i < histogram.size(); i++) {
            totalAccumulation += (std::min(maxHeightsToLeft[i], maxHeightsToRight[i]) - histogram[i]);
        }
        return totalAccumulation;
    }
}