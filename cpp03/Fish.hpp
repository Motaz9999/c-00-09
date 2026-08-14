/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fish.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:14:21 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:14:40 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FISH_HPP
# define FISH_HPP

# include <iostream>
# include <string>
class Fish
{
  protected:
	std::string _name;

  public:
	Fish(const std::string &name);
	~Fish();

	void move() const;
};
#endif