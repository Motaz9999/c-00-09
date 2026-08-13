/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Car.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:11:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:45:55 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Car.hpp"

//   protected:
// 	int _doors;
Car::Car() : Vehicle(), _doors(4)
{
	std::cout << "[Car]       constructor called (doors=" << _doors << ")" << std::endl;
}
//   private:
//   public:
// 	Car();
// 	Car(const std::string &brand, int doors);
Car::Car(const std::string & brand , int doors):Vehicle(brand) , _doors(doors)
{
        std::cout << "[Car]       constructor called (doors=" << _doors << ")" << std::endl;
}
Car::~Car()
{
        std::cout << "[Car]       destructor called (doors=" << _doors << ")" << std::endl;
}
