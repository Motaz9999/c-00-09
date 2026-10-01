/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:16 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 21:30:53 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "[Dog] copy assignment operator ->" << _type << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // first
		*_brain = *other._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete	_brain;

	std::cout << "[Dog] destructor -> " << _type << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

const std::string &Dog::getIdea(int index) const
{
	static const std::string &empty="";
	if (_brain != NULL) // must check bc its pointer
	{
		return (_brain->getIdea(index));
	}
	else
	{
		return (empty);
	}
}
// same here must check
void Dog::setIdea(int index, const std::string &idea)
{
	if (_brain != NULL)
	{
		_brain->setIdea(index, idea);
	}
}
// then use  what inside brain
Brain *Dog::getBrain(void) const
{
	return (_brain);
}