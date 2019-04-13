def remove_dups(head):  # O(n) speed with O(n) space for hash table
    hash_table = {head.value: True}
    while head is not None:
        if head.next_node is None:
            break
        if hash_table.get(head.next_node.value) is not None:
            head.next_node = head.next_node.next_node
        else:
            hash_table[head.next_node.value] = True
            head = head.next_node


def remove_dups_alternative(head):  # O(n^2) speed with O(1) space due to no hash table
    while head is not None:
        runner = head
        while runner is not None:
            if runner.next_node is None:
                break
            if runner.next_node.value == head.value:
                runner.next_node = runner.next_node.next_node
            runner = runner.next_node
        head = head.next_node
