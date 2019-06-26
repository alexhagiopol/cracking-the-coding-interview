#pragma once
#include <vector>

namespace chapter_10 {
    template <typename T>
    void mergeHelper(std::vector<T>& array, std::vector<T>& helperArray, int start, int middle, int end) {
        assert(array.size() == helperArray.size());
        int helperIdx = start;
        int leftIdx = start;
        int rightIdx = middle + 1;
        // perform merge operation from left and right halves of input array into helper array
        // this operation stops when either the left or right subarray is depleted
        while (leftIdx <= middle && rightIdx <= end) {
            if (array[leftIdx] <= array[rightIdx]) {
                helperArray[helperIdx] = array[leftIdx];
                leftIdx ++;
            }
            else {
                helperArray[helperIdx] = array[rightIdx];
                rightIdx ++;
            }
            helperIdx ++;
        }
        // account for case where one array segment (left or right) is smaller
        // only one of these while blocks will be executed because only one side may be smaller
        while (leftIdx <= middle) {
            helperArray[helperIdx] = array[leftIdx];
            leftIdx ++;
            helperIdx ++;
        }
        while (rightIdx <= end) {
            helperArray[helperIdx] = array[rightIdx];
            rightIdx ++;
            helperIdx ++;
        }
        // copy content of helper array into input array at the appropriate indices
        array = helperArray;
    }

    template <typename T>
    void sortHelper(std::vector<T>& array, std::vector<T>& helperArray, int start, int end) {
        assert(array.size() == helperArray.size());
        // check for terminating condition and recursively sort left and right halves
        if (start < end) {
            int middle = (end - start) / 2 + start;
            if (start < middle) sortHelper(array, helperArray, start, middle);
            if ((middle + 1) < end) sortHelper(array, helperArray, middle + 1, end);
            mergeHelper(array, helperArray, start, middle, end);
        }
    }

    template <typename T>
    void mergeSort(std::vector<T>& array) {
        std::vector<T> helperArray(array);
        int start = 0;
        int end = array.size() - 1;
        sortHelper(array, helperArray, start, end);  // by definition, the end of an array range *is* included in sort
    }
}
