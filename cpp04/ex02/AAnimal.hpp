/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 18:52:04 by moodeh            #+#    #+#             */
/*   Updated: 2026/10/01 22:58:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class AAnimal
{
protected:
    std::string _type;

public:
    AAnimal();
    AAnimal(const std::string &type);
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal();

    const std::string &getType() const ; //there is no need to make this function virtual since it does not need to be overridden in derived classes
    virtual void makeSound() const = 0;//pure virtual
};

#endif