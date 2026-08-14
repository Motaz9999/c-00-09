/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwimmingAnimal.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:42:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:45:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SwimmingAnimal.hpp"

// SwimmingAnimal(const std::string &name);
SwimmingAnimal::SwimmingAnimal(const std::string &name) : Animal(name)
{
	std::cout << "[SwimmingAnimal] constructor called" << std::endl;
}
// ~SwimmingAnimal();
SwimmingAnimal::~SwimmingAnimal()
{
	std::cout << "[SwimmingAnimal] destructor called" << std::endl;
}
// void swim() const;
void SwimmingAnimal::swim() const
{
	std::cout << _name << " swims gracefully." << std::endl;
}