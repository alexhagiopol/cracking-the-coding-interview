#include "problem_03_06_animalShelter.h"

namespace chapter_03 {
    Animal::Animal(const std::string& name, int ID) {
        _name = name;
        _ID = ID;
        _species = Species::none;
    }

    Dog::Dog(const std::string& name, int ID) : Animal(name, ID) {
        _species = Species::dog;
    }

    Cat::Cat(const std::string& name, int ID) : Animal(name, ID) {
        _species = Species::cat;
    }

    AnimalShelter::AnimalShelter() {
        _dogs = Queue<Dog*>();
        _cats = Queue<Cat*>();
        _timestamp = 0;
    }

    void AnimalShelter::enqueue(Animal* animal) {
        if (animal == nullptr) return;
        animal->setID(_timestamp);
        _timestamp ++;
        if (animal->getSpecies() == Species::cat) {
            _cats.push(static_cast<Cat*>(animal));
        } else if (animal->getSpecies() == Species::dog) {
            _dogs.push(static_cast<Dog*>(animal));
        }
    }

    Cat* AnimalShelter::dequeueCat() {
        if (_cats.isEmpty()) {
            return nullptr;
        } else {
            return _cats.pop();
        }
    }

    Dog* AnimalShelter::dequeueDog() {
        if (_dogs.isEmpty()) {
            return nullptr;
        } else {
            return _dogs.pop();
        }
    }

    Animal* AnimalShelter::dequeueAny() {
        // if either of the queues is empty, we need to handle
        if (_dogs.isEmpty() && _cats.isEmpty()) {
            return nullptr;
        } else if (_dogs.isEmpty()) {
            return dequeueCat();
        } else if (_cats.isEmpty()) {
            return dequeueDog();
        }
        // return the animal with lowest ID
        int dogID = _dogs.peek()->getID();
        int catID = _cats.peek()->getID();
        if (dogID <= catID) {
            return dequeueDog();
        } else {
            return dequeueCat();
        }
    }
}

