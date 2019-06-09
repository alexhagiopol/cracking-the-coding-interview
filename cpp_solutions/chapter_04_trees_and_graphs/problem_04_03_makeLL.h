/*
Chapter 04 - Problem 02 - Minimal Tree

Problem Statement:
Given a binary tree, design an algorithm which creates a linked list
of all the nodes at each depth (e.g., if you have a tree with
depth D, you'll have D linked lists).


Solution:
Represent the data structure described by the problem as a vector of
linked lists. Traverse the BST using recursive depth first search keeping
track of the depth at each recursion. For each node traversed in each
recursive call, determine the index of the vector from the depth, then
add a singly linked node to the end of the linked list at that vector index.
To keep track of the linked list tails, a second vector of tail pointers is
also implemeted.

Time complexity: O(N)
Space complexity: O(N)
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"

namespace chapter_04 {
    // utility function to test correctness of vector of linked lists
    template <typename T>
    std::vector<T> vectorFromVectorOfLLs(std::vector<chapter_02::SinglyLinkedNode<T>*>& vector) {
        std::vector<T> contents = {};
        for (int i = 0; i < vector.size(); i++) {
            chapter_02::SinglyLinkedNode<T>* node = vector[i];
            while (node != nullptr) {
                contents.push_back(node->getValue());
                node = node->getNext();
            }
        }
        return contents;
    }
    // convert BST into vector of linked lists. one linked list at every BST depth
    template <typename T>
    void makeLL(
            std::vector<chapter_02::SinglyLinkedNode<T>*>& vectorOfHeads,
            std::vector<chapter_02::SinglyLinkedNode<T>*>& vectorOfTails,
            const chapter_02::BinaryNode<T>* bstHead,
            int depth = 0) {  // we cast the problem as a vector of linked lists
        if (bstHead == nullptr) {  // terminating condition: do nothing if BST head is null
            return;
        }
        if (depth >= vectorOfHeads.size()) {  // case where head of new linked list needs to be added to vector
            auto newNode = new chapter_02::SinglyLinkedNode<T>(bstHead->getValue(), nullptr);
            vectorOfHeads.push_back(newNode);
            vectorOfTails.push_back(newNode);
        } else { // case where current node ("bstHead") needs to be appended to end of existing linked list
            chapter_02::SinglyLinkedNode<T>* depthTail = vectorOfTails[depth];
            depthTail->setNext(new chapter_02::SinglyLinkedNode<T>(bstHead->getValue(), nullptr));
            vectorOfTails[depth] = depthTail->getNext();
        }
        // recursive function calls
        makeLL(vectorOfHeads, vectorOfTails, bstHead->getLeft(), depth + 1);
        makeLL(vectorOfHeads, vectorOfTails, bstHead->getRight(), depth + 1);
    }
}  // namespace chapter_04
