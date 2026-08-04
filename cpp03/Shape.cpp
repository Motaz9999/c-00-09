/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shape.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 15:55:29 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 15:55:30 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shape.hpp"

Shape::Shape() : _name("Unknown Shape"), _area(0.0)
{
    std::cout << "Shape default constructor called." << std::endl;
}

Shape::Shape(const std::string& name) : _name(name), _area(0.0)
{
    std::cout << "Shape constructor called for " << _name << "." << std::endl;
}

Shape::~Shape()
{
    std::cout << "Shape destructor called for " << _name << "." << std::endl;
}

double Shape::getArea() const
{
    return _area;
}

std::string Shape::getName() const
{
    return _name;
}

void Shape::printInfo() const
{
    std::cout << _name << " has an area of " << _area << "." << std::endl;
}