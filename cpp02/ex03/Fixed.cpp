/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:06:25 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/01 10:18:24 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// class Fixed
// {
//     public:
Fixed::Fixed() : _rawValue(0)
{
}

Fixed::Fixed(int const value) : _rawValue(value << _fractionalBits)
{
}
Fixed::Fixed(float const value) : _rawValue(static_cast<int>(roundf(value* (1 << _fractionalBits))))
{
}
// copy const
Fixed::Fixed(Fixed const &other) : _rawValue(other._rawValue)
{
}

// assign
Fixed &Fixed::operator=(Fixed const &other)
{
	if (this == &other) // same obj
	{
		return (*this);
	}
	this->_rawValue = other.getRawBits();
	return (*this); // chaining
}
Fixed::~Fixed()
{
}
int Fixed::getRawBits(void) const
{
	return (_rawValue);
}
void Fixed::setRawBits(int const raw)
{
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

bool Fixed::operator>(Fixed const &other) const
{
	return (this->_rawValue > other._rawValue);
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->_rawValue < other._rawValue);
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->_rawValue >= other._rawValue);
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->_rawValue <= other._rawValue);
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->_rawValue == other._rawValue);
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->_rawValue != other._rawValue);
}

Fixed Fixed::operator+(Fixed const &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(Fixed const &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

// here its like a special case so after we convert them to the original form we return them
Fixed Fixed::operator*(Fixed const &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(Fixed const &other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

//++obj
Fixed &Fixed::operator++()
{
	_rawValue++;
	return (*this);
} // return obj for chaining pFixed::readd
// obj++
Fixed Fixed::operator++(int)
{
	Fixed ret(*this);
	this->_rawValue++;
	return (ret);
} // garbage int post addFixed::
Fixed &Fixed::operator--()
{
	_rawValue--;
	return (*this);
} //
Fixed Fixed::operator--(int)
{
	Fixed ret(*this);
	this->_rawValue--;
	return (ret);
} //
// 	// next is min and max are static bc i want them to be part from this class not obj
// find which one is smaller than the other and return it
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}
// overload to take all
// same but with consts
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}
// overload to take all
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}
// overload to take all
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}