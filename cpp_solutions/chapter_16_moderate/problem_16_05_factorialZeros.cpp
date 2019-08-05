#include "problem_16_05_factorialZeros.h"

namespace chapter_16 {
    int factorialZeros(long N) {
        if (N < 0) {
            return -1;
        }
        int factorialZeros = 0;
        int multipleOf5 = 5;
        int exponentOf5 = 1;
        int exponentCount = 1;
        while (N >= multipleOf5) {
            // increment number of zeros
            factorialZeros += exponentOf5;
            // update multiple
            multipleOf5 += 5;
            // update exponent
            exponentCount += 1;
            if (exponentCount == 5) {
                exponentCount = 1;
                exponentOf5 ++;
            }
        }
        return factorialZeros;
    }
}
