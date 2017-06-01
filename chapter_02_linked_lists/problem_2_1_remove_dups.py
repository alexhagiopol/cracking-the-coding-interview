def remove_dups(head):
    prev_node = head  # keep track of previous and current node to retain ability to remove current node
    hash_table = {prev_node.value: True}
    node = prev_node.next_node
    while node is not None:
        if hash_table.get(node.value, None) is None:  # update hash table with each new value
            hash_table[node.value] = True
            prev_node = node  # advance node
            node = node.next_node  # advance node
        else:
            if node.next_node is None:
                prev_node.next_node = None
                break
            else:
                prev_node.next_node = node.next_node
                node = prev_node.next_node.next_node
