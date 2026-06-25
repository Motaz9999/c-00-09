/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/25 20:39:16 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	toUpper(std::string &word)
{
	for (size_t i = 0; i < word.length(); i++)
	{
		word[i] = std::toupper(word[i]);
	}
}

bool	checkOnCmdAndExecute(std::string &cmd, Phone::PhoneBook &book , bool &flag)
{
	toUpper(cmd); // make the string into upper case
	if (!cmd.compare("ADD"))
	{
		book.add();
		return (true);
	}
	else if (!cmd.compare("SEARCH"))
	{
        	book.search();
		return (true);
	}
	else if (!cmd.compare("EXIT"))
	{
        flag = false;
        std::cout << "Exit the program successfully ." <<std::endl;   
		return (true);
	}
	else
		return (false);
}
int	main(void)
{
	Phone::PhoneBook book;
	std::string cmd;
    bool flag = true;
	while (flag)
	{
		std::cout << "Please enter your command (ADD , SEARCH , EXIT) :";
		if (!std::getline(std::cin, cmd))
		{
			std::cerr << "Error : error happen in reading the cmd please try again." << std::endl;
			continue ;
		}
		if (cmd.empty())
		{
			std::cerr << "Error : please enter input." << std::endl;
			continue ;
		}
		if (!checkOnCmdAndExecute(cmd, book , flag))
		{
			std::cerr << "Error : please choose from these 3 cmd (ADD , SEARCH , EXIT)" << std::endl;
		}
	}

	return (0);
}