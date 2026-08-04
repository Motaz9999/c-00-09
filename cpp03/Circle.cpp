/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:57:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 16:00:57 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Circle.hpp"
#include <cmath>

Circle::Circle() : Shape("Circle"), _radius(1.0)
{
	_area = M_PI * pow(_radius, 2); // i can access area bc its protected
	std::cout << "Circle default constructor called." << std::endl;
}
Circle::Circle(double radius) : Shape("Circle"), _radius(radius)
{
	_area = M_PI * pow(_radius, 2); // i can access area bc its protected
	std::cout << "Circle constructor called with radius " << _radius << "." << std::endl;
}

Circle::~Circle()
{
    std::cout << "Circle destructor called." << std::endl;
}