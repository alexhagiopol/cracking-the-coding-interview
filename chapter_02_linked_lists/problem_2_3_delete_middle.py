def delete_middle(node):
    node.value = node.next_node.value
    node.next_node = node.next_node.next_node