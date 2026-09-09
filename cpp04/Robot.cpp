/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:22:10 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/09 19:26:42 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Robot.hpp"
#include <iostream>
#include <sstream>

Robot::Robot(const std::string & name):AAnimal(name) , _batteryLog(new int[100]) // array of 100 log
{
    std::cout << "[Robot] parameterized constructor -> " << _name
	          << " (allocated battery log)" << std::endl;
}
Robot::~Robot()
{
	std::cout << "[Robot] destructor -> " << _name
	          << " (freeing battery log)" << std::endl;
	delete[] _batteryLog;
}
void Robot::makeSound() const
{
	std::cout << _name << " says: Beep boop." << std::endl;
}

std::string  Robot::serialize() const
{
	std::stringstream oss;
	oss << "{ \"type\": \"Cat\", \"name\": \"" << _name << "\" }";
	return oss.str();
}