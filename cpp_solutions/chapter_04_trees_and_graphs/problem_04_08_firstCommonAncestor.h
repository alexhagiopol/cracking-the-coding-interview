/*
Chapter 04 - Problem 08 - First Common Ancestor

Problem Statement:
Design an algorithm and write code to find the first common ancestor of two nodes in a binary tree.
Avoid storing additional nodes in a data structure. Assume that this tree is not necessarily a binary search tree.
Assume that nodes in the tree do not have links to their parents.

Solution:
Traverse the tree recursively using a function whose return value indicates the presence of nodes 1 and 2
in the current node's left or right subtrees. The function also passes a reference to a Null node that is changed
to the identity of the first common ancestor if such a node exists. At each recursive call, the function returns one of
the following: "1" if the current node is an ancestor of node1, "2" if the current node is an ancestor of node2,
"3" if the current node is an ancestor of both nodes 1 and 2 or "0" in case the current node is an ancestor
of neither nodes 1 or 2. The function recurses until nodes1 and 2 are found and their presence is "bubbled up"
the tree in the form of the return values. If case "3" is encountered and the reference is still Null, the
reference is assigned the current node which by definition is the first common ancestor.
The terminating condition of the function is finding node1, node2, or Null.

Time complexity: O(N)
Space complexity: O(log(N)) if tree is balanced
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    template <typename T>
    int firstCommonAncestorHelper(chapter_02::BinaryNode<T>* currentNode,
                                  chapter_02::BinaryNode<T>* node1,
                                  chapter_02::BinaryNode<T>* node2,
                                  chapter_02::BinaryNode<T>*& fca) {
        if (currentNode == nullptr) return 0;
        if (currentNode == node1) return 1;
        if (currentNode == node2) return 2;
        int returnLeft = firstCommonAncestorHelper(currentNode->getLeft(), node1, node2, fca);
        int returnRight = firstCommonAncestorHelper(currentNode->getRight(), node1, node2, fca);
        int sum = returnLeft + returnRight;
        if (sum == 3 && fca == nullptr) fca = currentNode;
        return sum;
    }

    template <typename T>
    chapter_02::BinaryNode<T>* firstCommonAncestor(chapter_02::BinaryNode<T>* head,
                                                   chapter_02::BinaryNode<T>* node1,
                                                   chapter_02::BinaryNode<T>* node2) {
        chapter_02::BinaryNode<T>* fca = nullptr;
        firstCommonAncestorHelper(head, node1, node2, fca);
        return fca;
    }
}  // chapter_04