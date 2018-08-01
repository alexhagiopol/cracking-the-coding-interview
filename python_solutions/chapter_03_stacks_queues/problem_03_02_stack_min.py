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
            if value == self.min_stack.peek():
                self.min_stack.pop()

    def see_min(self):
        return self.min_stack.peek()
        
