/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 18:24:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 19:33:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
class HumanA
{
  private:
	std::string name;
	Weapon &a;

  public:
	HumanA(std::string const &name, Weapon &b);
	void attack(void) const;
};
#endif