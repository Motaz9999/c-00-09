/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reading.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 09:11:17 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 09:41:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Reading.hpp"

//   public:
// 	Reading(double celsius, const std::string &location);
// 	double getCelsius(void) const;
// 	double getFahrenheit(void) const;
// 	std::string getLocation(void) const;
// 	void printSummary(void) const;

// 	void recordAccess(void);
// 	int getAccess(void) const;

//   private:
// 	const double _celsius;
// 	const std::string _location;
// 	mutable int _accessCount;

Reading::Reading(double celsius,const std::string &location) : _celsius(celsius), _location(location)
{
    std::cout << "READING recorded :" << this->_celsius << "°C at" << this->_location << std::endl;
}
double Reading::getCelsius(void) const
{
    this->_accessCount++;
    return this->_celsius;
}

double Reading::getFahrenheit(void) const
{
    this->_accessCount++;
    
    return (this->_celsius * ( 9.0/5.0)) + 32.0;
}

std::string Reading::getLocation(void) const
{
    this->_accessCount++;
    return this->_location;
}
void Reading::printSummary(void) const
{
    std :: cout << "[" << this->getLocation() << "] "
              << this->getCelsius()    << "°C / "
              << this->getFahrenheit() << "°F" << std::endl;
}

void Reading::recordAccess(void)
{
    this->_accessCount++;
    std::cout << "Manual access recorded." << std::endl;
}

int Reading::getAccess(void) const
{
    return this->_accessCount;
}