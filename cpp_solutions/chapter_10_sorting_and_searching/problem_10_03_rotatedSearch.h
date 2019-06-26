/*
 * PROBLEM:
 * Given a sorted array that has been rotated by an unknown offset, write code to find
 * an element in the array. Assume the array was originally sorted in increasing order.
 *
 * TEST CASE:
 * search({1.5, 1.6, 1.7, 1.1, 1.2, 1.3, 1.4}, 1.6) -> 1
 *
 * ALGORITHM:
 * 0. Observe that an invariant in this problem is that in such an array, there is one adjacent pair of elements that are
 * the sorted first element and sorted last element. Thus, if the array is divided in half, one or both halves must be
 * correctly sorted.
 * 1. If the array is of size 1 or 0, handle the terminating condition.
 * 2. Recursively divide the input array in half.
 * 3. For each half...
 *  a. If the beginning and end elements are in numerical order...
 *      i. Call binarySearch to find the element.
 *  b. If the beginning and end elements are *not* in numerical order...
 *      i. Recurse on the halves of the array.
 *
 * TIME COMPLEXITY: O(log(N)) in average case. O(N) in worst case.
 *
 * SPACE COMPLEXITY: O(1)
 *
 * CODE:
 */


#pragma once
#include "binarySearch.h"

namespace chapter_10 {
    template <typename T>
    int rotatedSearchHelper(const std::vector<T>& array, const T& value, int start, int end) {
        if (start > end) return -1;  // terminating condition: asked to search empty list
        int midpoint = (end - start) / 2 + start;
        if (value == array[midpoint]) {  // terminating condition: found query
            return midpoint;
        }
        else if (start == end) { // terminating condition: asked to search single element list which is not query
            return -1;
        }

        if (array[start] <= array[end] && value >= array[start] && value <= array[end]) {  // this is a normally sorted array - use binary searc
            return binarySearchHelper(array, value, start, end);
        }
        else {  // this array was rotated, recurse on its halves
            if (array[start] <= array[midpoint - 1] && value >= array[start] && value <= array[midpoint - 1]) {  // left half is sorted and may contain value
                return binarySearchHelper(array, value, start, midpoint - 1);
            }
            if (array[midpoint + 1] <= array[end] && value >= array[midpoint + 1] && value <= array[end]) {  // right half is sorted and may contain value
                return binarySearchHelper(array, value, midpoint + 1, end);
            }
            // neither sorted half may contain the value. recurse on rotated halves
            int left_result = rotatedSearchHelper(array, value, start, midpoint - 1);
            if (left_result != -1) return left_result;
            int right_result = rotatedSearchHelper(array, value, midpoint + 1, end);
            if (right_result != -1) return right_result;
        }
        return -1;
    }

    template <typename T>
    int rotatedSearch(const std::vector<T>& array, const T& value) {
        return rotatedSearchHelper(array, value, 0, array.size() - 1);
    }
}
