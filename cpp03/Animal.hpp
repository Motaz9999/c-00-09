/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:13:17 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 14:16:13 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>
class Animal
{
    private:
    std::string _name;
    public:
    Animal();
    Animal(std::string const& name);
    Animal(Animal const& other);
    Animal& operator=(Animal const& other);
    ~Animal();
    std::string getName() const ;//return name
};
#endif