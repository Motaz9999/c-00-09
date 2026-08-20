/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:53:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/20 19:57:09 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void	printSection(const std::string &title)
{
	std::cout << "\n==================== " << title << " ====================" << std::endl;
}
int	main(void)
{
	printSection("Test ofc and see if all works");
	{
		ScavTrap a;             // default const btw same is a()
		ScavTrap b("Guardian"); // par const
		ScavTrap bb(b);
		ScavTrap c("temp");
		c = b; // test assign
	}

	printSection("Test fun that are exists in ClapTrap and redefined in ScavTrap");
	{
		ScavTrap a("trap 1");
		a.attack("human 1");
		a.takeDamage(40);
		a.beRepaired(20);
		printSection("Test unique fun in ScavTrap");
		a.guardGate();
		printSection("test the functionality");
		a.takeDamage(200);
		a.attack("human 1");
		a.beRepaired(50);
		a.guardGate();
	}
	// now test the getters and setter that exists in claptrap
	printSection("Test setters and getters that exists");
	{
		ScavTrap a("trap 2");
		std::cout << "getters : AD:" << a.getAttackDamage() << " ,HP:" << a.getHitPoints() << std::endl;
		a.setAttackDamage(0);
		std::cout << " after Setter : AD:" << a.getAttackDamage() << " ,HP:" << a.getHitPoints() << std::endl;
	}
}