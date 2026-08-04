/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:16:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 14:21:07 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _name("Unamed Animal")
{
	std::cout << "Animal default constructor called." << std::endl;
}
Animal::Animal(std::string const &name) : _name(name)
{
	std::cout << "Animal parameterized constructor called for " << _name << "." << std::endl;
}
Animal::Animal(Animal const &other) : _name(other._name)
{
	std::cout << "Animal copy constructor called." << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	std::cout << "Animal copy assignment operator called." << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	_name = other._name;
	return (*this);
}
Animal::~Animal()
{
	std::cout << "Animal destructor called for " << _name << "." << std::endl;
}
std::string Animal::getName() const
{
	return (_name);
}