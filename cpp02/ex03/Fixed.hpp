/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:00:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/31 21:09:55 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>
class Fixed
{
  public:
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const &other);            // copy constructerr
	Fixed &operator=(Fixed const &other); // copy assignment
	~Fixed();                             // des
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	friend std::ostream &operator<<(std::ostream &os, Fixed const &obj);

	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	Fixed &operator++();   // return obj for chaining preadd
	Fixed operator++(int); // garbage int post add

	Fixed &operator--();   //
	Fixed operator--(int); //

	// max and min STATIC FUN
	static Fixed const &max(Fixed const &obj1, Fixed const &obj2);
	static Fixed &max(Fixed &obj1, Fixed &obj2);
	static Fixed const &min(Fixed const &obj1, Fixed const &obj2);
	static Fixed &min(Fixed &obj1, Fixed &obj2);

  private:
	int _rawValue;
	static const int _fractionalBits = 8;
};
#endif