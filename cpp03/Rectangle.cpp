/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rectangle.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:02:45 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 16:03:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rectangle.hpp"

Rectangle::Rectangle() : Shape("Rectangle"), _width(1.0), _height(1.0)
{
	_area = _width * _height;
	std::cout << "Rectangle default constructor called." << std::endl;
}

Rectangle::Rectangle(double width, double height) : Shape("Rectangle"),
	_width(width), _height(height)
{
	_area = _width * _height;
	std::cout << "Rectangle constructor called with width " << _width << " and height " << _height << "." << std::endl;
}

Rectangle::~Rectangle()
{
	std::cout << "Rectangle destructor called." << std::endl;
}