/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:36:39 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/03 19:48:19 by moodeh           ###   ########.fr       */
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
	Zombie(std::string const &name);
	~Zombie(void);
	void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif