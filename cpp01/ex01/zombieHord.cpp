/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHord.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:16:14 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 16:48:17 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>
#include <sstream>

Zombie	*zombieHorde(int N, std::string name)
{
	std::stringstream ss;
	if (N <= 0)
	{
        std::cerr << "Error in size of the array " << std::endl;
		return (NULL);
	}
	Zombie *array_of_zombies = new (std::nothrow) Zombie[N];
	if (array_of_zombies == NULL)
	{
		std::cerr << "Error in new for the array " << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
        ss.str("");
        ss.clear();
		ss << i;
		array_of_zombies[i].setName(name + ss.str());
	}
	return (array_of_zombies);
}