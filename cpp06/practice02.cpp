/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice02.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 06:53:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/26 07:48:34 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <typeinfo>
#include <cstddef>

class Animal
{
public:
    Animal(int age) : _age(age) {}
    virtual ~Animal() {}
    int getAge() const { return _age; }

protected:
    int _age;
};

class Dog : public Animal
{
public:
    Dog(int age, int loyaltyScore) : Animal(age), _loyaltyScore(loyaltyScore) {}
    int getLoyaltyScore() const { return _loyaltyScore; }

private:
    int _loyaltyScore;
};

class Cat : public Animal
{
public:
    Cat(int age, int independence) : Animal(age), _independence(independence) {}
    int getIndependence() const { return _independence; }

private:
    int _independence;
};
void identifyByPointer(Animal *ptr)
{
    Dog *asDog = dynamic_cast<Dog *>(ptr);
    if (asDog != NULL)
    {
        std::cout << "It's a Dog! Loyalty score: " << asDog->getLoyaltyScore() << std::endl;
        return;
    }
    Cat *asCat = dynamic_cast<Cat *>(ptr);
    if (asCat != NULL)
    {
        std::cout << "It's a Cat! Independence: " << asCat->getIndependence() << std::endl;
        return;
    }

    std::cout << "Unknown animal type (neither Dog nor Cat)." << std::endl;
}

//this fun always want a dog animal so anything diff it throws
void identifyByReference(Animal &animal)
{
    try
    {
        Dog &asDog = dynamic_cast<Dog &>(animal);
           std::cout << "It's a Dog! Loyalty score: " << asDog.getLoyaltyScore() << std::endl;
    }
    catch(const std::exception& e)
    {
                std::cout << "Not a Dog (dynamic_cast<Dog&> threw): " << e.what() << std::endl;
    }
    
}
int main()
{
    std::cout << "--- Pointer form: returns NULL on a failed cast ---" << std::endl;
    Dog rex(3, 95);
    Cat whiskers(2, 80);
    Animal *animals[2];
    animals[0] = static_cast<Animal *>(&rex);
    animals[1] = static_cast<Animal *>(&whiskers);
    for (int i = 0; i < 2; i++)
        identifyByPointer(animals[i]);
    std::cout << "\n--- Reference form: throws std::bad_cast on a failed cast ---" << std::endl;
    std::cout << "Trying rex (an actual Dog) as a Dog&:" << std::endl;
    identifyByReference(rex);
    std::cout << "Trying whiskers (a Cat) as a Dog&:" << std::endl;
    identifyByReference(whiskers);

    std::cout << "\n--- End of program ---" << std::endl;
}