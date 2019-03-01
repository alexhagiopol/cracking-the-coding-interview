"""
Chapter 03 - Problem 05 - Sort Stack

Problem Statement:
Write a program to sort a stack such that the smallest items are on the top. You can use an
additional temporary stack, but you may not copy the elements into any other data structure
(such as an array). The stack supports the following operations: push(), pop(), peek(), and isEmpty().

Solution:
We sort a stack with N items by using an additional stack of up to size N and a single
temporary variable of size 1. We start with a full "left" stack and an empty "right"
stack. We first (1) pop every item off of the left stack and push each item onto the right
stack. During step (1), we fill the temporary variable with the smallest item seen so far.
In step (2), we pop every item off of the right stack back onto the left stack. However, when we encounter
the smallest item, we do *not* pop it back onto the left stack and instead just keep track of it with
the temporary variable. Once the right stack is empty, we pop the smallest item into the right stack
thus establishing the "first" item of the new, sorted stack. We then (3) repeat steps (1) and (2) while ignoring
the already sorted items in the right stack.

Time complexity: O(N)
Space complexity: O(N)
"""

from . import Stack as s


def sort_stack(stack):
    temp = s.Stack()
    smallest = None
    stack_size = stack.size
    for i in range(stack_size):
        for j in range(stack_size - i, 0, -1):
            current = stack.pop()
            if smallest is None:
                smallest = current
            else:
                if current < smallest:
                    temp.push(smallest)
                    smallest = current
                else:
                    temp.push(current)
        stack.push(smallest)
        smallest = None
        while not temp.is_empty():
            stack.push(temp.pop())
