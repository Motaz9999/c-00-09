/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:53:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/21 18:35:02 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	printSection(const std::string &title)
{
	std::cout << "\n==================== " << title << " ====================" << std::endl;
}
int main()
{
    printSection("1. CONSTRUCTORS & ORTHODOX CANONICAL FORM");
    
    std::cout << "--- Default Constructor ---" << std::endl;
    DiamondTrap defaultDiamond;

    std::cout << "\n--- Parameterized Constructor ---" << std::endl;
    DiamondTrap namedDiamond("Goliath");

    std::cout << "\n--- Copy Constructor ---" << std::endl;
    DiamondTrap copiedDiamond(namedDiamond);

    std::cout << "\n--- Copy Assignment Operator ---" << std::endl;
    DiamondTrap assignedDiamond;
    assignedDiamond = namedDiamond;

    printSection("2. DIAMONDTRAP SPECIAL ABILITY (whoAmI)");
    
    defaultDiamond.whoAmI();
    namedDiamond.whoAmI();
    copiedDiamond.whoAmI();

    printSection("3. INHERITED ABILITIES (ScavTrap & FragTrap)");
    
    // Testing ScavTrap's special ability
    namedDiamond.guardGate();
    
    // Testing FragTrap's special ability
    namedDiamond.highFivesGuys();

    printSection("4. BASIC ACTIONS & ATTACK (ScavTrap's attack)");
    
    // Should display ScavTrap's attack message and consume energy
    namedDiamond.attack("Bandit");
    
    // Taking damage
    namedDiamond.takeDamage(30);
    
    // Repairing
    namedDiamond.beRepaired(20);

    printSection("5. EDGE CASES (Zero Hit Points / Energy)");
    
    // Inflicting massive damage to deplete hit points
    namedDiamond.takeDamage(150); 
    
    // These actions should fail and display appropriate messages
    namedDiamond.attack("Another Bandit"); 
    namedDiamond.beRepaired(50);
    
    // whoAmI should still work even if the robot is "dead"
    namedDiamond.whoAmI();

    printSection("6. DESTRUCTORS");
    // Destructors will be called automatically in reverse order of creation
    
    return (0);
}