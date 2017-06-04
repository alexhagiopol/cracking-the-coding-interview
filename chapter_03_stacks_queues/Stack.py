class Stack(object):
    def __init__(self):
        self.data = []

    def pop(self):
        if self.is_empty():
            return None
        return self.data.pop()

    def push(self, val):
        self.data += [val]

    def peek(self):
        if self.is_empty():
            return None
        return self.data[-1]

    def is_empty(self):
        return len(self.data) == 0
