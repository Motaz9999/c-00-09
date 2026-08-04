/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice01.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 16:03:15 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 16:03:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rectangle.hpp"
#include "Circle.hpp"

int main()
{
    std::cout << "--- Creating shapes ---" << std::endl;
    Circle    c(4.0);
    Rectangle r(3.0, 5.0);

    std::cout << "\n--- Direct protected access from derived classes ---" << std::endl;
    c.printInfo();
    r.printInfo();

    // The line below would NOT compile if attempted here in main():
    // c._area = 100.0; // ERROR: '_area' is protected within this context
    // Only Shape and classes derived from Shape may touch _area directly.

    std::cout << "\n--- End of scope ---" << std::endl;
    return (0);
}