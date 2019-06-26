#pragma once
#include <algorithm>

namespace chapter_10 {
    template <typename T>
    int partition(std::vector<T>& array, int start, int end) {
        T partitionValue = array[end];
        int partitionIndex = start;
        // perform parition operation:
        // swap element to lowest index with unknown partition assignment
        for (int i = start; i <= end; i++) {
            if (array[i] <= partitionValue) {
                std::swap(array[i], array[partitionIndex]);
                partitionIndex ++;
            }
        }
        return partitionIndex - 1;  // - 1 to undo the increment operation after the final swap of the partitionValue
    }

    template <typename T>
    void quickSortHelper(std::vector<T>& array, int start, int end) {
        if (start < end) {
            int partitionIndex = partition(array, start, end);
            quickSortHelper(array, start, partitionIndex - 1);
            quickSortHelper(array, partitionIndex + 1, end);
        }
    }

    template <typename T>
    void quickSort(std::vector<T>& array) {
        quickSortHelper(array, 0, array.size() - 1);
    }
}
