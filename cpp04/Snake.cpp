/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:51:57 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 21:04:20 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Snake.hpp"
#include <iostream>

Snake::Snake() : Animal()
{
	std::cout << "[Snake] default constructor -> " << _name << std::endl;
}
Snake::Snake(const std::string &name) : Animal(name)
{
	std::cout << "[Snake] parameterized constructor -> " << _name << std::endl;
}
Snake::~Snake()
{
	std::cout << "[Snake] destructor -> " << _name << std::endl;
}

void Snake::makeSound() const
{
	std::cout << _name << " says: Hiss!" << std::endl;
}
// missing 'const' — does NOT override  so it will be name hiding and it will go with base class
