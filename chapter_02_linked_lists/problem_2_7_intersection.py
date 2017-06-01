def intersection(head1, head2):
    runner1 = head1
    runner2 = head2
    if runner1 is None or runner2 is None:
        return None
    size1 = size2 = 1
    while runner1.next_node is not None:  # advance pointer 1 to end
        runner1 = runner1.next_node
        size1 += 1
    while runner2.next_node is not None:  # advance pointer 2 to end
        runner2 = runner2.next_node
        size2 += 1
    if runner2 is not runner1:  # if the lists don't intersect at all
        return None
    diff = size1 - size2  # determine difference between list lengths
    if diff > 0:  # make new pointers for larger and smaller lists
        larger = head1
        smaller = head2
    else:
        larger = head2
        smaller = head1
    diff = abs(diff)
    for i in range(diff):  # advance pointer for larger list to be "equal" to smaller list
        larger = larger.next_node
    while larger is not smaller:  # advance pointers simultaneously until they are equal
        larger = larger.next_node
        smaller = smaller.next_node
    return smaller
