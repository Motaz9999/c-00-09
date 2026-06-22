/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:52:15 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 17:02:01 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

void toUpper(char *word)
{
    int i = 0;
    int len = strlen(word);
    while (i < len)
    {
        word[i] = toupper(word[i]);
        i++;
    }
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*word;

	std ::string word;
	if (argc <= 1)
		std ::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	i = 1;
	while (i < argc)
	{
		word = argv[i];
		toUpper(word);
		std::cout << word << std ::endl;
	}
}
