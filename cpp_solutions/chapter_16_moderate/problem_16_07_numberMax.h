/*
PROBLEM:
Write a method that finds the maximum of two numbers. You should not use if-else
or any other comparison operator.

ALGORITHM:
If the numbers are integers, we can take advantage of the properties of integer division.
Dividing the smaller number by the larger number will yield 0. Example:

A = 7.5
B = 1.0
quotientA = static_cast<bool>(A / B) = 7.5 -> 7 -> 1
quotientB = static_cast<bool>(B / A) = 0.13 -> 0 -> 0

We can then return the following:

quotientA * A + quotientB * B / (quotientA + quotientB)

However, this formulation has issues where either or both A and B are zero. Thus we use a revised
formulation. First we increment both A and B by 1 to avoid division by zero. This incrementation does
not affect which number is bigger or smaller. Next we use the && operator to create a divisor that can
never be zero as shown:

(quotientA * A + quotientB * B) / ((quotientA && quotientB) + 1);

With this formula, we solve the problem with much fewer lines than the book author's solution, but we are limited to only
positive integers.

TIME:
O(1) time
SPACE:
O(1) space
*/

#pragma once
#include <cstdint>

namespace chapter_16 {
    uint16_t numberMax(uint16_t A, uint16_t B);
}
