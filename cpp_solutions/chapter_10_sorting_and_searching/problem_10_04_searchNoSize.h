/*
 * PROBLEM:
 * You are given an array-like data structure Listy which lacks a size method.
 * It does, however, have an elementAt (i) method that returns the element at
 * index i in 0(1) time. If i is beyond the bounds of the data structure, it
 * returns - 1. (For this reason, the data structure only supports positive integers.)
 * Given a Listy which contains sorted, positive integers, find the index at which an
 * element x occurs. If x occurs multiple times, you may return any index.
 *
 * TEST CASE:
 * Same as for vanilla search:
 * searchNoSize({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 3) -> 3
 *
 * ALGORITHM:
 * We need to find an upper bound for the size of the array. One way to do this is to try
 * elementAt() on indices increasing in a linear pattern e.g. 1,2,3,4,... This is a linear
 * time procedure which is no worse than just brute force linear searching the array.
 *
 * To find the upper bounds of the array in O(log(N)) time, we try elementAt() on indices increasing
 * in an exponential pattern e.g 2^0, 2^1, 2^2, 2^3, 2^4 until elementAt() returns -1.
 *
 * We have to account for "-1" values in the binary search by considering -1 to be greater
 * than any possible query value. This issue affects only the midpoint values that are used
 * to determine which side of the array to recurse on.
 *
 * TIME COMPLEXITY: O(log(N))
 *
 * SPACE COMPLEXITY: O(1)
 */

#pragma once
#include <vector>

namespace chapter_10 {
    // implement "Listy" as described in problem description
    // by removing size() from std::vector
    // and adding elementAt()
    // and supporting only ints
    class Listy : public std::vector<int> {
    private:
        using std::vector<int>::size;  // do not allow size computation as specified in problem description
        using std::vector<int>::operator[];  // do not allow operator[]; force user to use elementAt()
    public:
        Listy(std::initializer_list<int> il) : std::vector<int>(il){}  // inherit initializer list constructor
        int elementAt(int i) const { return (i >= 0 && i < this->size()) ? (*this)[i] : -1; }
    };
    int searchNoSize(const Listy& array, int value);
}
