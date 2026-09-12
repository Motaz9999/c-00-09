/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:32:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/12 19:18:58 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void toUpper(std::string &word)
{
    for (size_t i = 0; i < word.length(); i++)
        word[i] = std::toupper(word[i]);
}

bool checkOnCmdAndExecute(std::string &cmd, Phone::PhoneBook &book)
{
    toUpper(cmd);
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
    return (false);
}

int main(void)
{
    Phone::PhoneBook book;
    std::string cmd;

    while (true)
    {
        std::cout << "Please enter your command (ADD, SEARCH, EXIT) : ";
        if (!std::getline(std::cin, cmd))
        {
            std::cout << "\nEOF detected. Exiting program." << std::endl;
            break ;
        }
        if (cmd.empty())
            continue ;
        toUpper(cmd);
        if (!cmd.compare("EXIT"))
        {
            std::cout << "Exited the program successfully." << std::endl;
            break ;
        }
        if (!checkOnCmdAndExecute(cmd, book))
            std::cerr << "Error : please choose from these 3 cmd (ADD, SEARCH, EXIT)" << std::endl;
    }
    return (0);
}