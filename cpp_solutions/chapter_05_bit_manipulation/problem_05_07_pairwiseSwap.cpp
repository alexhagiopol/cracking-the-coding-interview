#include "problem_05_07_pairwiseSwap.h"

namespace chapter_05{
    int pairwiseSwap(int x){
        const int even_mask_1010 = 0b10101010101010101010101010101010;
        const int odd_mask_0101 = 0b01010101010101010101010101010101;
        return ((x & even_mask_1010) >> 1 | (x & odd_mask_0101) << 1);
    }
}