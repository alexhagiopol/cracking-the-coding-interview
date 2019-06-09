/*
Note from textbook:

Regardless of whether or not you use memoization, note that the
number of ways will quickly overflow the bounds of an integer.
By the time you get to just n = 37, the result has already overflowed.
Using a long will delay, but not completely solve, this issue.
*/

#include "problem_08_01_tripleStep.h"

namespace chapter_08{
    int tripleStep(int n, std::vector<long> memo){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        if(n == 3){
            return 4;
        }
        if(memo[n] == 0){
            memo[n] = tripleStep(n - 3, memo) + tripleStep(n - 2, memo) + tripleStep(n - 1, memo);
        }
        return memo[n];
    }

    int tripleStep(int n){
        std::vector<long> memo(n + 1, 0);
        return tripleStep(n, memo);
    }
}