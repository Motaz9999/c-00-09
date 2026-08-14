/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogV2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:44:58 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 15:47:25 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogV2.hpp"

DogV2::DogV2(const std::string &name) : AnimalV2(name)
{
	std::cout << "Dog constructor called for " << _name << "." << std::endl;
}
DogV2::~DogV2()
{
	std::cout << "Dog destructor called." << std::endl;
}
void DogV2::makeSound() const
{
	std::cout << _name << " barks: Woof! Woof!" << std::endl;
	AnimalV2::makeSound();
}