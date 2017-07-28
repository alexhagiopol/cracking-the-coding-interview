class RandomBinaryNode:
    def __init__(self, value=None, left=None, right=None, num_left_children=0, num_right_children=0):
        self.value = value
        self.left = left
        self.right = right
        self.num_left_children = num_left_children
        self.num_right_children = num_right_children


class RandomBinarySearchTree:
    def __init__(self, root):
        self.root = root

    def insert(self, node):
        if self.root is None:
            self.root = node
        runner = self.root

        while runner is not None:
            if node.value == runner.value:
                pass  # don't add non-unique elements
            if node.value > runner.value:
                runner = runner.right
            else:
                runner = runner.left

    def find(self):
        pass

    def delete(self):
        pass

    def get_random(self):
        pass
