/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice00.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:27:46 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 14:28:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

int main()
{
    std::cout << "--- Creating a Dog ---" << std::endl;
    Dog rex("Rex", "German Shepherd");

    std::cout << "\n--- Inherited and own members ---" << std::endl;
    std::cout << rex.getName() << " is a " << rex.getBreed() << "." << std::endl;

    std::cout << "\n--- End of scope, destruction begins ---" << std::endl;
    return (0);
}