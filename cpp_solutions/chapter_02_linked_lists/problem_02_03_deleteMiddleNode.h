/*
Chapter 02 - Problem 03 - Delete Middle Node - CTCI 6th Edition page 211

Problem Statement:
Implement an algorithm to delete a node in the middle (i.e., any node but the first and last
node, not necessarily the exact middle) of a singly linked list, given only access to that node.

Example:
Input: the node c from the linked list a -> b -> c -> d -> e -> f
Result: nothing is returned, but the new linked list looks like a -> b -> d -> e -> f

Solution:
The solution is best illustrated by example: given node "c", copy the contents of node "d" into node
"c". Link node "c" to node "e". Delete node "d".

Time complexity: O(1).
Space complexity: O(1).
*/

#pragma once
#include "Node.h"

namespace chapter_02{
    template <typename T>
    void deleteMiddleNode(SinglyLinkedNode<T>* middle){
        if (middle == nullptr || middle->getNext() == nullptr){
            return; // given node is not in the middle. do nothing.
        }
        SinglyLinkedNode<T>* next = middle->getNext();
        middle->setValue(next->getValue());
        middle->setNext(next->getNext());
        delete next;
    }
}
