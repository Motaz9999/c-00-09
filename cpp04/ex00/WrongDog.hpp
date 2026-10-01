/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:51:34 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 18:51:35 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP

# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
    WrongDog();
    WrongDog(const std::string &type);
    WrongDog(const WrongDog &other);
    WrongDog &operator=(const WrongDog &other);
    virtual ~WrongDog();

     virtual void makeSound(void) const;//must rewite it if i want it to make another thinges here
};

#endif