/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:06 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:52:08 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
// default const
// the already have 100 element have nothing
Brain::Brain()
{
    std::cout << "[Brain] default constructor called " << std::endl;
}

Brain::Brain(const std::string ideas[])
{
    std::cout << "[Brain] parametrized constructor called " << std::endl;
    if (ideas)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = ideas[i];
        }
    }
} // array cant be ref

// we dont use any malloc here so its ok to not deep copy
Brain::Brain(const Brain &other)
{
    std::cout << "[Brain] copy constructor called " << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i] = other._ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "[Brain] copy assignment operator " << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return *this;
}
Brain::~Brain()
{
    std::cout << "[Brain] destructor " << std::endl;

} // must be virtual bc dont have leaks when using delete

const std::string &Brain::getIdea(int index) const
{
    static const std::string empty = ""; // always use same const
    if (index < 0 || index >= 100)
        return (empty); // out ranged and i must return value
    else
        return _ideas[index];
} // send index and get idea from the array
void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        return; // nothing can do
    _ideas[index] = idea;
} // set idea inside the array