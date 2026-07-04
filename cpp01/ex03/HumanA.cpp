/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:41:34 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 19:35:31 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
HumanA::HumanA(std::string const &name, Weapon   &b) : a(b)
{
    if (name.empty())
        this->name = "unknown name";
    else
    this->name = name;
}

//<name> attacks with their <weapon type>
void HumanA::attack(void) const 
{
    std::cout << this->name << " attacks with their " << this->a.getType() <<std::endl; 
}