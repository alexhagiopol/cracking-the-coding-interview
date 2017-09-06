#include "problem_08_05_recursiveMultiply.h"
#include <algorithm>

namespace chapter_08{
    int recursiveMultiplyHelper(int a, int b){
        if(b == 1){
            return a;
        } else if (b <= 0){
            return 0;
        }
        int half_b = b >> 1;
        if(b > (half_b + half_b)){  // odd b. a 1 was removed during truncation
            return a + recursiveMultiplyHelper(a << 1, half_b);  // odd case
        } else {
            return recursiveMultiplyHelper(a << 1, half_b);  // even case
        }
    }

    int recursiveMultiply(int a, int b){
        int A = std::max(a, b);
        int B = std::min(a, b);
        return recursiveMultiplyHelper(A, B);
    }
}

