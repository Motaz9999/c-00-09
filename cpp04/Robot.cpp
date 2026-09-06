/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Robot.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:22:10 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 22:30:42 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Robot.hpp"
#include <iostream>
Robot::Robot(const std::string & name):Animal(name) , _batteryLog(new int[100]) // array of 100 log
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