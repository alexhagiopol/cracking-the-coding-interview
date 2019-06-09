/*
Chapter 02 - Problem 05 - Sum Lists - CTCI 6th Edition page 95

Problem Statement:
You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function
that adds the two numbers and returns the sum as a linked list.

Example:
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: (2 -> 1 -> 9). That is, 912.

Solution:

Create a node representing the head of a new linked list. Traverse the input linked lists one node at a time until
both pointers are nullptr. Append a new node to the output linked list for every sum computed between pairs of nodes.
Add two input nodes and store the sum in the output node. If the sum is > 9, store the carry value in an int variable.
If one pointer is nullptr but the other isn't, copy the value of the non-null pointer into the new list.
Add the sum to a node in the new linked list. Return head of new linked list.

Time complexity: O(N)
Space complexity: O(N)
*/

#include "Node.h"

namespace chapter_02{
    SinglyLinkedNode<uint8_t>* sumLists(const SinglyLinkedNode<uint8_t>* head1, const SinglyLinkedNode<uint8_t>* head2){
        uint8_t carry = 0;
        SinglyLinkedNode<uint8_t>* outputRunner = nullptr;
        SinglyLinkedNode<uint8_t>* outputHead = nullptr;
        while (head1 != nullptr || head2 != nullptr){  // continue traversing so long as one pointer is not null
            if (outputRunner == nullptr){  // create head of output linked list
                outputRunner = new SinglyLinkedNode<uint8_t>(0);
                outputHead = outputRunner;
            } else {  // add new node to existing list
                SinglyLinkedNode<uint8_t>* temp = new SinglyLinkedNode<uint8_t>(0);
                outputRunner->setNext(temp);
                outputRunner = outputRunner->getNext();
            }
            uint8_t sum = 0;
            if (head1 == nullptr){  // if head1 is null, use only head2 to compute sum
                assert(head2->getValue() < 10);
                sum = head2->getValue() + carry;
                head2 = head2->getNext();
            } else if (head2 == nullptr){  // if head2 is null use only head1 to compute sum
                assert(head1->getValue() < 10);
                sum = head1->getValue() + carry;
                head1 = head1->getNext();
            } else {
                assert(head1->getValue() < 10 && head2->getValue() < 10);
                sum = head1->getValue() + head2->getValue() + carry;
                head1 = head1->getNext();
                head2 = head2->getNext();
            }
            carry = 0;
            if (sum > 9){  // if sum is too large for 1 digit, carry over to next digit
                carry = sum / 10;
                sum = sum - 10;
            }
            outputRunner->setValue(sum);
        }
        if (carry > 0) outputRunner->setNext(new SinglyLinkedNode<uint8_t>(carry));  // traversal is over but carry value still remains
        return outputHead;
    }
}

