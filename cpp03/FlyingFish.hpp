/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlyingFish.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:15:30 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:20:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLYINGFISH_HPP
# define FLYINGFISH_HPP
# include "Bird.hpp"
# include "Fish.hpp"
class FlyingFish : public Bird, public Fish
{
  public:
	FlyingFish(std::string const &name);
	~FlyingFish();

	void move() const;
};
#endif