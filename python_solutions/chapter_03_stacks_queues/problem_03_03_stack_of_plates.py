from . import Stack as s


class SetOfStacks:
    def __init__(self, max_height):
        self.max_height = max_height
        self.stacks = [s.Stack()]
        self.i = 0

    def push(self, value):
        if self.stacks[self.i].size >= self.max_height:
            self.stacks.append(s.Stack())
            self.i += 1
        self.stacks[self.i].push(value)

    def pop(self):
        if self.stacks[self.i].is_empty():
            if self.i == 0:
                return None
            self.stacks.pop(self.i)
            self.i -= 1
        return self.stacks[self.i].pop()

    def pop_at(self, index):
        if self.stacks[index].is_empty():
            if index <= 0:
                return None
            self.stacks.pop(index)
            self.i -= 1
            index -= 1
        return self.stacks[index].pop()
