/*
Chapter 04 - Problem 04 - Check Balanced

Problem Statement:
Implement a function to check if a binary tree is balanced.
For the purposes of this question, a balanced tree is defined to be a tree
such that the heights of the two subtrees of any node never differ by more than one.

Solution:
Implement a solution in which a recursive checkBalanced() function is called on
every node. At each recursive call, the function returns (1) the number of child nodes beneath
it and (2) boolean if the numbers returned by its left and right children differ by more than 1. The recursive
terminating condition is a node which does not have any children: in this case the node returns 0 and true.

Time complexity: O(N)
Space complexity: O(H) where H is the height of the tree
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    struct NodeStatus {
        bool balanced;
        int subtreeSize;
    };

    template <typename T>
    NodeStatus checkBalanced(chapter_02::BinaryNode<T>* head) {
        NodeStatus status;
        // terminating condition
        if (head == nullptr) {
            status.balanced = true;
            status.subtreeSize = 0;
            return status;
        }

        // recursive calls
        NodeStatus leftStatus = checkBalanced(head->getLeft());
        NodeStatus rightStatus = checkBalanced(head->getRight());

        // check for imbalance in left and right children
        if (std::abs(leftStatus.subtreeSize - rightStatus.subtreeSize) > 1) {
            status.balanced = false;
        } else {
            status.balanced = true;
        }

        // check for imbalance in subtrees
        status.balanced = status.balanced && leftStatus.balanced && rightStatus.balanced;
        status.subtreeSize = std::max(leftStatus.subtreeSize, rightStatus.subtreeSize) + 1;
        return status;
    }
}  // namespace chapter_04
