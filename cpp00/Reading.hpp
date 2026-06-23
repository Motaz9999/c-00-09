/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reading.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:11:49 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 09:18:29 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_HPP
# define READING_CPP
# include <iostream>
# include <string>

class Reading
{
  public:
	Reading(double celsius, const std::string &location);
	double getCelsius(void) const;
	double getFahrenheit(void) const;
	std::string getLocation(void) const;
	void printSummary(void) const;

	void recordAccess(void);
	int getAccess(void) const;

  private:
	const double _celsius;
	const std::string _location;
	mutable int _accessCount;
};
#endif