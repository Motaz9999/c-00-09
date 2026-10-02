/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:16:26 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/02 21:51:58 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include "AMateria.hpp"
# include <string>
// there is no need to make cpp file cus this interface
class ICharacter
{
  public:
	virtual ~ICharacter(){}//there is nothing to write or do but its must be virtual
	virtual const std::string  &getName() const = 0;// there is no member called name btw this interface cant have any real members
	virtual void equip(AMateria *m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter &target) = 0;
};
#endif