#include "problem_16_17_contiguousSequence.h"
#include <limits>

namespace chapter_16 {
    int contiguousSequence(const std::vector<int>& input) {
        if (input.size() < 1) return 0;
        int maxSum = std::numeric_limits<int>::min();
        int sum = 0;
        for (auto num : input) {
            sum += num;
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        return maxSum;
    }
}
