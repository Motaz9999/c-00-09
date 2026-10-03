/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:00:33 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 18:00:09 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
  private:
	std::string _type; // cus we have get and set so its private
  public:
	AMateria();                                 // def
	AMateria(const std::string &type);          // parm
	AMateria(const AMateria &other);            // copy
	AMateria &operator=(const AMateria &other); // assign
	virtual ~AMateria();                                // destr

	// setter and getters
	void setType(const std::string &type);
	const std::string &getType() const;

	// this class is abs class so its also a base class
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};
#endif