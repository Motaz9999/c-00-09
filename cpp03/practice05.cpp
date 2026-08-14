/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice05.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:26:49 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:59:21 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Amphibious.hpp"

int main()
{
    std::cout << "--- Constructing an Amphibious animal ---" << std::endl;
    Amphibious frog("Frog");
    std::cout << "\n--- Using inherited behavior ---" << std::endl;
    frog.walk();
    frog.swim();
    // Only ONE Animal subobject exists thanks to virtual inheritance,
    // so this call is unambiguous - it would NOT compile without 'virtual'
    // on WalkingAnimal's and SwimmingAnimal's inheritance from Animal.
    std::cout << frog.getName() << " is fully amphibious." << std::endl;
    std::cout << "\n--- End of scope ---" << std::endl;
    return (0);
}