/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 01:40:32 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/03 01:46:12 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "[MateriaSource] default constructor" << std::endl;

    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
}
MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "[MateriaSource] copy constructor" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (other._templates[i] != NULL)
            this->_templates[i] = other._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "[MateriaSource] copy assignment operator" << std::endl;

    if (this != &other)
    {
        for (int i = 0; i < 4; i++)
        {
            if (this->_templates[i] != NULL)
            {
                delete this->_templates[i];
                this->_templates[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            if (other._templates[i] != NULL)
                this->_templates[i] = other._templates[i]->clone();
            else
                this->_templates[i] = NULL;
        }
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    std::cout << "[MateriaSource] destructor" << std::endl;

    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL)
        {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] == NULL)
        {
            this->_templates[i] = m; // add it to array
            return;
        }
    }
    delete m; // cant do anything with it
}
// if there anyone from the ary and match the type make clone and return it
AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
            return this->_templates[i]->clone();
    }
    return NULL;
}