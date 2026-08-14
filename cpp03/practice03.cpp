/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice03.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:47:53 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 15:54:48 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DogV2.hpp"

int main()
{
    std::cout << "--- Creating a Dog ---" << std::endl;
    DogV2 rex("Rex");

    std::cout << "\n--- Calling makeSound() directly on the Dog object ---" << std::endl;
    rex.makeSound();//calls animal and dog makeSound

    std::cout << "\n--- Explicitly calling the hidden Animal overload ---" << std::endl;
    rex.AnimalV2::makeSound(2);//call animal make sound twice

    // rex.makeSound(2); would NOT compile here:
    // Dog::makeSound() (no args) hides ALL Animal::makeSound overloads,
    // including makeSound(int). Name hiding, not overload resolution,
    // governs unqualified lookup in Dog's scope.

    std::cout << "\n--- Non-virtual dispatch through a base pointer/reference ---" << std::endl;
    AnimalV2* animalPtr = &rex;//use the parent scope fun even if the obj of type son 
    animalPtr->makeSound();

    AnimalV2& animalRef = rex;//same for ref 
    animalRef.makeSound();

    std::cout << "\n--- End of scope ---" << std::endl;
    return (0);
}
