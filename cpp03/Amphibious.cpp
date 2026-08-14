/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amphibious.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:49:39 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:57:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Amphibious.hpp"

// Amphibious(const std::string &name);
Amphibious::Amphibious(const std::string &name) :Animal(name) , WalkingAnimal(name) , SwimmingAnimal(name)
{
    std::cout << "[Amphibious]     constructor called" << std::endl;
}
Amphibious::~Amphibious()
{
	std::cout << "[Amphibious]     destructor called" << std::endl;
}