from . import LinkedList as ll


def pad_zeros(head, num_zeros):
    if head is None:
        return None
    node = head
    while node.next_node is not None:
        node = node.next_node

    for i in range(num_zeros):
        node.next_node = ll.Node(0, None)
        node = node.next_node


def sum_lists(node1, node2):
    if not node1 or not node2:
        return None

    l1 = ll.list_length(node1)
    l2 = ll.list_length(node2)
    if l1 > l2:
        pad_zeros(node2, l1 - l2)
    elif l2 > l1:
        pad_zeros(node1, l2 - l1)

    current1 = node1
    current2 = node2
    head = ll.Node(0, None)
    tail = head
    while current1 is not None:
        sum = current1.value + current2.value + tail.value
        if sum > 9:
            tail.value = sum - 10
            tail.next_node = ll.Node(1, None)
        else:  # sum <= 9
            tail.value = sum
            tail.next_node = ll.Node(0, None)
        tail = tail.next_node
        current1 = current1.next_node
        current2 = current2.next_node
    return head


