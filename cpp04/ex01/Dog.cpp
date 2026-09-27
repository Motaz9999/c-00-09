#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    std::cout << "[Dog] default constructor -> " << _type << std::endl;
}

Dog::Dog(const std::string &type) : Animal(type), _brain(new Brain())
{
    std::cout << "[Dog] parameterized constructor -> " << _type << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "[Dog] copy constructor -> " << _type << std::endl;
    _brain = new Brain(*other._brain); // copy const first make memory then copy
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "[Fog] copy assignment operator ->" << _type << std::endl;

    if (this != &other)
    {
        Animal::operator=(other); // first
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "[Dog] destructor -> " << _type << std::endl;
    delete _brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
