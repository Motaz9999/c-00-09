/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 21:36:07 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/20 22:01:05 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "[FragTrap] parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "[FragTrap] copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "[FragTrap] copy assignment operator called" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	// casting to claptrap type static_cast<ClapTrap&>(*this)
	// then use = ,,
	// auto casted to claptrap its ok bc its origins is from claptrap
	static_cast<ClapTrap &>(*this) = other;
	// make it parent obj point to it then use the operator= from that calls
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[FragTrap] " << _name << " doesn't have enough hit points or energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "[FragTrap] " << _name << " attacks " << target << ",causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "[FragTrap] " << _name << " have " << _hitPoints << " hit points left so it cant take anymore damage!" << std::endl;
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
	std::cout << "[FragTrap] " << this->_name << " has taken " << amount << " damage points and has " << this->_hitPoints << " hit points left." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[FragTrap] " << _name << " have " << _hitPoints << " hit points and " << _energyPoints << " energy points so it cant be repaired!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "[FragTrap] " << _name << " repaired by adding " << amount << " to his hit points and have a total of " << _hitPoints << " hit points." << std::endl;
} // redefinition all these fun

void FragTrap::highFivesGuys() const
{
	if (_hitPoints <= 0)
	{
		std::cout << "[FragTrap] " << _name << " have " << _hitPoints << " hit points and " << _energyPoints << " energy points so it cant do positive high-fives request !" << std::endl;
		return ;
	}
	std::cout << "[FragTrap] " << this->_name << " positive high-fives request !" << std::endl;
}