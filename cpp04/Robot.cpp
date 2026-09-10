/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:22:10 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/10 18:16:48 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Robot.hpp"
#include <iostream>
#include <sstream>

Robot::Robot(const std::string &name) : AAnimal(name), _batteryLog(new int[100])
	// array of 100 log
{
	std::cout << "[Robot] parameterized constructor-> " << _name << " (allocated battery log)" << std::endl;
}
Robot::~Robot()
{
	std::cout << "[Robot] destructor-> " << _name << " (freeing battery log)" << std::endl;
	delete[] _batteryLog;
}
void Robot::makeSound() const
{
	std::cout << _name << " says: Beep boop." << std::endl;
}

std::string Robot::serialize() const
{
	std::stringstream oss;
	oss << "{ \"type\": \"Cat\", \"name\": \"" << _name << "\" }";
	return (oss.str());
}

// copy constructor
Robot::Robot(const Robot &obj) : AAnimal(obj)
{
	std::cout << "[Robot] copy constructor-> " << _name << " (deep-copying battery log)" << std::endl;
	this->_batteryLog = new int[100];
	for (int i = 0; i < 100; i++)
	{
		this->_batteryLog[i] = obj._batteryLog[i];
	}
}
// assign
Robot &Robot::operator=(const Robot &obj)
{
	std::cout << "[Robot] copy assignment -> " << obj._name << std::endl;
	if (this == &obj)
	{
		return (*this);
	}
	AAnimal::operator=(obj);
	delete this->_batteryLog;
	this->_batteryLog = new int[100];
	for (int i = 0; i < 100; i++)
	{
		this->_batteryLog[i] = obj._batteryLog[i];
	}
	return (*this);
}

AAnimal *Robot::clone() const
{
	return new Robot(*this);
}
