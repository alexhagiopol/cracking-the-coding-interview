//
// Created by Alex Hagiopol on 2019-02-02.
//

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