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

Time complexity: O(N)
Space complexity: O(N)
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    template <typename T>
    chapter_02::BinaryNode<T>* minimalTreeHelper(const std::vector<T>& array, int start, int end, chapter_02::BinaryNode<T>* head ) {
        if (end < start) {  // if end is less than start, do not add new node to tree
            return nullptr;
        }
        int center = start + static_cast<int>((end - start) / 2);  // center position is offset by start position
        chapter_02::BinaryNode<T>* newHead = new chapter_02::BinaryNode<T>(array[center]);
        if (end > start) {  // if end equals start, add a new node but no children
            // if end > start, test the children as well
            newHead->setLeft(minimalTreeHelper( array,      start, center - 1, newHead));
            newHead->setRight(minimalTreeHelper(array, center + 1,        end, newHead));
        }
        return newHead;
    }
    template <typename T>
    chapter_02::BinaryNode<T>* minimalTree(const std::vector<T>& array) {
        if (array.size() <= 0) {
            return nullptr;
        }
        int start = 0;
        int end = static_cast<int>(array.size()) - 1;
        int center = (end - start) / 2;
        chapter_02::BinaryNode<T>* head = new chapter_02::BinaryNode<T>(array[center]);
        if (start != end) {
            head->setLeft(minimalTreeHelper( array,      start, center - 1, head));
            head->setRight(minimalTreeHelper(array, center + 1,        end, head));
        }
        return head;
    }
} // namespace chapter_04
