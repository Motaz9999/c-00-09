/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:51:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal() : _type("Animal")
{
    std::cout << "[Animal] default constructor -> " << _type << std::endl;
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "[Animal] parameterized constructor -> " << _type << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
    std::cout << "[Animal] copy constructor -> " << _type << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "[Animal] copy assignment operator ->" << _type << std::endl;
    if (this != &other)
        _type = other._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] destructor -> " << _type << std::endl;
}

const std::string &Animal::getType() const
{
    return _type;
}

void Animal::makeSound() const
{
    std::cout << "Some animal sound" << std::endl;
}
