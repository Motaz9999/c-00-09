/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:10:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/07 20:32:50 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : AAnimal()
{
	std::cout << "[Dog] default constructor -> " << _name << std::endl;
}

Dog::Dog(const std::string& name) : AAnimal(name)
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