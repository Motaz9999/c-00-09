#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    std::cout << "[Cat] default constructor -> " << _type << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type), _brain(new Brain())
{
    std::cout << "[Cat] parameterized constructor -> " << _type << std::endl;
}

// use the copy const from animal
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] copy constructor -> " << _type << std::endl;
    // must deep copy
    _brain = new Brain(*other._brain); // copy const first make memory then copy
    // must deref cus the obj are ref (cant be pointer and ref same time)
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] copy assignment operator ->" << _type << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); // first
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destructor -> " << _type << std::endl;
    delete _brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
