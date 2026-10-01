/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:27 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:51:28 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] default constructor -> " << _type << std::endl;
}

WrongCat::WrongCat(const std::string &type) : WrongAnimal(type)
{
    std::cout << "[WrongCat] parameterized constructor -> " << _type << std::endl;
}

// use the copy const from animal
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "[WrongCat] copy constructor -> " << _type << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "[WrongCat] copy assignment operator ->" << _type << std::endl;
    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destructor -> " << _type << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
