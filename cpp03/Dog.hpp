/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 14:21:26 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/04 14:25:33 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
// dog also is animal
// so he inher all Animal specs
class Dog : public Animal
{
  private:
	std::string _breed;

  public:
	Dog();
	Dog(std::string const &name, std::string const &breed);
	~Dog();
	std::string getBreed() const;
};
#endif