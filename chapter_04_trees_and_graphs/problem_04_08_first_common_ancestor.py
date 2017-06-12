def fca(node1, node2):
    count1 = 0
    count2 = 0
    runner1 = node1
    runner2 = node2
    while runner1 is not None:
        runner1 = runner1.parent
        count1 += 1
    while runner2 is not None:
        runner2 = runner2.parent
        count2 += 1
    if count1 > count2:
        deep_node = node1
        shallow_node = node2
    else:
        deep_node = node2
        shallow_node = node1
    difference = abs(count1 - count2)
    while difference != 0:
        deep_node = deep_node.parent
        difference -= 1
    while deep_node is not None and shallow_node is not None:
        if deep_node is shallow_node:
            return deep_node
        deep_node = deep_node.parent
        shallow_node = shallow_node.parent
    return None