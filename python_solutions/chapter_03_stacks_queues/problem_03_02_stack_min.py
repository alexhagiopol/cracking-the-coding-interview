"""
Chapter 03 - Problem 02 - Stack Min

Problem Statement:
Implement a stack which, in addition to push and pop, has a function min
which returns the minimum element. Push, pop and min should all operate in 0(1) time.

Solution:
StackMin will be a derived class of Stack that - along with implementing the normal
stack data structure - will keep a second stack of minimum values. When a value is pushed to
the stack that is less than the value at the top of the min stack, both the min stack and
the main stack are pushed upon. When a stack value is popped off that equals the value
at the top of the min stack, both the min stack and the main stack are popped. The best
case space complexity is O(1) for the min stack and O(N) for the main stack. This is the
case in which we have N of the same large numbers and 1 small number. The worst case space
complexity is O(N) for the min stack and O(N) for the main stack. This is the case in which
N numbers are pushed onto the stack in monotonically descending order.

Time complexity: O(1)
Space complexity: O(2N)
"""
from . import Stack as s


class StackMin(s.Stack):
    def __init__(self):
        super().__init__()
        self.min_stack = s.Stack()

    def push(self, value):
        super().push(value)
        if self.min_stack.is_empty() or value < self.min_stack.peek():
            self.min_stack.push(value)

    def pop(self):
        if not super().is_empty():
            value = super().pop()
            if value <= self.min_stack.peek():
                self.min_stack.pop()

    def see_min(self):
        return self.min_stack.peek()
        
