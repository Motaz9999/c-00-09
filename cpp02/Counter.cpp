/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Counter.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 05:57:33 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/19 06:46:50 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Counter.hpp"

// class Counter
// {
//   public:
// 	Counter();
Counter::Counter() : _value(0), _min(0), _max(0)
{
	std::cout << "[Counter] Default constructor: " << *this << std::endl;
}
// 	explicit Counter(int value, int min = 0, int max = 10);
Counter::Counter(int value, int min, int max) : _value(value), _min(min),
	_max(max)
{
	std::cout << "[Counter] Parameterized constructor: " << *this << std::endl;
}
// 	~Counter();
Counter::~Counter()
{
	std::cout << "[Counter] Destructor: " << *this << std::endl;
}
// 	Counter(Counter const &other);            // copy const
Counter::Counter(Counter const &other) : _value(other._value), _min(other._min),
	_max(other._max)
{
	std::cout << "[Counter] Copy constructor: " << *this << std::endl;
}
// 	Counter &operator=(Counter const &other); // assign copy
Counter &Counter::operator=(Counter const &other)
{
	std::cout << "[Counter] Copy assignment" << std::endl;
	if (&other == this)
	{
		return (*this);
	}
	_value = other._value;
	_min = other._min;
	_max = other._max;
	return (*this);
}

// 	int getValue() const;
int Counter::getValue() const
{
	return (_value);
}
// prefix

// 	Counter &operator++(); //++obj
// so what i want to pre increment?
// increment _value ; if it exceeds _max , warp to _min.
// return *this by ref - the modded obj
// NO copy is made here the res of ++obj is obj
Counter &Counter::operator++()
{
	std::cout << "[Counter] Prefix ++: " << _value;
	_value = (_value >= _max) ? _min : _value + 1;
	std::cout << " → " << _value << std::endl;
	return (*this);
}
// 	Counter &operator--(); //--obj
Counter &Counter::operator--()
{
	std::cout << "[Counter] Prefix --: " << _value;
	_value = (_min >= _value) ? _min : _value - 1;
	return (*this);
}
// 	Counter operator++(int); // obj++
Counter Counter::operator--(int)
{
	std::cout << "[Counter] Postfix  --: " << _value;
	Counter save(*this);
	--(*this);
	std::cout << "         postfix --: now " << _value << ",returning saved " << save._value << std::endl;
	return (save);
}
// 	Counter operator--(int); // obj--
Counter Counter::operator++(int)
{
	std::cout << "[Counter] Postfix  ++: " << _value;
	Counter save(*this);
	++(*this);
	std::cout << "         postfix ++: now " << _value << ",returning saved " << save._value << std::endl;
	return (save);
}
std::ostream &operator<<(std::ostream  &output, Counter const &obj)
{
	output << "Counter(" << obj._value<< " [" << obj._min << ".." << obj._max << "])";
	return output;
}
//     private:
//     int _value;
//     int _min;
//     int _max;
// };