from .. chapter_02_linked_lists import SinglyLinkedNode as sln


class Stack(object):
    def __init__(self):
        self.head = None
        self.size = 0

    def is_empty(self):
        return self.head is None

    def peek(self):
        if self.is_empty():
            return None
        return self.head.value

    def push(self, value):
        node = sln.SinglyLinkedNode(value, self.head)
        self.head = node
        self.size += 1

    def pop(self):
        if self.is_empty():
            return None
        temp_value = self.head.value
        self.head = self.head.next_node
        self.size -= 1
        return temp_value

    def __str__(self):
        string_list = []  # strings are immutable in Python thus appending to a string is not O(1) amortized
        temp = self.head
        while temp is not None:
            string_list += [str(temp.value)]
            temp = temp.next_node
        return ' '.join(string_list)  # return string with values in top to bottom order
