/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 05:41:06 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/27 07:57:31 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "[Fixed] Default constructor: 0" << std::endl;
}
// here we convert the value into rawbits using left shifting its like *256
// Fixed(3)  → _rawBits = 3 * 256 = 768  → toFloat() = 768/256 = 3.0
Fixed::Fixed(int const value) : _rawBits(value << _fractionalBits)
{
	std::cout << "[Fixed] Int constructor: " << value << " → rawBits=" << _rawBits << std::endl;
}
//// Fixed(1.5f) → _rawBits = roundf(1.5 * 256) = roundf(384.0) = 384
//             → toFloat() = 384/256 = 1.5
// Fixed(0.1f) → _rawBits = roundf(0.1 * 256) = roundf(25.6) = 26
//             → toFloat() = 26/256 ≈ 0.10156 (nearest representable value) FIXED
Fixed::Fixed(float const value) : _rawBits(static_cast<int>(roundf(value
			* (1 << _fractionalBits))))
{
	std::cout << "[Fixed] Float constructor: " << value << " → rawBits=" << _rawBits << std::endl;
}
// 	// ocf
// 	// copy constructor
Fixed::Fixed(Fixed const &other) : _rawBits(other._rawBits)
{
	std::cout << "[Fixed] Copy constructor: " << toFloat() << std::endl;
}

// assign operator
Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "[Fixed] Copy assignment: " << other.toFloat() << std::endl;
	if (this == &other)
	{
		return (*this);
	}
	_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "[Fixed] Destructor: " << toFloat() << std::endl;
}
// 	// additional setter and getter if it required

int Fixed::getRawBits(void) const
{
	return (_rawBits);
}
void Fixed::setRawBits(int const newRaw)
{
	_rawBits = newRaw;
}

// To int: divide by 256 (right shift — truncates toward zero, not rounds).
// Fixed with rawBits=768 → 768 >> 8 = 3
// Fixed with rawBits=384 → 384 >> 8 = 1 (1.5 truncated to 1)
// any bits before the 2^8 truncates to 0
// right shifting so its like Rawbits/256 = real value as int
int Fixed::toInt() const
{
	return (_rawBits >> _fractionalBits);
}
// same here use casting
float Fixed::toFloat() const
{
	return (static_cast<float>(_rawBits)
		/ static_cast<float>(1 << _fractionalBits));
}
// 	//++ -- max min must be here
// 	// for ++ -- there is prefix and postfix
// 	// prefix add then return the original obj

// here we start with perfix (adding and using in the same line)

Fixed &Fixed::operator++()
{
	++_rawBits; // add 1
	return (*this);
}
Fixed &Fixed::operator--()
{
	--_rawBits;
	return (*this);
}

// here we need new obj
Fixed Fixed::operator++(int)
{
	Fixed old(*this);
	++_rawBits;
	return (old);
}

Fixed Fixed::operator--(int)
{
	Fixed old(*this);
	--_rawBits;
	return (old);
}

// 	// next is min and max are static bc i want them to be part from this class not obj
// find which one is smaller than the other and return it
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}
// overload to take all
// same but with consts
Fixed const&Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}
// overload to take all
Fixed const& Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}
// overload to take all
Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}
// 		// overload to take all

// 	// friend  here bc its easier to get to private data to print it
std::ostream &operator<<(std::ostream &os, Fixed const &obj)
{
	os << obj.toFloat();
	return (os);
}

// //+-*/ > < == != <= >=
// // now are the + - * /
Fixed operator+(Fixed const&a, Fixed const&b)
{
	Fixed	res;

	res.setRawBits(a.getRawBits() + b.getRawBits());
	return (res);
}
Fixed operator-(Fixed const&a, Fixed const&b)
{
	Fixed	res;

	res.setRawBits(a.getRawBits() - b.getRawBits());
	return (res);
}

int Fixed::getFractionalBits(void)
{
	return (_fractionalBits); // أو Fixed::_fractionalBits
}

// ok both rawBits is *256 so now there is 2 256 and this wrong if we a*b  so at least we need to move 1 by right shifting a or b  i prefer b
// (a * b) = (a_raw/256) * (b_raw/256) = (a_raw * b_raw) / 65536
// To get the result in Q24.8 scale: multiply by 256 = (a_raw * b_raw) / 256
// result._rawBits = (a_raw * b_raw) >> 8  ✓
Fixed operator*(Fixed const&a, Fixed const&b)  
{
	Fixed	res;

	res.setRawBits((a.getRawBits()
			* b.getRawBits()) >> Fixed::getFractionalBits());
	return (res);
}
// Division: (a / b) in actual value = (a_raw/256) / (b_raw/256) = a_raw / b_raw
// here if 256/256 now there is now 256 so we left shifting by 8 so i left shifting one so there is only 1 256 remain
// But result._rawBits must be in Q24.8 scale = actual_result * 256
// result._rawBits = (a_raw / b_raw) * 256 = (a_raw << 8) / b_raw  ✓
Fixed operator/(Fixed const&a, Fixed const&b)
{
	Fixed	res;

	res.setRawBits((a.getRawBits() << Fixed::getFractionalBits())
		/ b.getRawBits());
	return (res);
}
// and s comparison ops
// here we compar between rawBits ONLY

bool operator>(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() > b.getRawBits());
}

bool operator==(Fixed const &a, Fixed const &b)
{
	return (a.getRawBits() == b.getRawBits());
}

bool operator<(Fixed const &a, Fixed const &b)
{
	return (b > a);
}

bool operator!=(Fixed const &a, Fixed const &b)
{
	return (!(a == b));
}

bool operator>=(Fixed const &a, Fixed const &b)
{
	return (!(a < b));
}

bool operator<=(Fixed const &a, Fixed const &b)
{
	return (!(a > b));
}