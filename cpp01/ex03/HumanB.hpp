/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:25:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 19:33:28 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon *a;
    public:
    HumanB(std::string const &name);
    void attack() const;
    void setWeapon(Weapon &a);
};
#endif