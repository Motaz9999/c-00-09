/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:55:35 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 19:02:07 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

// constraster
Logger::Logger(void)
{
	this->_name = "Unnamed";
	std ::cout << "[+] Constructor (default) ->" << this->_name << std::endl;
}
// parameterized constructor
Logger::Logger(const std::string &name)
{
    this->_name = name;
    std ::cout << "[+] Constructor (parameterized) ->" << this->_name << std::endl;

}

// Destructor Auto called
Logger::~Logger(void)
{
    std:: cout << "[-] Destructor -> " << this->_name << std :: endl;
}

void Logger::doSomething(void) const
{
      std::cout << "    " << this->_name << " is doing something." << std::endl;
}