/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:06:22 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 18:06:34 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _name("Unnamed Animal")
{
	std::cout << "[Animal] default constructor -> " << _name << std::endl;
}

Animal::Animal(const std::string& name) : _name(name)
{
	std::cout << "[Animal] parameterized constructor -> " << _name << std::endl;
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor -> " << _name << std::endl;
}

std::string Animal::getName() const
{
	return _name;
}

void Animal::makeSound() const
{
	std::cout << _name << " makes a generic animal sound." << std::endl;
}