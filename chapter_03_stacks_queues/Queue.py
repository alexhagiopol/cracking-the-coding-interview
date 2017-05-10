class Node:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node


class Queue:
    def __init__(self):
        self.first = None
        self.last = None

    def add(self, value):
        new = Node(value, None)
        if self.is_empty():
            self.first = new
            self.last = self.first
        else:
            self.last.next_node = new
            self.last = self.last.next_node

    def remove(self):
        if self.first is None:
            return self.first
        to_be_returned = self.first
        self.first = self.first.next_node
        return to_be_returned

    def is_empty(self):
        return self.first is None
