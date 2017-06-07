class LinkedList:
    def __init__(self, head=None):  # initialize with a node
        self.head = head
        self.tail = head

    def add_to_end(self, node):
        if self.tail is not None:
            self.tail.next_node = node
            self.tail = node
        else:
            self.head = node
            self.tail = node

    def peek_head(self):
        return self.head

    def remove_head(self):
        node = self.head
        if self.head is self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next_node
        return node


class Animal:
    def __init__(self, name, species, order, next_node=None):
        self.name = name
        self.species = species
        self.order = order
        self.next_node = next_node


class AnimalShelter:
    def __init__(self):
        self.cats = LinkedList()
        self.dogs = LinkedList()
        self.order = 0

    def enqueue(self, species, name):
        self.order += 1
        animal = Animal(name, species, self.order)
        if animal.species == "cat":
            self.cats.add_to_end(animal)
        else:
            self.dogs.add_to_end(animal)

    def dequeue_dog(self):
        return self.dogs.remove_head()

    def dequeue_cat(self):
        return self.cats.remove_head()

    def dequeue_any(self):
        if self.dogs.peek_head() is not None and self.cats.peek_head() is not None:
            if self.cats.peek_head().order < self.dogs.peek_head().order:
                return self.cats.remove_head()
            else:
                return self.dogs.remove_head()
        elif self.dogs.peek_head() is not None:
            return self.dogs.remove_head()
        elif self.cats.peek_head() is not None:
            return self.cats.remove_head()
        else:
            return None