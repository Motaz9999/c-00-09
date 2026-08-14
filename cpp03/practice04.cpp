/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice04.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:23:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:23:04 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FlyingFish.hpp"

int main()
{
    std::cout << "--- Creating a FlyingFish ---" << std::endl;
    FlyingFish exocet("Exocet");

    std::cout << "\n--- Calling move() (resolved by FlyingFish's own redefinition) ---" << std::endl;
    exocet.move();

    // If FlyingFish did NOT redefine move(), the line above would fail:
    //   error: request for member 'move' is ambiguous
    // because both Bird::move() and Fish::move() are equally viable
    // candidates and neither is preferred over the other.

    std::cout << "\n--- End of scope ---" << std::endl;
    return (0);
}