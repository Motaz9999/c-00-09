/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 22:57:35 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() : _type("AAnimal")
{
    std::cout << "[AAnimal] default constructor -> " << _type << std::endl;
}

AAnimal::AAnimal(const std::string &type) : _type(type)
{
    std::cout << "[AAnimal] parameterized constructor -> " << _type << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
    std::cout << "[AAnimal] copy constructor -> " << _type << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "[AAnimal] copy assignment operator ->" << _type << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "[AAnimal] destructor -> " << _type << std::endl;
}
const std::string &AAnimal::getType() const
{
    return _type;
}

void AAnimal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}
