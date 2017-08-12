class Tower:
    def __init__(self, disks=None):
        if disks is None:
            self.disks = []
        else:
            self.disks = disks

    def add(self, value):
        if len(self.disks) <= 0:
            self.disks.append(value)
            return
        elif value <= self.disks[-1]:
            self.disks.append(value)
            return
        else:
            return

    def move_top_to(self, destination):
        if len(self.disks) <= 0:
            return
        destination.add(self.disks[-1])
        self.disks.pop()

    def move_disks(self, n, destination, buffer):
        if n > 0:
            self.move_disks(n - 1, buffer, destination)
            self.move_top_to(destination)
            buffer.move_disks(n - 1, destination, self)
