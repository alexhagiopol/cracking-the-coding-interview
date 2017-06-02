class TripleStack:
    def __init__(self):
        self.array = [None] * 30
        self.i = [0, 5, 10]  # current data insertion indices for each stack
        self.min_i = [0, 5, 10]  # current minimum indices for each stack
        self.max_i = [4, 9, 14]  # current maximum indices for each stack

    def push(self, s, value):  # s is the stack ID. 0, 1, or 2
        if s not in [0, 1, 2]:
            return False
        if self.i[s] < self.max_i[s]:
            self.array[self.i[s]] = value
            self.i[s] += 1
        else:  # expand the triple stack to accomodate more numbers
            self.array[self.i[s]] = value
            expansion_amount = self.max_i[s] - self.min_i[s]
            new_stack = self.array[self.min_i[s] : self.max_i[s] + 1] + [None] * expansion_amount
            if s == 0:
                self.array = new_stack + self.array[self.min_i[1]:]
                self.max_i[:] = [x + expansion_amount for x in self.max_i]
                self.min_i[1:] = [x + expansion_amount for x in self.min_i[1:]]
                self.i[0] += 1
                self.i[1:] = [x + expansion_amount for x in self.i[1:]]

            elif s == 1:
                self.array = self.array[0:self.max_i[0] + 1] + new_stack + self.array[self.min_i[2]:]
                self.max_i[1:] = [x + expansion_amount for x in self.max_i[1:]]
                self.min_i[2] += expansion_amount
                self.i[1] += 1
                self.i[2] += expansion_amount
            elif s == 2:
                self.array = self.array[self.min_i[0]:self.max_i[1]+1] + new_stack
                self.max_i[2] += expansion_amount
                self.i[2] += 1
        return True

    def pop(self, s):
        if s not in [0, 1, 2]:
            return None
        self.i[s] -= 1
        value = self.array[self.i[s]]
        return value



