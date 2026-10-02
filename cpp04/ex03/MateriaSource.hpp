/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 01:16:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 01:50:12 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include"AMateria.hpp"
#include "IMateriaSource.hpp"
class MateriaSource : public IMateriaSource
{
private:
AMateria* _templates[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource & operator=(const MateriaSource &other);
    virtual ~MateriaSource();


//fun to implement from the interface 
    virtual void learnMateria(AMateria *);
    virtual AMateria *createMateria(std::string const &type);
};

#endif