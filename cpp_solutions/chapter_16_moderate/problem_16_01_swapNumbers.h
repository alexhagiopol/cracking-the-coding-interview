/*
 * Write a function to swap a number in place (that is, without temporary variables) .
 */

#pragma once

namespace chapter_16 {
    template <typename T>
    void swapNumbers(T& a, T& b) {
        static_assert(std::is_arithmetic<T>::value, "T must be an arithmetic type");
        // ex: a=5 b=9
        a = a + b;  // 5 + 9 = 14
        b = a - b;  // 14 - 9 = 5
        a = a - b;  // 14 - 5 = 9
        // ex: a=9 b=5
    }
}