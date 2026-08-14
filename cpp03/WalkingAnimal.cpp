/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WalkingAnimal.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:23:06 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:30:36 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WalkingAnimal.hpp"

WalkingAnimal::WalkingAnimal(const std::string &name) : Animal(name)
{
	std::cout << "[WalkingAnimal]  constructor called" << std::endl;
}
WalkingAnimal::~WalkingAnimal()
{
	std::cout << "[WalkingAnimal]  destructor called" << std::endl;
}
void WalkingAnimal::walk() const
{
	std::cout << _name << " walks on four legs." << std::endl;
}
