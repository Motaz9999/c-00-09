/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalV2.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:36:47 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 15:41:42 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AnimalV2.hpp"

//   protected:
// 	std::string _name;

//   public:
// 	AnimalV2(std::string const &name);
AnimalV2::AnimalV2(std::string const &name) : _name(name)
{
	std::cout << "Animal constructor called for " << _name << "." << std::endl;
}
// 	~AnimalV2();
AnimalV2::~AnimalV2()
{
	std::cout << "Animal destructor called for " << _name << "." << std::endl;
}

//     void makeSound() const;
void AnimalV2::makeSound() const
{
	std::cout << _name << " makes a generic animal sound." << std::endl;
}
//     void makeSound(int times) const;
void AnimalV2::makeSound(int times) const
{
	for (int i = 0; i < times; ++i)
		std::cout << _name << " makes a generic animal sound." << std::endl;
}