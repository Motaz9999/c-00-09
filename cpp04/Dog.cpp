/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:10:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/10 18:22:31 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>
#include <sstream>

Dog::Dog() : AAnimal()
{
	std::cout << "[Dog] default constructor -> " << _name << std::endl;
}

Dog::Dog(const std::string &name) : AAnimal(name)
{
	std::cout << "[Dog] parameterized constructor -> " << _name << std::endl;
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor -> " << _name << std::endl;
}

void Dog::makeSound() const
{
	std::cout << _name << " says: Woof! Woof!" << std::endl;
}

std::string Dog::serialize() const
{
	std::ostringstream oss;
	oss << "{ \"type\": \"Dog\", \"name\": \"" << _name << "\" }";
		// make a everything to str its like a notebook
	return (oss.str());
}

Dog::Dog(const Dog &obj): AAnimal(obj)
{
	std::cout << "[Dog] copy constructor -> " << _name << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "[Dog] copy assignment -> " << obj._name << std::endl;
	if(this == &obj)
	{
		return *this;
	}
	AAnimal::operator=(obj);//here we use like
	return *this; 
}

AAnimal *Dog::clone() const
{
	return new Dog(*this);
}
