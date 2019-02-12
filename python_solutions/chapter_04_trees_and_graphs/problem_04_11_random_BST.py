import random


class RandBinNode:

    def __init__(self, value, left=None, right=None, children=0):
        self.value = value
        self.left = left
        self.right = right
        self.children = children

    def left_children(self):
        if self.left is None:
            return 0
        else:
            return 1 + self.left.children

    def right_children(self):
        if self.right is None:
            return 0
        else:
            return 1 + self.right.children


class RandBST:
    def __init__(self, root=None):
        self.root = root

    def insert(self, value):
        if self.root is None:
            self.root = RandBinNode(value)
            return
        runner = self.root
        while 1:
            if value > runner.value:
                runner.children += 1
                if runner.right is not None:
                    runner = runner.right
                else:
                    runner.right = RandBinNode(value)
                    return
            elif value < runner.value:
                runner.children += 1
                if runner.left is not None:
                    runner = runner.left
                else:
                    runner.left = RandBinNode(value)
                    return
            else:
                return  # don't allow non-unique values in tree

    def get_random(self):
        if self.root is None:
            return None
        runner = self.root
        while 1:
            assert(runner.children == runner.left_children() + runner.right_children())  #
            sum_of_nodes = 1 + runner.children
            rand_int = random.randint(1, sum_of_nodes)
            if rand_int == 1:
                return runner.value
            elif 1 < rand_int <= 1 + runner.left_children():
                runner = runner.left
            elif 1 + runner.left_children() < rand_int:
                runner = runner.right

    def find(self):
        pass

    def delete(self):
        pass
