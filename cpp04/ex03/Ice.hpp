/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 17:24:54 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/02 19:48:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

//cus AMateria is abs class and base class for this class
class Ice : public AMateria
{
private:
protected:
public:
    Ice();//def
    Ice(const std::string & type);
    Ice(const Ice &other);
    Ice& operator=(const Ice &other);
    virtual ~Ice();//must be virtual best practice

    //now what it inherit from base class
    virtual AMateria* clone() const ;
    virtual void use(ICharacter & target);
};
#endif