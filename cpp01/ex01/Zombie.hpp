/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:36:39 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 16:32:33 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP 

# include <string>
// some zombies will be on stack and some on the heap
class Zombie
{
  private:
	std::string name;

  public:
	Zombie(void);
	Zombie(std::string const &name);
	~Zombie(void);
	void announce(void);
	void setName(const std::string &name);
};
Zombie	*zombieHorde(int N, std::string name);
#endif