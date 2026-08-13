/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vehicle.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:06:33 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:08:43 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vehicle.hpp"

Vehicle::Vehicle() : _brand("Unknown")
{
	std::cout << "[Vehicle]   constructor called (brand=" << _brand << ")" << std::endl;
}
Vehicle::Vehicle(std::string const &brand) : _brand(brand)
{
	std::cout << "[Vehicle]   constructor called (brand=" << _brand << ")" << std::endl;
}

Vehicle::~Vehicle()
{
    std::cout << "[Vehicle]   destructor called (brand=" << _brand << ")" << std::endl;
}
