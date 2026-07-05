/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 18:05:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/05 18:46:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

//  void debug(void);
// void info(void);
// void warning(void);
// void error(void);

// public :
// void complain(std::string level);

void Harl::debug(void)
{
	std::cout << "[DEBUG]\n"
				<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
    	std::cout << "[INFO]\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"<<std::endl;
}

void Harl::warning(void)
{
    std::cout << "[WARNING]\n"<<"I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." <<std::endl;
}
void Harl::error(void)
{
	std::cout << "[ERROR]\n" <<"This is unacceptable! I want to speak to the manager now."<<std::endl;
}
//it takes levels as uppercase
void Harl::complain(std::string level)
{
    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*pointer[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    for (int i = 0; i < 4; i++)
    {
        if(levels[i] == level)
        {
            (this->*pointer[i])();
            return ;
        }
    }
    std::cout << "[ Probably complaining about insignificant problems ]" <<std::endl;
}