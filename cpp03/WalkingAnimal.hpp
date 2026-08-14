/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WalkingAnimal.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:20:13 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:24:07 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALKINGANIMAL_HPP
# define WALKINGANIMAL_HPP
# include "Animal.hpp"
class WalkingAnimal : virtual public Animal
{
  protected:
  public:
	WalkingAnimal(const std::string &name);
	~WalkingAnimal();
	void walk() const;
};
#endif