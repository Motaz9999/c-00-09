/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice02.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 22:24:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 23:09:14 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Robot.hpp"
#include <iostream>

// int main()
// {
// 	Animal* p = new Robot("R2D2");
// 	delete p;   // Animal's destructor is non-virtual -> only ~Animal() runs
// 	return (0);
// }
void	demoFixedRobot(void)
{
	Animal	*p;
	

	std::cout << "=== Demo 1: The Fixed Robot Leak ===" << std::endl;
	std::cout << std::endl;
	p = new Robot("R2D2");
    delete	p;
	std::cout << std::endl;
    
}
void	demoFullZoo(void)
{
	Animal	*zoo[4];

	std::cout << "=== Demo 2: The Full Zoo — Safe Heap Cleanup ===" << std::endl;
	std::cout << std::endl;
    zoo[0] = new Dog("Buddy");
	zoo[1] = new Cat("Luna");
	zoo[2] = new Robot("R2D2");
	zoo[3] = new Animal("Generic Beast");
    
    for (int i = 0; i < 4; i++)
		zoo[i]->makeSound();

	std::cout << std::endl;

    
	for (int i = 0; i < 4; i++)
		delete zoo[i];

        
	std::cout << std::endl;
}
int	main(void)
{
	demoFixedRobot();
	demoFullZoo();

	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}