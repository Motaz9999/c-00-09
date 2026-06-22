/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:52:15 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 17:17:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>
#include <string>

void	toUpper(std::string &word)
{
    for (size_t i = 0 ; i < word.length() ; i++)
    {
        word[i] = std::toupper(word[i]);
    }
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc <= 1)
	{
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		std::string word = argv[i];
		toUpper(word);
		std::cout << word;
		i++;
	}
	std ::cout << std::endl;
	return (0);
}
