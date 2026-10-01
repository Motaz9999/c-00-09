/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:19 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 22:59:40 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain* _brain;
public:
    Dog();
    Dog(const std::string &type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    virtual ~Dog();

    virtual void makeSound(void) const;//must rewrite it if i want it to make another things here

    
    const std::string &getIdea(int index) const;
    void setIdea(int index, const std::string &idea);//then use  what inside brain
    Brain *getBrain() const;
};

#endif