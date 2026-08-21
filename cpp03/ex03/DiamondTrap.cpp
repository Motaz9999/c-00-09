/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:47:24 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/21 18:45:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//   private:
// 	std::string _name;

//   protected:
//   public:
DiamondTrap::DiamondTrap() : ClapTrap("Unknown_clap_name"), FragTrap(),
	ScavTrap()
{
	this->_name = "Unknown";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[DiamondTrap] default constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name
	+ "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "[DiamondTrap] parametrized constructor called" << std::endl;
}
// this is for the diamond class
// 	// for the clap const use name+"_clap_name"
// 	// for hitpoint use FragTrap + attack damage
// 	// for attack() and energy points use ScavTrap
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
	FragTrap(other), ScavTrap(other)
{
	std::cout << "[DiamondTrap] copy constructor called" << std::endl;
	this->_name = other._name;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "[DiamondTrap] copy assignment operator called" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	this->_name = other._name;
	this->_attackDamage = other._attackDamage;
	this->_energyPoints = other._energyPoints;
	this->_hitPoints = other._hitPoints;
	this->ClapTrap::_name = other.ClapTrap::_name;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "[DiamondTrap] destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
}
// redefinition all these fun
// 	// btw also have unique fun
void DiamondTrap::whoAmI() const
{
	std::cout << "I am DiamondTrap " << this->_name << ",and my ClapTrap name is " << ClapTrap::_name << std::endl;
} // display the name and the clap name