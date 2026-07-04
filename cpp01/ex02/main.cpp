/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 16:49:50 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/04 17:59:19 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string var1 = "HI THIS IS BRAIN";
	std::string *stringPTR = &var1;
	std::string &stringREF = var1;
    
    std::cout << "The memory address of the string variable :" << &var1 << std::endl;
    std::cout << "The memory address held by stringPTR :" << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF :" << &stringREF << std::endl;
    
    std::cout << "The value of the string variable :" << var1 << std::endl;
    std::cout << "The value pointed to by stringPTR :" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF :" << stringREF << std::endl;

}