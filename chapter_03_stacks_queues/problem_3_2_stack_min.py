from . import Stack as s


class StackMin(s.Stack):
    def __init__(self):
        super().__init__()
        self.min_stack = [float('inf')]

    def push(self, value):
        super().push(value)
        if value < self.min_stack[-1]:
            self.min_stack.append(value)

    def pop(self):
        value = super().pop()
        if value == self.min_stack[-1]:
            self.min_stack.pop()

    def see_min(self):
        if len(self.min_stack) != 1:
            return self.min_stack[-1]
        else:
            return None
