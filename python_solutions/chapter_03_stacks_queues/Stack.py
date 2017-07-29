class Stack(object):
    def __init__(self):
        self.data = []

    def pop(self):
        if self.is_empty():
            return None
        return self.data.pop()

    def push(self, val):
        self.data.append(val)

    def peek(self):
        if self.is_empty():
            return None
        return self.data[-1]

    def is_empty(self):
        return len(self.data) == 0

    def __str__(self):
        string = ''
        for x in self.data:
            string += str(x) + ' '
        return string
