# Implementations of structures and functions related to trees and graphs.

import queue


class BinaryNode:  # binary tree node
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class BinaryNodeLP:  # binary node with link to parent
    def __init__(self, val, left=None, right=None, parent=None):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent

    def __eq__(self, other):
        if self.val == other.val:
            return True
        return False


class LLElem:  # linked list element. Used for P 4.3 that demands linked list
    def __init__(self, val, next_elem=None):
        self.val = val
        self.next_elem = next_elem


def in_order_traversal(node, visit_sequence):
    if node is not None:
        in_order_traversal(node.left, visit_sequence)
        visit_sequence.append(node.val)  # visit operation
        in_order_traversal(node.right, visit_sequence)


def pre_order_traversal(node, visit_sequence):
    if node is not None:
        visit_sequence.append(node.val)  # visit operation
        pre_order_traversal(node.left, visit_sequence)
        pre_order_traversal(node.right, visit_sequence)


def post_order_traversal(node, visit_sequence):
    if node is not None:
        post_order_traversal(node.left, visit_sequence)
        post_order_traversal(node.right, visit_sequence)
        visit_sequence.append(node.val)  # visit operation


class Node:  # general graph node
    def __init__(self, val, children=()):
        self.val = val
        self.children = children
        self.visited = False


def dfs(root, visit_sequence):
    if root is None:
        return None
    visit_sequence.append(root.val)  # visit operation
    for node in root.children:
        dfs(node, visit_sequence)


def bfs(root, visit_sequence):
    if root is None:
        return None
    frontier = queue.Queue()
    frontier.put(root)
    while not frontier.empty():
        node = frontier.get()
        visit_sequence.append(node.val)  # visit operation
        for child in node.children:
            if not child.visited:
                child.visited = True
                frontier.put(child)


def stringify_bin_tree(root):
    frontier = [root]
    next_frontier = []
    display_str = ''
    while len(frontier) > 0:
        for node in frontier:
            if node is not None:
                display_str += str(node.val) + ','
                next_frontier += [node.left, node.right]
            else:
                display_str += '_,'
        display_str += '\n'
        frontier = next_frontier
        next_frontier = []
    return display_str


def stringify_list_of_linked_lists(linked_lists):
    display_str = ''
    for ll in linked_lists:
        elem = ll[0]
        while elem is not None:
            display_str += str(elem.val) + ','
            elem = elem.next_elem
        display_str += '\n'
    return display_str
