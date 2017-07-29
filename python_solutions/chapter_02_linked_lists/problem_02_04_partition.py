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
