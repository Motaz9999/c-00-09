/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 23:56:10 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/21 18:40:09 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
  private:
	std::string _name;

  protected:
  public:
	DiamondTrap();
	DiamondTrap(const std::string &name); // this is for the diamond class
	// for the clap const use name+"_clap_name"
	// for hitpoint use FragTrap + attack damage
	// for attack() and energy points use ScavTrap
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void attack(const std::string &target);
	//void takeDamage(unsigned int amount);
	//void beRepaired(unsigned int amount); // redefinition all these fun
	// btw also have unique fun
    using ClapTrap::takeDamage;
    using ClapTrap::beRepaired;
    void whoAmI()const ;//display the name and the clap name
};
#endif