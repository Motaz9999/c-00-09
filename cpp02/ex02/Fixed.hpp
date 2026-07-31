/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 13:00:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/31 17:39:04 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

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
    friend std::ostream& operator<<(std::ostream &os , Fixed const& obj);
    
  private:
	int _rawValue;
	static const int _fractionalBits = 8;
};
#endif