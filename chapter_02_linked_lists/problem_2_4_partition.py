class Node:
    def __init__(self, value, next_node):
        self.value = value
        self.next_node = next_node

def print_list(head):
    while head is not None:
        print str(head.value) + " ",
        head = head.next_node
    print

def partition(node, k):
    tail = node
    head = node
    while node is not None:
        nextNode = node.next_node
        node.next_node = None
        if node.value >= k:
            tail.next_node = node
            tail = node
        else:
            node.next_node = head
            head = node
        node = nextNode
    return head

if __name__ == "__main__":
    """
    Create linked list:
    3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1
    """
    n1 = Node(1, None)
    n2 = Node(2, n1)
    n10 = Node(10, n2)
    n5_1 = Node(5, n10)
    n8 = Node(8, n5_1)
    n5_0 = Node(5, n8)
    n3 = Node(3, n5_0)
    # my_new_head = partition(n3)
    print "input linked list:"
    print_list(n3)
    print "output linked list:"
    print_list(partition(n3, 5))
