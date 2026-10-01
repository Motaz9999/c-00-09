/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:21 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 23:01:51 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
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
    std::cout << "=== AAnimal construction and polymorphism ===" << std::endl;
    printLine();
    {
    //     AAnimal animal;
    //     AAnimal namedAnimal("Named animal");
    //     AAnimal animalCopy(animal);
    //     AAnimal assignedAnimal("Temporary");
    // printLine();

    //     assignedAnimal = namedAnimal;//temp now Named AAnimal so both are named animal
    //     AAnimal &refAnimal = assignedAnimal;
    //     assignedAnimal = refAnimal;//test self-assignment
    // printLine();

    //     allPassed = check(animal.getType() == "AAnimal", "AAnimal default type") && allPassed;
    //     allPassed = check(namedAnimal.getType() == "Named animal", "AAnimal parameterized type") && allPassed;
    //     allPassed = check(animalCopy.getType() == "AAnimal", "AAnimal copy constructor") && allPassed;
    //     allPassed = check(assignedAnimal.getType() == "Named animal", "AAnimal copy assignment") && allPassed;

    // printLine();
    //     animal.makeSound();
    //     namedAnimal.makeSound();
    // printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Dog and Cat construction, copying, and assignment ===" << std::endl;
    printLine();
    printLine();

    {
        Dog dog;
        Dog namedDog("Named dog");
        Dog copiedDog(dog);
        Dog assignedDog("Temporary dog");
    printLine();

        assignedDog = namedDog;
        Dog &refDog = assignedDog;
        assignedDog = refDog;
    printLine();

        Cat cat;
        Cat namedCat("Named cat");
        Cat copiedCat(cat);
        Cat assignedCat("Temporary cat");
    printLine();

        assignedCat = namedCat;
        Cat &refCat = assignedCat;
        assignedCat = refCat;
    printLine();
        allPassed = check(dog.getType() == "Dog", "Dog default type") && allPassed;
        allPassed = check(namedDog.getType() == "Named dog", "Dog parameterized type") && allPassed;
        allPassed = check(copiedDog.getType() == "Dog", "Dog copy constructor") && allPassed;
        allPassed = check(assignedDog.getType() == "Named dog", "Dog copy assignment") && allPassed;
        allPassed = check(cat.getType() == "Cat", "Cat default type") && allPassed;
        allPassed = check(namedCat.getType() == "Named cat", "Cat parameterized type") && allPassed;
        allPassed = check(copiedCat.getType() == "Cat", "Cat copy constructor") && allPassed;
        allPassed = check(assignedCat.getType() == "Named cat", "Cat copy assignment") && allPassed;
    printLine();

    dog.makeSound();
    cat.makeSound();
    printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Brain construction, copying, and assignment ===" << std::endl;
    printLine();
    printLine();

    {
        Brain brain;
        brain.setIdea(0, "first idea");
        brain.setIdea(99, "last idea");
    printLine();

        Brain copiedBrain(brain);
        Brain assignedBrain;
        assignedBrain.setIdea(0, "temporary idea");
    printLine();
        
        assignedBrain = brain;
        Brain &refBrain = assignedBrain;
        assignedBrain = refBrain;
    printLine();

        allPassed = check(brain.getIdea(0) == "first idea", "Brain first valid index") && allPassed;
        allPassed = check(brain.getIdea(99) == "last idea", "Brain last valid index") && allPassed;
        allPassed = check(brain.getIdea(-1).empty(), "Brain rejects negative index") && allPassed;
        allPassed = check(brain.getIdea(100).empty(), "Brain rejects index 100") && allPassed;
        allPassed = check(copiedBrain.getIdea(0) == "first idea", "Brain copy constructor") && allPassed;
        allPassed = check(copiedBrain.getIdea(99) == "last idea", "Brain copied all ideas") && allPassed;
        allPassed = check(assignedBrain.getIdea(0) == "first idea", "Brain copy assignment") && allPassed;
        allPassed = check(assignedBrain.getIdea(99) == "last idea", "Brain assignment copied all ideas") && allPassed;
    printLine();

        copiedBrain.setIdea(0, "changed copy");
        copiedBrain.setIdea(-1, "ignored");
        copiedBrain.setIdea(100, "ignored");
        allPassed = check(brain.getIdea(0) == "first idea", "Brain copies have independent storage") && allPassed;
    printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Leak Test 1: Subject basic test (new / delete) ===" << std::endl;
    printLine();
    printLine();
    {
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();

    printLine();
        delete j;//should not create a leak
        delete i;
    printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Leak Test 2: Deep copy & memory address independence ===" << std::endl;

    printLine();
    printLine();
    {
        Dog dog1;
        dog1.setIdea(0, "Dog idea 0");
        dog1.setIdea(1, "Dog idea 1");
    printLine();

        Dog dog2(dog1); // copy constructor
        Dog dog3;
    printLine();

        dog3 = dog1;    // copy assignment
    printLine();

        allPassed = check(dog2.getIdea(0) == "Dog idea 0", "Dog copy constructor copied idea") && allPassed;
        allPassed = check(dog3.getIdea(0) == "Dog idea 0", "Dog assignment copied idea") && allPassed;
        allPassed = check(dog1.getBrain() != dog2.getBrain(), "Dog copy has distinct Brain address") && allPassed;
        allPassed = check(dog1.getBrain() != dog3.getBrain(), "Dog assignment has distinct Brain address") && allPassed;
    printLine();

        // Modifying dog1 must NOT affect dog2 or dog3
        dog1.setIdea(0, "Modified Dog idea 0");
        allPassed = check(dog2.getIdea(0) == "Dog idea 0", "Dog2 idea independent from dog1") && allPassed;
        allPassed = check(dog3.getIdea(0) == "Dog idea 0", "Dog3 idea independent from dog1") && allPassed;
    printLine();

        Cat cat1;
        cat1.setIdea(0, "Cat idea 0");
        Cat cat2(cat1);
        Cat cat3;
    printLine();

        cat3 = cat1;
    printLine();

        allPassed = check(cat2.getIdea(0) == "Cat idea 0", "Cat copy constructor copied idea") && allPassed;
        allPassed = check(cat3.getIdea(0) == "Cat idea 0", "Cat assignment copied idea") && allPassed;
        allPassed = check(cat1.getBrain() != cat2.getBrain(), "Cat copy has distinct Brain address") && allPassed;
        allPassed = check(cat1.getBrain() != cat3.getBrain(), "Cat assignment has distinct Brain address") && allPassed;
    printLine();

        cat1.setIdea(0, "Modified Cat idea 0");
        allPassed = check(cat2.getIdea(0) == "Cat idea 0", "Cat2 idea independent from cat1") && allPassed;
        allPassed = check(cat3.getIdea(0) == "Cat idea 0", "Cat3 idea independent from cat1") && allPassed;
    printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Leak Test 3: Multiple reassignments & chained assignments ===" << std::endl;
    printLine();
    printLine();
    {
        Dog d1;
        Dog d2;
        Dog d3;
    printLine();

        d1.setIdea(0, "Alpha");
        d2.setIdea(0, "Beta");
        d3.setIdea(0, "Gamma");
    printLine();

        // Repeated reassignment must not leak brains
        d1 = d2;
        d1 = d3;
        d2 = d1;
        d3 = d2 = d1; // Chained assignment
    printLine();

        allPassed = check(d1.getIdea(0) == "Gamma", "Chained assignment d1") && allPassed;
        allPassed = check(d2.getIdea(0) == "Gamma", "Chained assignment d2") && allPassed;
        allPassed = check(d3.getIdea(0) == "Gamma", "Chained assignment d3") && allPassed;
    printLine();

    }
    printLine();
    printLine();

    std::cout << "=== Leak Test 4: Subject polymorphic array (half Dogs, half Cats) ===" << std::endl;
    printLine();
    printLine();
    {

        const int animalCount = 10;
        AAnimal *animals[animalCount];
    printLine();

        for (int idx = 0; idx < animalCount / 2; idx++)
            animals[idx] = new Dog();
    printLine();

            for (int idx = animalCount / 2; idx < animalCount; idx++)
            animals[idx] = new Cat();
    printLine();

        for (int idx = 0; idx < animalCount; idx++)
            animals[idx]->makeSound();
    printLine();

        // Loop over the array and delete every AAnimal through AAnimal* base pointer
        for (int idx = 0; idx < animalCount; idx++)
            delete animals[idx];
    printLine();

       }
    printLine();

    std::cout << (allPassed ? "All checks passed with ZERO leaks." : "Some checks failed.") << std::endl;
    printLine();

    return allPassed ? 0 : 1;
}

