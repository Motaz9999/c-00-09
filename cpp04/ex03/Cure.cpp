/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 19:27:55 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 01:48:37 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "[Cure] default constructor" << std::endl;
}
Cure::Cure(const std::string &type) : AMateria(type)
{
	std::cout << "[Cure] parametrized constructor" << std::endl;
}
Cure::Cure(const Cure &other) : AMateria(other)
{
	std::cout << "[Cure] copy constructor" << std::endl;
}
Cure &Cure::operator=(const Cure &other)
{
	std::cout << "[Cure] copy assignment operator" << std::endl;
	if (this != &other) // not the same
	{
		AMateria::operator=(other);
	}
	return (*this);
}
Cure::~Cure()
{
	std::cout << "[Cure] destructor" << std::endl;
}

// must implement it
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}
void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
