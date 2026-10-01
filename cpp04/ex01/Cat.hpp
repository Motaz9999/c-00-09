/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 20:32:52 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;//this is on heap    
public:
    Cat();
    Cat(const std::string &type);
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    virtual ~Cat();

    virtual void makeSound(void) const;//must Rewrite it if i want it to make another thinges here
    
    const std::string &getIdea(int index) const;
    void setIdea(int index, const std::string &idea);//then use  what inside brain
    Brain *getBrain() const;
};

#endif