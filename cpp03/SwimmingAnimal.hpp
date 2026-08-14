/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SwimmingAnimal.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 21:31:06 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 21:41:17 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWIMMINGANIMAL_HPP
# define SWIMMINGANIMAL_HPP
# include "Animal.hpp"
class SwimmingAnimal : virtual public Animal
{
  public:
	SwimmingAnimal(const std::string &name);
	~SwimmingAnimal();
	void swim() const;
};
#endif