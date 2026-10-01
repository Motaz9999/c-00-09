/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 20:23:37 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
#include <iostream>

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
    std::cout << "[WrongDog] default constructor -> " << _type << std::endl;
}

WrongDog::WrongDog(const std::string &type) : WrongAnimal(type)
{
    std::cout << "[WrongDog] parameterized constructor -> " << _type << std::endl;
}

WrongDog::WrongDog(const WrongDog &other) : WrongAnimal(other)
{
    std::cout << "[WrongDog] copy constructor -> " << _type << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &other)
{
    std::cout << "[Dog] copy assignment operator ->" << _type << std::endl;

    if (this != &other)
        WrongAnimal::operator=(other);
    return *this;
}

WrongDog::~WrongDog()
{
    std::cout << "[WrongDog] destructor -> " << _type << std::endl;
}

void WrongDog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}
