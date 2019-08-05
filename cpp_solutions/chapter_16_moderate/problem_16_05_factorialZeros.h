/*
 * PROBLEM: Write an algorithm which computes the number of trailing 0s in N!.
 *
 * TEST CASES:
 * 1! = 1        -> 0
 * 2! = 2        -> 0
 * 5! = 120      -> 1
 * 7! = 5040     -> 1
 * 10! = 3628800 -> 2
 *
 * ALGORITHM:
 * The easy solution is to compute N! then iteratively divide by 10 until
 * the division yields a fractional value. However, N! will quickly overwhelm
 * the maximum integer size on a 32 bit machine, so this solution is not practical
 * for large values of N.
 *
 * We observe that the only way to generate a trailing zero is for a
 * factorial multiplication series is for the series to contain a (5, 2) pair. Thus 5! can be represented
 * as 5 * 2 * 2 * 3 * 2 * 1 which contains 1 such pair. We observe that in a factorial operation, there will
 * always be more 2 factors than 5 factors. Thus the number of trailing zeros is equal
 * to the number of 5 factors in the factorial operation. Note that a number like 25
 * is 5^2 and thus contains two 5 factors.
 *
 * To solve, we iterate over the values [5, 10, 15, 20, 25, ... ] and stop iterating
 * when N > the current multiple of 5 value. We also keep track of the current exponent
 * of 5 [5->1, 10->1, 15->1, 20->1, 25->2, ...] during the iteration. At each iteration,
 * we add the current exponent to the count of total zeros.
 *
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

#pragma once

namespace chapter_16 {
    int factorialZeros(long N);
}