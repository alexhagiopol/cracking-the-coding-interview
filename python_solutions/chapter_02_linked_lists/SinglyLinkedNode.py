class SinglyLinkedNode:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node


def stringify_linked_list(head):
    display_str = ''
    while head is not None:
        display_str += str(head.value) + ","
        head = head.next_node
    return display_str


def list_length(node):
    length = 0
    while node is not None:
        length += 1
        node = node.next_node
    return length