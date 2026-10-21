/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:16 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 23:00:14 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "[Dog] default constructor -> " << _type << std::endl;
}

Dog::Dog(const std::string &type) : AAnimal(type), _brain(new Brain())
{
	std::cout << "[Dog] parameterized constructor -> " << _type << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other), _brain(NULL)
{
	std::cout << "[Dog] copy constructor -> " << _type << std::endl;
	if (other._brain)
		_brain = new Brain(*other._brain);
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "[Dog] copy assignment operator ->" << _type << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other); // first
		if (other._brain)
		{
			if (_brain)
				*_brain = *other._brain;
			else
				_brain = new Brain(*other._brain);
		}
		else
		{
			delete _brain;
			_brain = NULL;
		}
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
	static const std::string empty = "";
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