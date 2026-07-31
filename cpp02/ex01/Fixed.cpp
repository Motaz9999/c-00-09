/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:06:25 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/31 13:42:46 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// class Fixed
// {
//     public:
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
// copy const
Fixed::Fixed(Fixed const &other) : _rawValue(other._rawValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

// assign
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) // same obj
	{
		return (*this);
	}
	this->_rawValue = other._rawValue;
	return (*this); // chaining
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void)
{
	return (_rawValue);
}
void Fixed::setRawBits(int const raw)
{
    this->_rawValue = raw;
}
//     private:
//     int _rawValue;
//     static const int _fractionalBits = 8 ;
// };