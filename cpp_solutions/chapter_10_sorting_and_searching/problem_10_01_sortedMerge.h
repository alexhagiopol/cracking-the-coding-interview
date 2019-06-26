/*
Chapter 10 - Problem 01 - Sorted Merge

Problem Statement:
You are given two sorted arrays, A and B, where A has a large enough buffer at the end to hold B.
Write a method to merge B into A in sorted order.

Solution:
First create 3 runner pointers: one to the last useful element of A, one to the last useful element of B,
and one to the very end of A. Iterate through the elements of A and B in order from back to front, and copy
the greater one to the back of A. Check the address to which the pointers point to ensure that we have not
run out of A or B elements before advancing pointers.

Time complexity: O(N)
Space complexity: O(1) // because our function uses pointers instead of array copies, we do not
allocate any memory that scales with the input size
*/

namespace chapter_10{
    template <typename T>
    void sortedMerge(T* A, int lastAindex, T* B, int lastBindex){

        // create pointer to very end of array A representing the start point of merging procedure
        int mergeIndex = lastAindex + lastBindex + 1;
        T* mergeA = A;
        while(mergeIndex > 0){
            mergeA ++;
            mergeIndex --;
        }

        // create pointer to last element of A that we want to merge
        T* lastA = A;
        while(lastAindex > 0){
            lastA ++;
            lastAindex --;
        }

        // create pointer to last element of B that we want to merge
        T* lastB = B;
        while(lastBindex > 0){
            lastB ++;
            lastBindex --;
        }

        // iterate through arrays A and B from back to front performing the merge operation along the way
        while (lastB >= B){  // note that you don't need to copy the contents of A after running out of elements of B. they are already in place.
            if (*lastA > *lastB && lastA >= A){  // do not allow copying from A if we have run out of A values
                *mergeA = *lastA;
                lastA --;
            } else {
                *mergeA = *lastB;
                lastB --;
            }
            mergeA --;
        }
    }
}
