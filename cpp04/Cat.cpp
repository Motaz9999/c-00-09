#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
	std::cout << "[Cat] default constructor -> " << _name << std::endl;
}

Cat::Cat(const std::string& name) : Animal(name)
{
	std::cout << "[Cat] parameterized constructor -> " << _name << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor -> " << _name << std::endl;
}

void Cat::makeSound() const
{
	std::cout << _name << " says: Meow!" << std::endl;
}