#include "problem_16_11_divingBoard.h"

namespace chapter_16 {
    std::unordered_set<int> divingBoard(int shorter, int longer, int K ) {
        std::unordered_set<int> lengths;
        for (int i = 0; i <= K; i++) {
            int length = i * shorter + (K - i) * longer;
            if (!lengths.count(length)) lengths.insert(length);
        }
        return lengths;
    }
}
