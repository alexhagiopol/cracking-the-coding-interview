from .. chapter_02_linked_lists import SinglyLinkedNode as sln

class Queue:
    def __init__(self):
        self.first = None
        self.last = None

    def enqueue(self, value):
        new = sln.SinglyLinkedNode(value, None)
        if self.is_empty():
            self.first = new
            self.last = self.first
        else:
            self.last.next_node = new
            self.last = self.last.next_node

    def dequeue(self):
        if self.first is None:
            return self.first
        to_be_returned = self.first
        self.first = self.first.next_node
        return to_be_returned.value

    def is_empty(self):
        return self.first is None
