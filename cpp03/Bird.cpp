/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bird.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:13:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:14:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bird.hpp"

Bird::Bird(const std::string &name) : _name(name)
{
	std::cout << "Bird constructor called for " << _name << "." << std::endl;
}

Bird::~Bird()
{
	std::cout << "Bird destructor called for " << _name << "." << std::endl;
}

void Bird::move() const
{
	std::cout << _name << " flies through the air." << std::endl;
}