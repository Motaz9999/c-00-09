/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice01.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 21:04:33 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 21:09:52 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Snake.hpp"
#include <iostream>

void	demoFixedArray(void)
{
	std::cout << "=== Demo 1: The Fixed Animal Array ===" << std::endl;
    Animal generic("Generic Beast");
	Dog buddy("Buddy");
	Cat luna("Luna");
    Animal *zoo[3] = {&generic , &buddy , &luna};
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        zoo[i]->makeSound();
    }
    std::cout << std::endl;
    
}

void demoCorrectOverride()
{
   	std::cout << "=== Demo 2: Snake — A Correct Override ===" << std::endl;

	Snake kaa("Kaa");
     	std::cout << "\n  Direct call: kaa.makeSound()" << std::endl;
    kaa.makeSound();
    
	std::cout << "\n  Polymorphic call: Animal* p = &kaa; p->makeSound();" << std::endl;
    Animal* p = &kaa;
    p->makeSound();//snake sound
    	std::cout << std::endl;

}

int	main(void)
{
	demoFixedArray();
	demoCorrectOverride();

	std::cout << "=== All demos complete. ===" << std::endl;
	return (0);
}