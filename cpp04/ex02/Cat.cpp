/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 23:00:37 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "[Cat] default constructor -> " << _type << std::endl;
}

Cat::Cat(const std::string &type) : AAnimal(type), _brain(new Brain())
{
	std::cout << "[Cat] parameterized constructor -> " << _type << std::endl;
}

// use the copy const from animal
Cat::Cat(const Cat &other) : AAnimal(other)
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
		AAnimal::operator=(other); // first
		*_brain = *other._brain;
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