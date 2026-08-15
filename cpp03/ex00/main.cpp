/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 17:53:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/15 18:40:08 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//a attack b
// void attacking(ClapTrap &a , ClapTrap &b)
// {
//     a.attack(b.getName());
//     b.takeDamage(a.getAttackDamage());
// }


// int main()
// {
//     ClapTrap a("robo a");
//     ClapTrap b("robo b");
//     //now 
//     attacking(a , b);
//     a.setAttackDamage(2);
//     attacking(a,b);
//     a.setAttackDamage(10);
//     attacking(a,b);
//         attacking(a,b);
//     b.beRepaired(10);
//         attacking(a,b);
//     a.beRepaired(10);
//     b.setAttackDamage(10);
//     attacking(b , a);
//     return 0;
// }
void printSection(const std::string& title) {
    std::cout << "\n==================== " << title << " ====================" << std::endl;
}
int main() {
    printSection("1. Construction & OCF Tests");
    ClapTrap defaultBot;
    ClapTrap alpha("Alpha");
    ClapTrap copyAlpha(alpha); // Copy constructor
    ClapTrap assignedBot;
    assignedBot = alpha;      // Copy assignment operator

    printSection("2. Basic Attack & Damage Test");
    alpha.setAttackDamage(3);
    alpha.attack("TargetDummy");
    
    ClapTrap beta("Beta");
    beta.takeDamage(3);

    printSection("3. Repair Test");
    beta.beRepaired(5);

    printSection("4. Energy Points Depletion Test (10 Actions)");
    ClapTrap spammer("Spammer");
    for (int i = 1; i <= 10; i++) {
        std::cout << "[" << i << "] ";
        spammer.attack("TargetDummy");
    }
    std::cout << "--- Attempting actions with 0 Energy ---" << std::endl;
    spammer.attack("TargetDummy");
    spammer.beRepaired(5);

    printSection("5. Hit Points Depletion / Death Test");
    ClapTrap victim("Victim");
    victim.takeDamage(5); 
    victim.takeDamage(20); 
    
    std::cout << "--- Attempting damage on dead ClapTrap ---" << std::endl;
    victim.takeDamage(10);

    std::cout << "--- Attempting actions on dead ClapTrap ---" << std::endl;
    victim.attack("TargetDummy");
    victim.beRepaired(10);

    printSection("6. Destructors");
    return 0;
}