/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bird.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 17:09:46 by moodeh            #+#    #+#             */
/*   Updated: 2026/08/14 17:13:38 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIRD_HPP
# define BIRD_HPP
# include <iostream>
# include <string>
class Bird
{
  protected:
	std::string _name;

  private:
  public:
	Bird(std::string const &name);
	~Bird();
	void move() const;
};
#endif