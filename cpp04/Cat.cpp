/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:23:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/09 19:25:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>
#include <sstream>

Cat::Cat() : AAnimal()
{
	std::cout << "[Cat] default constructor -> " << _name << std::endl;
}

Cat::Cat(const std::string& name) : AAnimal(name)
{
	std::cout << "[Cat] parameterized constructor -> " << _name << std::endl;
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor -> " << _name << std::endl;
}

void Cat::makeSound() const
{
	std::cout << _name << " says: Meow!" << std::endl;
}
std::string  Cat::serialize() const
{
	std::stringstream oss;
	oss << "{ \"type\": \"Cat\", \"name\": \"" << _name << "\" }";
	return oss.str();
}