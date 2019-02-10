/*
Chapter 04 - Problem 05 - Validate BST

Problem Statement:
Implement a function to check if a binary tree is a binary search tree (BST).

Solution:
A BST is defined as a binary tree in which every node is less than all nodes to
its right and greater than all nodes to its left. It is not enough to just check that each
node is greater or less than its parent. If the node is a right child, it must be greater than its
parent but also less than all nodes to the right of its parent. If the node is a left child, it must be less
than its parent, but also greater than all nodes to the left of its parent.

To validate a BST according to these rules, we recursively traverse the tree and check if each node's value
is between min and max values. The min and max values are initialized to +Inf and -Inf and we update the
min and max values as we traverse down the tree. For example, at the head of the tree, min=-Inf and max=+Inf thus
any head value will pass the test. For the left child of the head, min=-Inf and max=head_value while for the
right child of the head, min=head_value and max=+Inf. We repeat this pattern for all nodes and return false
if a node is not in bounds.

Time complexity: O(N)
Space complexity: O(log(N)) assuming tree is balanced
*/

#pragma once
#include <chapter_02_linked_lists/Node.h>

namespace chapter_04 {
    template <typename T>
    bool validateBST(chapter_02::BinaryNode<T>* head, T min = std::numeric_limits<T>::min(), T max = std::numeric_limits<T>::max()) {
        if (head == nullptr) return true;  // lack of a node is considered valid
        if (head->getValue() > max || head->getValue() < min) return false;
        return validateBST(head->getLeft(), min, head->getValue()) && validateBST(head->getRight(), head->getValue(), max);
    }
}  // namespace chapter_04
