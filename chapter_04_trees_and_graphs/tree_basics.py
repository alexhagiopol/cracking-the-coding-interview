# Implementations of structures and functions related to trees and graphs.

import Queue


class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
        self.visited = False
        self.inFrontier = False


class BinaryNode:
    def __init__(self, val, left, right):
        self.val = val
        self.left = left
        self.right = right


class Tree:
    def __init__(self, root):
        self.root = root


def visit(node):
    print node.val
    node.visited = True


def in_order_traversal(node):
    if node is not None:
        in_order_traversal(node.left)
        visit(node)
        in_order_traversal(node.right)


def pre_order_traversal(node):
    if node is not None:
        visit(node)
        pre_order_traversal(node.left)
        pre_order_traversal(node.right)


def post_order_traversal(node):
    if node is not None:
        post_order_traversal(node.left)
        post_order_traversal(node.right)
        visit(node)


def dfs(root):
    if root is None:
        return
    visit(root)
    for node in root.children:
        if not node.visited:
            dfs(node)


def bfs(root):
    frontier = Queue.Queue()
    frontier.put(root)
    visit(root)
    while not frontier.empty():
        node = frontier.get()
        visit(node)
        for child in node.children:
            if not child.inFrontier:
                child.inFrontier = True
                frontier.put(child)


def print_bin_tree(root):
    """print out binary tree given its root"""
    frontier = [root]
    next_frontier = []
    while len(frontier) > 0:
        for node in frontier:
            if node is not None:
                print node.val,
                next_frontier += [node.left, node.right]
            else:
                print '_',
        print
        frontier = next_frontier
        next_frontier = []

