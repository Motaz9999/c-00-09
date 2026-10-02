/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 18:42:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/02 21:56:59 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "[Ice] default constructor" << std::endl;
}
Ice::Ice(const std::string &type) : AMateria(type)
{
	std::cout << "[Ice] parametrized constructor" << std::endl;
}
Ice::Ice(const Ice &other) : AMateria(other)
{
	std::cout << "[Ice] copy constructor" << std::endl;
}
Ice &Ice::operator=(const Ice &other)
{
	std::cout << "[Ice] copy assignment operator" << std::endl;
	if (this != &other) // not the same
	{
		AMateria::operator=(other);
	}
	return (*this);
}
Ice::~Ice()
{
	std::cout << "[Ice] destructor" << std::endl;
}

// must implement it 
AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at "<< target.getName()<<" *" << std::endl;
}

