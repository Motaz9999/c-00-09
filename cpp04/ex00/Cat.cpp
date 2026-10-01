/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:45 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:51:46 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] default constructor -> " << _type << std::endl;
}

Cat::Cat(const std::string &type) : Animal(type)
{
    std::cout << "[Cat] parameterized constructor -> " << _type << std::endl;
}

// use the copy const from animal
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "[Cat] copy constructor -> " << _type << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "[Cat] copy assignment operator ->" << _type << std::endl;
    if (this != &other)
        Animal::operator=(other);
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destructor -> " << _type << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
