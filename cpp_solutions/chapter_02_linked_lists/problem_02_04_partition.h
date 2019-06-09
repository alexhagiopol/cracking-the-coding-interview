/*
Chapter 02 - Problem 04 - Partition - CTCI 6th Edition page 94

Problem Statement:
Write code to partition a linked list around a value x, such that all nodes less than x come before all nodes greater
than or equal to x. lf x is contained within the list, the values of x only need to be after the elements less than x
(see below).The partition element x can appear anywhere in the "right partition"; it does not need to appear between
the left and right partitions.

Example:
Input:  3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

Solution:
Start a new list with a head and tail pointing to null. Traverse the nodes of the input linked list one at a time.
If the current node has value greater than or equal to the partition value, move it to the tail of the new list. Else,
move it to the the head of the new list.

Time complexity: O(N).
Space complexity: O(1) (we need no additional space in addition to the O(N) space required to store the list itself).
*/

#pragma once
#include <iostream>

namespace chapter_02{
    template <typename T>
    SinglyLinkedNode<T>* partition(SinglyLinkedNode<T>* head, T partition){
        if (head == nullptr){
            return nullptr;
        }
        SinglyLinkedNode<T>* newHead = head;
        SinglyLinkedNode<T>* newTail = head;
        head = head->getNext();
        while (head != nullptr){
            SinglyLinkedNode<T>* temp = head;
            head = head->getNext();
            if (temp->getValue() < partition){ // add node in front of new head
                temp->setNext(newHead);
                newHead = temp;
            } else { // add node behind new tail
                newTail->setNext(temp);
                newTail = temp;
                newTail->setNext(nullptr);
            }
        }
        return newHead;
    }
}
