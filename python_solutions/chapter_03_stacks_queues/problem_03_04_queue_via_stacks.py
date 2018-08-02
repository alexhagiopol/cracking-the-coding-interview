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
