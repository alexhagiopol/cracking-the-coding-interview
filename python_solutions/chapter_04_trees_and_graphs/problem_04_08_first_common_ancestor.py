def fca(node1, node2):
    count1 = 0
    count2 = 0
    runner1 = node1
    runner2 = node2
    # compute distance from the top for each node
    while runner1 is not None:
        runner1 = runner1.parent
        count1 += 1
    while runner2 is not None:
        runner2 = runner2.parent
        count2 += 1
    # determine which node is deeper based on difference in distances from top
    if count1 > count2:
        deep_node = node1
        shallow_node = node2
    else:
        deep_node = node2
        shallow_node = node1
    difference = abs(count1 - count2)
    # advance deeper node pointer upward by the number of levels eq to the distance
    while difference != 0:
        deep_node = deep_node.parent
        difference -= 1
    # advance both pointers (now at equal depths) upward simultaneously until they point to the same node
    while deep_node is not None and shallow_node is not None:
        if deep_node is shallow_node:
            return deep_node  # if both pointers point to same node, return it
        deep_node = deep_node.parent
        shallow_node = shallow_node.parent
    return None  # if we advance both pointers to the top and they are never equal, the nodes aren't in the same tree
