/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:51 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:51:52 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

     virtual void makeSound(void) const;//must rewite it if i want it to make another thinges here
};

#endif