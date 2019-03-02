"""
Chapter 03 - Problem 6 - Animal Shelter

Problem Statement:
An animal shelter, which holds only dogs and cats, operates on a strictly "first in,
first out" basis. People must adopt either the "oldest"(based on arrival time) of all animals at the
shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest
animal of that type). They cannot select which specific animal they would like. Create the data structures
to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat.
You may use the built-in LinkedList data structure.

Solution:
We can maintain 2 queues: one for cats and one for dogs. Popping off of the end of each queue will fulfill the
requirements for dequeueDog() and dequeueCat() because queues are first in first out data structures. To fulfill
the requirements for dequeueAny(), we can also maintain a single integer variable that keeps track of the ID
of each animal. This ID is incremented with each animal that is added. When dequeueAny() is called, we check the
end of the cats queue and the end of the dogs queue and we pop the animal with the lowest ID number.

Time complexity: O(N) for building queues of N animals. O(1) for dequeueing an animal.
Space complexity: O(N) for storing queues of N animals.
"""


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
