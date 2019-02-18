import random


class RandBinNode:

    def __init__(self, value=None, left=None, right=None, children=0):
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

    def insert(self, value):
        if value is None:  # like good silicon valley people, we disallow adding no value
            return
        if self.value is None:  # create children only if the current node has no value
            self.value = value
            return
        self.children += 1
        if value > self.value:
            if self.right is not None:
                self.right.insert(value)
            else:
                self.right = RandBinNode(value)
        else:
            if self.left is not None:
                self.left.insert(value)
            else:
                self.left = RandBinNode(value)
        return

    def get_random(self):
        assert(self.children == self.left_children() + self.right_children())
        num_nodes = 1 + self.children
        rand_int = random.randint(1, num_nodes)
        if rand_int == 1:
            return self.value
        elif 1 < rand_int <= 1 + self.left_children():
            return self.left.get_random()
        elif 1 + self.left_children() < rand_int:
            return self.right.get_random()

    def find(self):
        pass

    def delete(self):
        pass
