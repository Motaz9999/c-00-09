/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 19:19:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 19:36:17 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// HumanB(std::string const &name);
// void attack() const;
// void setWeapon(Weapon const& a);
HumanB::HumanB(std::string const &name)
{
	if (name.empty())
		this->name = "unknown name";
	else
		this->name = name;
	this->a = NULL;
}
//<name> attacks with their <weapon type>
void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->a->getType() <<std::endl;
}

void	HumanB::setWeapon(Weapon &a)
{
	this->a = &a;
}