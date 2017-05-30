def find_loop(root):
    S = root
    F = root
    # set up first meeting
    while True:
        # if there is no loop, we will detect it
        if S is None or F is None:
            return None
        # advance slow and fast pointers
        S = S.next_node
        F = F.next_node.next_node
        if S is F:
            break
    # reset S to beginning
    S = root
    # set up second meeting
    while True:
        # advance pointers at same speed
        S = S.next_node
        F = F.next_node
        if S is F:
            break
    return S