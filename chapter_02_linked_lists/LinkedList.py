class Node:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node


def print_list(head):
    while head is not None:
        print(str(head.value) + " ")
        head = head.next_node
    print


def list_length(node):
    length = 0
    while node is not None:
        length += 1
        node = node.next_node
    return length