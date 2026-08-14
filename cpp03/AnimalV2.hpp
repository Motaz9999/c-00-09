/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalV2.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:33:41 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 15:40:16 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMALV2_HPP
# define ANIMALV2_HPP
# include <iostream>
# include <string>
class AnimalV2
{
  protected:
	std::string _name;

  public:
	AnimalV2(std::string const &name);
	~AnimalV2();

	void makeSound() const;
	void makeSound(int times) const;
};
#endif