/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   practice7.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 14:20:31 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/23 14:28:36 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Widget.hpp"

int	main(void)
{
	std::cout << "Widgets alive before any creation: " << Widget::getInstanceCount() << std::endl;
	std::cout << "\n-- Creating widgets --" << std::endl;
	Widget a1("Button");
	Widget a2("Slider");
	std::cout << "\nWidgets alive now: " << Widget::getInstanceCount() << std::endl;
	{
		std::cout << "\n-- Entering inner scope --" << std::endl;
		Widget a3("insider");
		std::cout << "Widgets alive now: " << Widget::getInstanceCount() << std::endl;
		std::cout << "-- Leaving inner scope --" << std::endl;
	}
	std::cout << "Widgets alive now: " << Widget::getInstanceCount() << std::endl;
    a1.printInfo();
    a2.printInfo();
    return 0;
}
