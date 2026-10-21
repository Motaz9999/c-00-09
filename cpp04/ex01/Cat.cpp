/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 21:31:12 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
Cat::Cat(const Cat &other) : Animal(other), _brain(NULL)
{
	std::cout << "[Cat] copy constructor -> " << _type << std::endl;
	if (other._brain)
		_brain = new Brain(*other._brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "[Cat] copy assignment operator ->" << _type << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // first
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

Cat::~Cat()
{
	delete	_brain;

	std::cout << "[Cat] destructor -> " << _type << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

const std::string &Cat::getIdea(int index) const
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
void Cat::setIdea(int index, const std::string &idea)
{
	if (_brain != NULL)
	{
		_brain->setIdea(index, idea);
	}
}
// then use  what inside brain
Brain *Cat::getBrain(void) const
{
	return (_brain);
}