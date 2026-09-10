/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 18:09:07 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/10 18:22:01 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
//# include "Animal.hpp"
# include "AAnimal.hpp"
#include "ISerializable.hpp"
//class Dog : public Animal
class Dog : public AAnimal , public ISerializable
{
  private:
  protected:
  public:
	Dog();
	Dog(const std::string &name);
	Dog(const Dog &obj);
	Dog& operator=(const Dog &obj);
	~Dog();
	virtual void makeSound() const;//refined , now its virtual pure fun
	virtual std::string serialize() const ;
	virtual AAnimal* clone() const;
    
};

#endif