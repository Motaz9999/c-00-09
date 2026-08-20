/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 16:41:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/15 18:37:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//   private:
//   std::string _name;
//   int _hitPoints;
//   int _energyPoints;
//   int _attackDamage;

//   public://must also implement OCF
ClapTrap::ClapTrap() : _name("Unknown"), _hitPoints(10), _energyPoints(10),
	_attackDamage(0)
{
	std::cout << "[ClapTrap] default constructor called" << std::endl;
}
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	std::cout << "[ClapTrap] parameterized constructor called" << std::endl;
}
// copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) : _name(other._name),
	_hitPoints(other._hitPoints), _energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage)
{
	std::cout << "[ClapTrap] copy constructor called" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "[ClapTrap] copy assignment operator called" << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}
ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] destructor called" << std::endl;
}

// before attacking or do anything we must check if we can
void ClapTrap::attack(const std::string &target)
{
	// if i want to attack target i must have energy and if the obj still alive
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[ClapTrap] " << _name << " doesn't have enough hit points or energy points to attack!" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "[ClapTrap] " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

// this fun represent the fun taking damage
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "[ClapTrap] " << _name << " have " << _hitPoints << " hit points left so it cant take anymore damage!" << std::endl;
		return ;
	}
	if (amount >= this->_hitPoints) {
        this->_hitPoints = 0;
    } else {
        this->_hitPoints -= amount;
    }
std::cout << "[ClapTrap] " << this->_name << " has taken " << amount 
              << " damage points and has " << this->_hitPoints 
              << " hit points left." << std::endl;
}

//+ to hit points
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "[ClapTrap] " << _name << " have " << _hitPoints << " hit points and " << _energyPoints << " energy points so it cant be repaired!" << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "[ClapTrap] " << _name << " repaired by adding " << amount << " to his hit points and have a total of " << _hitPoints << " hit points." << std::endl;
}

std::string ClapTrap::getName() const
{
	return (_name);
}
unsigned ClapTrap::getAttackDamage() const
{
	return (_attackDamage);
}

void ClapTrap::setAttackDamage(unsigned int number)
{
	if (_hitPoints <= 0)
	{
		std::cout << "[ClapTrap] cant set attack damage to " << number << " because there is no hit points left." << std::endl;
		return ;
	}
	std::cout << "[ClapTrap] "<< _name <<" set attack damage to " << number << "." << std::endl;
	_attackDamage = number;
}
unsigned int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}