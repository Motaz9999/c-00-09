/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:35:40 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 18:43:51 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string const &type)
{
	if (type.empty())
	{
		std::cerr << "Error in type " << std::endl;
		this->type = "Unknown weapon";
		return ;
	}
	this->type = type;
}
void Weapon::setType(std::string const &type)
{
	if (type.empty())
	{
		std::cerr << "Error in type " << std::endl;
		this->type = "Unknown weapon";
		return ;
	}
	this->type = type;
}

// this fun work as set and get in the same time
std::string const &Weapon::getType() const
{
	return (this->type);
}
