/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:27:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/20 17:43:10 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
  private:   // special to this class
  protected: // can be used in this class and childs
  public:    // ocf:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &other);
	ScavTrap &operator=(const ScavTrap &other);
	~ScavTrap();
	// not override put its redefinition  or name hideing
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);//redefinition all these fun
    //btw also have unique fun
    void guardGate();
    //all setters and getters is for same parent values // in child u dont have to use setters bc u have direct access to parent elements
    
};
#endif