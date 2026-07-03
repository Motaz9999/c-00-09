/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 19:43:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/03 20:28:31 by moodeh           ###   ########.fr       */
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