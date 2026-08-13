/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SportsCar.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 21:48:39 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/13 21:51:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SportsCar.hpp"

//   private:
// 	int _topSpeed;

//   public:
// 	SportsCar();
SportsCar::SportsCar() : Car(), _topSpeed(180)
{
	std::cout << "[SportsCar] constructor called (topSpeed=" << _topSpeed << ")" << std::endl;
}
// 	SportsCar(const std::string &brand, int doors, int topSpeed);
SportsCar::SportsCar(const std::string &brand, int doors, int topSpeed) :Car(brand , doors) , _topSpeed(topSpeed)
{
	    std::cout << "[SportsCar] constructor called (topSpeed=" << _topSpeed << ")" << std::endl;
}
// 	~SportsCar();
SportsCar::~SportsCar()
{
    std::cout << "[SportsCar] destructor called (topSpeed=" << _topSpeed << ")" << std::endl;
}