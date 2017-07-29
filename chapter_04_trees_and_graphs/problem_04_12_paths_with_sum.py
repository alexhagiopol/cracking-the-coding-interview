def paths_with_sum(root, target_sum):
    hash_table = {}
    return count_paths(root, target_sum, 0, hash_table)


def count_paths(node, target_sum, running_sum, hash_table):
    if node is None:
        return 0
    running_sum = running_sum + node.val  # immutable value recreated
    if running_sum in hash_table:
        hash_table[running_sum] += 1
    else:
        hash_table[running_sum] = 1
    count = int(running_sum == target_sum) \
        + hash_table.get(running_sum - target_sum, 0) \
        + count_paths(node.left, target_sum, running_sum, hash_table) \
        + count_paths(node.right, target_sum, running_sum, hash_table)
    hash_table[running_sum] -= 1
    assert(hash_table[running_sum] >= 0)
    return count
