/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:43:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 16:45:07 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
# include <iostream> 
 
//   private:
// 	std::string name;

//   public:
// 	Zombie(std::string const &name);
// 	~Zombie(void);
// 	void announce(void);
Zombie::Zombie(void)
{
    this->name = "Unknown";
}
Zombie::Zombie(std::string const &name)
{
    this->name = name;
}
Zombie::~Zombie(void)
{
    std::cout <<"Zombie with name :" <<this->name << " was destroyed."<< std::endl;
}
void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..."<<std::endl;
}
void Zombie::setName(const std::string &name)
{
    this->name = name;
}