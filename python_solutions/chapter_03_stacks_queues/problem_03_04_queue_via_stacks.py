"""
Chapter 03 - Problem 04 - Queue Via Stacks

 Problem Statement:
 Implement a class which implements a queue using two stacks.

 Solution:
 A queue has two operations: enqueue() and dequeue(). The general idea is to always enqueue by
 pushing items onto stack 1. When dequeue() is called we check if stack 2 is empty. If stack 2 is
 not empty, we pop off of stack 2 to return the item expected for dequeue(). If stack 2 is empty,
 we pop every item off of stack 1 and push it onto stack 2. Thus, stack 1 contains the items in
 LIFO order while stack 2 contains the items in FIFO order. If we push into stack 1 and pop off
 of stack 2, we will implement a queue.

 Time complexity: O(1) for enqueue(). O(1) amortized for dequeue().
 Space complexity: O(N) - we only store each item once.
"""

from . import Stack as s


class QueueViaStacks:
    def __init__(self):
        self.s1 = s.Stack()
        self.s2 = s.Stack()

    def enqueue(self, value):
        self.s1.push(value)

    def dequeue(self):
        if self.s2.is_empty():
            while not self.s1.is_empty():
                self.s2.push(self.s1.pop())
        return self.s2.pop()
