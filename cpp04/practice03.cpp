/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 18:11:46 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/07 20:36:39 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// #include "AAnimal.hpp"

// int main()
// {
// 	AAnimal a("Generic Beast");   // ERROR: AAnimal is abstract
// 	(void)a;
// 	return (0);
// }

// #include "Fish.hpp"

// int main()
// {
// 	Fish nemo("Nemo");   // ERROR: Fish is still abstract
// 	(void)nemo;
// 	return (0);
// }
#include "Cat.hpp"
#include "Dog.hpp"
#include "Robot.hpp"
#include <iostream>

void	demoConcreteZoo(void)
{
	std::cout << "=== Demo: Only Concrete Classes Need Apply ===" << std::endl;
	std::cout << std::endl;
    AAnimal *zoo[3];
    zoo[0] = new Dog("buddy");
    zoo[1] = new Cat("luna");
    zoo[2] = new Robot("R2D2");
    
	for (int i = 0; i < 3; i++)
		zoo[i]->makeSound();

	std::cout << std::endl;
    
	for (int i = 0; i < 3; i++)
		delete zoo[i];
        
	std::cout << std::endl;
    
}
int	main(void)
{
	demoConcreteZoo();
	std::cout << "=== Demo complete. ===" << std::endl;
	return (0);
}