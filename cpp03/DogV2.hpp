/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogV2.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 15:41:59 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 15:43:38 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOGV2_HPP
# define DOGV2_HPP
# include "AnimalV2.hpp"
class DogV2 : public AnimalV2
{
  protected:
  private:
  public:
	DogV2(const std::string &name);
	~DogV2();

	void makeSound() const;
};

#endif