/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:47:23 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/02 18:45:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
	std::cout << "[AMateria] default constructor" << std::endl;
}
AMateria::AMateria(const std::string &type) : _type(type)
{
	std::cout << "[AMateria] parametrized constructor" << std::endl;
}
AMateria::AMateria(const AMateria &other) // copy
{
	std::cout << "[AMateria] copy constructor" << std::endl;
	this->_type = other._type;
}
AMateria &AMateria::operator=(const AMateria &other) // assign
{
	std::cout << "[AMateria] copy assignment operator" << std::endl;
	if (this != &other) // not the same
	{
		this->_type = other._type;
	}
	return (*this);
}
AMateria::~AMateria() // destr
{
	std::cout << "[AMateria] destructor" << std::endl;
}

void AMateria::setType(const std::string &type)
{
	this->_type = type;
}
const std::string &AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria: *doing nothing "<<_type << "*" << std::endl;
}
