/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlyingFish.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:20:44 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:22:45 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlyingFish.hpp"

FlyingFish::FlyingFish(std::string const &name): Bird(name) , Fish(name)
{
        std::cout << "FlyingFish constructor called." << std::endl;

}
FlyingFish::~FlyingFish()
{
    std::cout << "FlyingFish destructor called." << std::endl;
}
void FlyingFish::move()const
{
        std::cout << Bird::_name << " glides above the waves, then dives back in." << std::endl;
        Bird::move();
        Fish::move();
}