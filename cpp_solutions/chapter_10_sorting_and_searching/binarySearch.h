#pragma once

namespace chapter_10 {
    template <typename T>
    int binarySearchHelper(const std::vector<T>& array, const T& value, int start, int end) {
        if (start > end) return -1;  // terminating condition: asked to search empty list
        int midpoint = (end - start) / 2 + start;
        if (value == array[midpoint]) {  // terminating condition: found query
            return midpoint;
        }
        else if (start == end) { // terminating condition: asked to search single element list which is not query
            return -1;
        }
        else if (value < array[midpoint]) {  // recurse left
            return binarySearchHelper(array, value, start, midpoint - 1);
        }
        else  {  // recurse right
            return binarySearchHelper(array, value, midpoint + 1, end);
        }
    }

    template <typename T>
    int binarySearch(const std::vector<T>& array, const T& value) {
        return binarySearchHelper(array, value, 0, array.size() - 1);
    }
}