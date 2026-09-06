/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:09:07 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 18:10:38 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
class Dog : public Animal
{
  private:
  protected:
  public:
	Dog();
	Dog(const std::string &name);
	~Dog();
	void makeSound() const;//refined
    
};

#endif