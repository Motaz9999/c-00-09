/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:06:23 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/10 18:21:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

// implement all but not the Pure fun Even if u implement the fun u cant make any obj of this class

AAnimal::AAnimal() : _name("Unnamed Animal")
{
	std::cout << "[AAnimal] default constructor -> " << _name << std::endl;
}
AAnimal::AAnimal(const std::string &name) : _name(name)
{
	std::cout << "[AAnimal] parameterized constructor-> " << _name << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "[AAnimal] destructor -> " << _name << std::endl;
}
std::string AAnimal::getName() const
{
	return (_name);
}
// its ok if i dont implement it
void AAnimal::makeSound() const // never reach the light
{
	std::cout << _name << " makes a generic animal sound." << std::endl;
}
// copy const
AAnimal::AAnimal(const AAnimal &obj) : _name(obj._name)
{
	std::cout << "[AAnimal] copy constructor -> " << _name << std::endl;
}

// assign operator
AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "[AAnimal] copy assignment -> " << obj._name << std::endl;
	if (this == &obj)
	{
		return (*this);
	}
	this->_name = obj._name;
	return (*this);
}
