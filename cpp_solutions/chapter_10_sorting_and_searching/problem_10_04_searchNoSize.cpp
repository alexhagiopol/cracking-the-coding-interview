#include "problem_10_04_searchNoSize.h"
#include <cmath>
#include <limits>

namespace chapter_10 {
    int searchNoSizeHelper(const Listy& array, const int& value, int start, int end) {
        if (start > end) return -1;
        int midpoint = (end - start) / 2 + start;
        if (array.elementAt(midpoint) == value){
            return midpoint;
        }
        else if (start == end) {
            return -1;
        }
        int leftRecursionMidpointValue = array.elementAt(midpoint -1);
        if (leftRecursionMidpointValue == -1) leftRecursionMidpointValue = std::numeric_limits<int>::max();
        if (array.elementAt(start) <= value && value <= leftRecursionMidpointValue) {
            return searchNoSizeHelper(array, value, start, midpoint - 1);
        }
        else {
            return searchNoSizeHelper(array, value, midpoint + 1, end);
        }
    }

    int computeIndex(int exponent) { return static_cast<int>(std::pow(2, exponent) - 1); }

    int computeEndpoint(const Listy& array) {
        if (array.elementAt(0) == -1) return -1;  //  handle empty array
        int exponent = 0;
        int index = computeIndex(exponent);
        while (array.elementAt(index) != -1) {
            exponent ++;
            index = computeIndex(exponent);
        }
        return index;
    }

    int searchNoSize(const Listy& array, int value) {
        int end = computeEndpoint(array);
        if (end == -1) return -1;
        return searchNoSizeHelper(array, value, 0, end);
    }
}
