/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:06:25 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/31 17:52:54 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// class Fixed
// {
//     public:
Fixed::Fixed() : _rawValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _rawValue(value << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float const value) : _rawValue(value * (1 << _fractionalBits))
{
	std::cout << "Float constructor called" << std::endl;
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
	this->_rawValue = other.getRawBits();
	return (*this); // chaining
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawValue);
}
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawValue = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_rawValue))
		/ (static_cast<float>(1 << _fractionalBits));
}
int Fixed::toInt(void) const
{
	return (_rawValue >> _fractionalBits);
}

std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}
