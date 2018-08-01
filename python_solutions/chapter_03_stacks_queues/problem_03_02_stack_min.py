from . import Stack as s


class StackMin(s.Stack):
    def __init__(self):
        super().__init__()
        self.min_stack = s.Stack()
        self.min_stack.push(float('inf'))

    def push(self, value):
        super().push(value)
        if value < self.min_stack.peek():
            self.min_stack.push(value)

    def pop(self):
        value = super().pop()
        if value <= self.min_stack.peek():
            self.min_stack.pop()

    def see_min(self):
        if self.min_stack.size != 1:
            return self.min_stack.peek()
        else:
            return None
