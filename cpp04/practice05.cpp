
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice05.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/09 22:32:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/09 22:36:38 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>

// class Base
// {
//   public:
// 	Base()
// 	{
// 	}
// 	virtual ~Base()
// 	{
// 	}
// 	virtual void identify() const
// 	{
// 		std::cout << "I am a Base object." << std::endl;
// 	}
// };

// class Derived : public Base
// {
//   private:
// 	int _extra;

//   public:
// 	Derived() : _extra(42)
// 	{
// 		std::cout << "I am a Derived object, extra = " << _extra << std::endl;
// 	}
// 	virtual void identify() const
// 	{
// 		std::cout << "I am a Derived object, extra = " << _extra << std::endl;
// 	}
// };

// int	main(void)
// {
// 	Derived d;
// 	std::cout << "--- Calling through a reference (no slicing) ---" << std::endl;
// 	Base &b = d;
// 	b.identify();
// 	std::cout << "\n--- Copying BY VALUE into a Base (slicing occurs) ---" << std::endl;
// 	Base sliced = d;
// 	sliced.identify();
// }

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Robot.hpp"
#include <iostream>

void	demoCloneArray(void)
{
	AAnimal	*originals[3];


	std::cout << "=== Demo: Polymorphic Cloning ===" << std::endl;
	std::cout << "\n--- Building originals ---" << std::endl;
	originals[0] = new Dog("Buddy");
	originals[1] = new Cat("Luna");
	originals[2] = new Robot("R2D2");
	std::cout << "\n--- Cloning through AAnimal*, no concrete type named ---" << std::endl;
		AAnimal	*clones[3];
	for (int i = 0; i < 3; i++)
		clones[i] = originals[i]->clone();

	std::cout << "\n--- Proving each clone kept its real (dynamic) type ---" << std::endl;

for (int i = 0; i < 3; i++)
	{
		std::cout << "  original[" << i << "] address = " << originals[i] << " | ";
		originals[i]->makeSound();
		std::cout << "  clone[" << i << "]    address = " << clones[i] << " | ";
		clones[i]->makeSound();
	}

std::cout << "\n--- Cleaning up both arrays independently ---" << std::endl;
	for (int i = 0; i < 3; i++)
		delete originals[i];
	for (int i = 0; i < 3; i++)
		delete clones[i];
	std::cout << std::endl;
}

int	main(void)
{
	demoCloneArray();
	std::cout << "=== Demo complete. ===" << std::endl;
	return (0);
}