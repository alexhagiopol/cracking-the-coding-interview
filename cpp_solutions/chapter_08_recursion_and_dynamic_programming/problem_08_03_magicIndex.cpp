#include "problem_08_03_magicIndex.h"

namespace chapter_08{
    int binarySearchMagicIndex(const std::vector<int>& array, int start, int end){
        int middle = (start + end) / 2;
        if(array.size() < 1 || end - start < 0){
            return -1;
        }
        if(middle == array[middle]){
            return middle;
        }
        if(array.size() == 1){
            return -1;
        }
        if (middle < array[middle]){
            return binarySearchMagicIndex(array, start, middle);
        } else {
            return binarySearchMagicIndex(array, middle + 1, end);
        }
    }

    int magicIndex(const std::vector<int>& array){
        return binarySearchMagicIndex(array, 0, array.size() -1);
    }
}
