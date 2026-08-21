/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:43:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/21 18:28:29 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// std::string _name;
// unsigned int _hitPoints;
// unsigned int _energyPoints;
// unsigned int _attackDamage;
// give the attributes ScavTrap nums
// btw cant put the parent attributes in the IL of this class

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "[ScavTrap] parameterized constructor called" << std::endl;
}
// copy constructor  // just use the for clap cus u dont have any new att
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "[ScavTrap] copy constructor called" << std::endl;
}

// assign other data from other to this obj
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "[ScavTrap] copy assignment operator called" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	// casting to claptrap type static_cast<ClapTrap&>(*this)
	// then use = ,,
	//	auto casted to claptrap its ok bc its origins is from claptrap
	static_cast<ClapTrap &>(*this) = other;
	// make it parent obj point to it then use the operator= from that calls
	return (*this);
}
ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] destructor called" << std::endl;
		// the parent destructor auto called when son die so no need to manual call
}
// // not override put its redefinition  or name hideing
void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[ScavTrap] " << _name << " doesn't have enough hit points or energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "[ScavTrap] " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage!" << std::endl;
}
void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "[ScavTrap] " << _name << " have " << _hitPoints << " hit points left so it cant take anymore damage!" << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints)
	{
		this->_hitPoints = 0;
	}
	else
	{
		this->_hitPoints -= amount;
	}
	std::cout << "[ScavTrap] " << this->_name << " has taken " << amount << " damage points and has " << this->_hitPoints << " hit points left." << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount) // redefinition all these fun
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[ScavTrap] " << _name << " have " << _hitPoints << " hit points and " << _energyPoints << " energy points so it cant be repaired!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "[ScavTrap] " << _name << " repaired by adding " << amount << " to his hit points and have a total of " << _hitPoints << " hit points." << std::endl;
}
// //btw also have unique fun
void ScavTrap::guardGate() const
{
	if (_hitPoints <= 0)
	{
		std::cout << "[ScavTrap] " << _name << " have " << _hitPoints << " hit points and " << _energyPoints << " energy points so it cant be in Gate keeper mode!" << std::endl;
		return ;
	}
	std::cout << "[ScavTrap] " << this->_name << " is now in Gate keeper mode!" << std::endl;
}