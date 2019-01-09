/*
Chapter 04 - Problem 02 - Minimal Tree

Problem Statement:
Given a sorted (increasing order) array
with unique integer elements, write an algorithm
to create a binary search tree with minimal height.

Solution:
To create a minimal height BST, the input array must be traversed
according to the binary search algorithm. At each recursion of the
algorithm, we add the current array element's value to a BST node,
then divide the input array as closely to 50%/50% as possible before
recursing on each half for the left and right BST child nodes.

Time complexity: O(log(N))
Space complexity: O(log(N))
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    template <typename T>
    chapter_02::BinaryNode<T>* minimalTreeHelper(const std::vector<T>& array, size_t start, size_t end, chapter_02::BinaryNode<T>* head ) {
        std::cout << "calling mTH start=" << start << " end" << std::endl;
        if (end <= start) {
            return nullptr;
        }
        size_t center = (end - start) / 2;
        chapter_02::BinaryNode<T>* newHead = new chapter_02::BinaryNode<T>(array[center]);
        newHead->addLeft(minimalTreeHelper( array,      start, center - 1, head));
        newHead->addRight(minimalTreeHelper(array, center + 1,        end, head));
        return newHead;
    }
    template <typename T>
    chapter_02::BinaryNode<T>* minimalTree(const std::vector<T>& array) {
        if (array.size() <= 0) {
            return nullptr;
        }
        size_t start = 0;
        size_t end = array.size() - 1;
        size_t center = (end - start) / 2;
        chapter_02::BinaryNode<T>* head = new chapter_02::BinaryNode<T>(array[center]);
        if (start != end) {
            head->addLeft(minimalTreeHelper( array,      start, center - 1, head));
            head->addRight(minimalTreeHelper(array, center + 1,        end, head));
        }
        std::cout << "done!" << std::endl;
        return head;
    }

} // namespace chapter_04
