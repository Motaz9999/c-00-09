/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Snake.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 19:46:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/06 21:03:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SNAKE_HPP
# define SNAKE_HPP
# include "Animal.hpp"
class Snake : public Animal
{
  public:
  		Snake();

	Snake(const std::string &name);
	~Snake();

	// void makeSound(); // missing 'const' — does NOT override
    virtual void makeSound() const; //its ok to add Virtual 
};
#endif