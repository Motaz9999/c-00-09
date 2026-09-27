#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

static bool check(bool condition, const std::string &name)
{
    if (condition)
        std::cout << "[PASS] " << name << std::endl;
    else
        std::cout << "[FAIL] " << name << std::endl;
    return condition;
}
void printLine(void)
{
    std::cout << "=============================================================" << std::endl;
}

int main()
{
    bool allPassed = true;

    printLine();
    std::cout << "=== Animal construction and polymorphism ===" << std::endl;
    printLine();
    {
        Animal animal;
        Animal namedAnimal("Named animal");
        Animal animalCopy(animal);
        Animal assignedAnimal("Temporary");

        assignedAnimal = namedAnimal;//temp now Named Animal so both are named animal
        assignedAnimal = assignedAnimal;//no need to assign
        allPassed = check(animal.getType() == "Animal", "Animal default type") && allPassed;
        allPassed = check(namedAnimal.getType() == "Named animal", "Animal parameterized type") && allPassed;
        allPassed = check(animalCopy.getType() == "Animal", "Animal copy constructor") && allPassed;
        allPassed = check(assignedAnimal.getType() == "Named animal", "Animal copy assignment") && allPassed;

        animal.makeSound();
        namedAnimal.makeSound();
    }
    printLine();

    std::cout << "=== Dog and Cat construction, copying, and assignment ===" << std::endl;
    printLine();

    {
        Dog dog;
        Dog namedDog("Named dog");
        Dog copiedDog(dog);
        Dog assignedDog("Temporary dog");
        assignedDog = namedDog;
        assignedDog = assignedDog;

        Cat cat;
        Cat namedCat("Named cat");
        Cat copiedCat(cat);
        Cat assignedCat("Temporary cat");
        assignedCat = namedCat;
        assignedCat = assignedCat;

        allPassed = check(dog.getType() == "Dog", "Dog default type") && allPassed;
        allPassed = check(namedDog.getType() == "Named dog", "Dog parameterized type") && allPassed;
        allPassed = check(copiedDog.getType() == "Dog", "Dog copy constructor") && allPassed;
        allPassed = check(assignedDog.getType() == "Named dog", "Dog copy assignment") && allPassed;
        allPassed = check(cat.getType() == "Cat", "Cat default type") && allPassed;
        allPassed = check(namedCat.getType() == "Named cat", "Cat parameterized type") && allPassed;
        allPassed = check(copiedCat.getType() == "Cat", "Cat copy constructor") && allPassed;
        allPassed = check(assignedCat.getType() == "Named cat", "Cat copy assignment") && allPassed;

        dog.makeSound();
        cat.makeSound();
    }
    printLine();

    std::cout << "=== Brain construction, copying, and assignment ===" << std::endl;
    printLine();

    {
        Brain brain;
        brain.setIdea(0, "first idea");
        brain.setIdea(99, "last idea");

        Brain copiedBrain(brain);
        Brain assignedBrain;
        assignedBrain.setIdea(0, "temporary idea");
        assignedBrain = brain;
        assignedBrain = assignedBrain;

        allPassed = check(brain.getIdea(0) == "first idea", "Brain first valid index") && allPassed;
        allPassed = check(brain.getIdea(99) == "last idea", "Brain last valid index") && allPassed;
        allPassed = check(brain.getIdea(-1).empty(), "Brain rejects negative index") && allPassed;
        allPassed = check(brain.getIdea(100).empty(), "Brain rejects index 100") && allPassed;
        allPassed = check(copiedBrain.getIdea(0) == "first idea", "Brain copy constructor") && allPassed;
        allPassed = check(copiedBrain.getIdea(99) == "last idea", "Brain copied all ideas") && allPassed;
        allPassed = check(assignedBrain.getIdea(0) == "first idea", "Brain copy assignment") && allPassed;
        allPassed = check(assignedBrain.getIdea(99) == "last idea", "Brain assignment copied all ideas") && allPassed;

        copiedBrain.setIdea(0, "changed copy");
        copiedBrain.setIdea(-1, "ignored");
        copiedBrain.setIdea(100, "ignored");
        allPassed = check(brain.getIdea(0) == "first idea", "Brain copies have independent storage") && allPassed;
    }
    printLine();

    std::cout << "=== Polymorphic heap cleanup ===" << std::endl;
    printLine();

    {
        const Animal *animals[3];
        animals[0] = new Animal();
        animals[1] = new Dog();
        animals[2] = new Cat();

        for (int index = 0; index < 3; index++)
        {
            std::cout << animals[index]->getType() << ": ";
            animals[index]->makeSound();
        }

        delete animals[0];
        delete animals[1];
        delete animals[2];
    }
    printLine();

    std::cout << (allPassed ? "All checks passed." : "Some checks failed.") << std::endl;
    printLine();

    return allPassed ? 0 : 1;
}
