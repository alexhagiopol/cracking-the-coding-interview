//
// Created by Alex Hagiopol on 2/3/18.
//
/*
Chapter 02 - Problem 06 - Palindrome - CTCI 6th Edition page 95

Problem Statement:
Implement a function to check if a linked list is a palindrome.

Example:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: (2 -> 1 -> 9). That is, 912.

Solution:

A palindrome is a list that is the same forwards as it is backwards. We traverse the input list
once and count its length. We then use this count to create a new list that is the reverse of the first
half of the input list. This is done by traversing the first half of the input list a second time.
We then compare the reversed list with the second half of the input list.

Time complexity: O(N)
Space complexity: O(N)
*/
#include "LinkedListNode.h"

namespace chapter_02{
    template <typename T>
    bool palindrome(const LinkedListNode<T>* head){
        const LinkedListNode<T>* runner = head;
        int count = 0;
        while (runner != nullptr){  // traverse list forwards once
            count ++;  // count length of input list
            runner = runner->getNext();
        }
        int halfLength = count / 2;  // integer division to compute half length; odd lengths get truncated
        LinkedListNode<T>* revHead = new LinkedListNode<T>(head->getValue());
        runner = head;
        for (int i = 1; i < halfLength; i++){  // create a list that is reverse of first half of input list
            runner = runner->getNext();
            LinkedListNode<T>* temp = new LinkedListNode<T>(runner->getValue(), revHead);
            revHead = temp;
        }
        runner = runner->getNext();  // advance runner from first half to second half
        if (count % 2 != 0) runner = runner->getNext();  // if input list is odd length, advance runner once to move to latter half
        while (runner != nullptr && revHead != nullptr){  // traverse second half of input list simultaneously with reversed list
            if (runner->getValue() != revHead->getValue()) return false;
            runner = runner->getNext();
            revHead = revHead->getNext();
        }
        return true;
    }
}
