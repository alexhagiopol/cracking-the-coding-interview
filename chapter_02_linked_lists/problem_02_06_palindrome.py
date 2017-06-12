from . import LinkedList as ll


def palindrome(head):
    if head is None:
        return None
    count = 0
    runner = head
    while runner is not None:  # loop to count # of nodes in list
        count += 1
        runner = runner.next_node
    half_count = count // 2  # compute halfway point
    rev_first = ll.Node(head.value, None)  # start of list that is the reverse of first half of input list
    runner = head
    for i in range(1, half_count):  # create a list that is reverse of first half of input list
        runner = runner.next_node
        node = ll.Node(runner.value, rev_first)
        rev_first = node
    runner = runner.next_node  # advance runner from first half to second half
    if count % 2 != 0:  # odd numbered lists require an extra pointer advancement
        runner = runner.next_node
    runner2 = rev_first
    while runner2 is not None:  # traverse second half of input list simultaneously with reversed list
        if runner2.value != runner.value:  # equality check
            return False
        runner2 = runner2.next_node
        runner = runner.next_node
    return True
