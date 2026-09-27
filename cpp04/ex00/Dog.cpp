#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "[Dog] default constructor -> " << _type << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type)
{
    std::cout << "[Dog] parameterized constructor -> " << _type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "[Dog] copy constructor -> " << _type << std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Fog] copy assignment operator ->" << _type << std::endl;

    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] destructor -> " << _type << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
