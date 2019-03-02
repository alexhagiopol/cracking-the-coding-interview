/*
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
*/

#pragma once
#include "../chapter_02_linked_lists/Node.h"
#include "Queue.h"
#include <string>

namespace chapter_03 {
    enum Species {none, dog, cat};

    // superclass for Animal that allows animals of any kind to be passed to the same function ot
    // added to the same data structure
    class Animal {
    protected:
        std::string _name;
        int _ID;
        Species _species;

    public:
        Animal (const std::string& name, int ID=0);
        int getID() const {return _ID;}
        void setID(int ID) {_ID = ID;}
        std::string getName() const {return _name;}
        Species getSpecies() const {return _species;}
    };

    // dog subclass
    class Dog : public Animal {
    public:
        Dog(const std::string& name, int ID=0);
    };

    // cat subclass
    class Cat : public Animal {
    public:
        Cat(const std::string& name, int ID=0);
    };

    // animal shelter that is a wrapper around two queues containing dogs and cats
    class AnimalShelter {
    private:
        Queue<Dog*> _dogs;
        Queue<Cat*> _cats;
        int _timestamp;
    public:
        AnimalShelter();
        void enqueue(Animal* animal);
        Cat* dequeueCat();
        Dog* dequeueDog();
        Animal* dequeueAny();
    };
}
