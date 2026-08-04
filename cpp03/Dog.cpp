/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:25:43 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 14:27:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal(), _breed("Unknown Breed")
{
	std::cout << "Dog default constructor called." << std::endl;
}
Dog::Dog(const std::string &name, const std::string &breed) : Animal(name),
	_breed(breed)
{
	std::cout << "Dog parameterized constructor called for a " << _breed << "." << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called." << std::endl;
}

std::string Dog::getBreed() const
{
    return _breed;
}