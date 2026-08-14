/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fish.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:14:56 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:15:04 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fish.hpp"

Fish::Fish(const std::string &name) : _name(name)
{
	std::cout << "Fish constructor called for " << _name << "." << std::endl;
}

Fish::~Fish()
{
	std::cout << "Fish destructor called for " << _name << "." << std::endl;
}

void Fish::move() const
{
	std::cout << _name << " swims through the water." << std::endl;
}