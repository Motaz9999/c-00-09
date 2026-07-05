/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:53:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/05 19:57:12 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	getLevel(std::string const &level)
{
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			return (i);
		}
	}
	return (4); // 0-3 all levels 4 is else
}
// ok what is this is the user must give u input
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: more than 1 input ." << std::endl;
		return (1);
	}
	Harl m;
    std::string str = argv[1];
    for (size_t i = 0; i < str.length(); i++) {
        str[i] = std::toupper(str[i]);
    }
	switch (getLevel(str))
	{
	case 0:
		m.complain("DEBUG");
		/* FALLTHROUGH */
	case 1:
		m.complain("INFO");
		/* FALLTHROUGH */
	case 2:
		m.complain("WARNING");
		/* FALLTHROUGH */
	case 3:
		m.complain("ERROR");
		break ;
	default:
		m.complain("else");
	}
	return (0);
}