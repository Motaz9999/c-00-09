/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice04.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 19:26:58 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/09 19:43:31 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "ISerializable.hpp"
#include "Robot.hpp"
#include <iostream>

//the use case of poly
void printSerialized(const ISerializable &obj)
{
    	std::cout << "  " <<obj.serialize() << std::endl;
}
void demoInterface()
{
	std::cout << "=== Demo: ISerializable, Independent of AAnimal ===" << std::endl;
	std::cout << std::endl;
	Dog buddy("Buddy");
	Robot r2d2("R2D2");
	std::cout << "\n  Direct calls to serialize():" << std::endl;

	std::cout << "  " << buddy.serialize() << std::endl;
    	std::cout << "  " << r2d2.serialize() << std::endl; 
	std::cout << "\n  Through printSerialized(ISerializable const&):" << std::endl;
    printSerialized(buddy);
    printSerialized(r2d2);

    std::cout << "\n  Both objects still behave as AAnimal too:" << std::endl;
	buddy.makeSound();
	r2d2.makeSound();
	std::cout << std::endl;
    
}

int	main(void)
{
	demoInterface();
	std::cout << "=== Demo complete. ===" << std::endl;
	return (0);
}