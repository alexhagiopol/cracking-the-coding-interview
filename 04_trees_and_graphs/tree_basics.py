import Queue

class Node:
    def __init__(self, name, children):
        self.name = name
        self.children = children
        self.visited = False
        self.inFrontier = False

class BinaryNode:
    def __init__(self, name, left, right):
        self.name = name
        self.left = left
        self.right = right

class Tree:
    def __init__(self, root):
        self.root = root

def visit(node):
    print node.name
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

