/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Counter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 05:40:47 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/19 06:46:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COUNTER_HPP
# define COUNTER_HPP

# include <iostream>
class Counter
{
  public:
	// ocf
	Counter();
	explicit Counter(int value, int min = 0, int max = 10);
		// par constructor with  default  args
	// u can change these defaults if u insert value when calling the const
	~Counter();
	Counter(Counter const &other);            // copy const
	Counter &operator=(Counter const &other); // assign copy
	int getValue() const;

	// perfix and postfix operators
	// perfix modify then return the original obj
	Counter &operator++(); //++obj
	Counter &operator--(); //--obj
	// postfix save copy -> mod original
	///	->return saved copy by value  btw have dummy int
	Counter operator++(int); // obj++
	Counter operator--(int); // obj--
	// stream output so it can print the obj direct
	friend std::ostream& operator<<(std::ostream & output ,Counter const &obj);
    private:
    int _value;
    int _min;
    int _max;
};
#endif