#include "problem_05_01_insertion.h"

namespace chapter_05{
    int insertion(int N, int M, int i, int j){
        /*
        example input: N = 10000000000, M = 10011, i = 2, j = 6
        example output:    10001001100
        */
        int right_mask = (1 << i) - 1;  // produces 0...011
        int left_mask = -1 << (j + 1);  // produces 1...1000000
        int M_shifted = M << i;
        int full_mask = right_mask | left_mask;  // produces 1111...000000...1111
        int N_cleared = N & full_mask;  // replace part of N with zeros according to mask
        return N_cleared | M_shifted;
    }
}


