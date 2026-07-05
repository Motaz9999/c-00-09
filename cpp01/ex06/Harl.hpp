/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 17:54:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/05 18:04:53 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
#include <string>
#include <iostream>
class Harl
{
    private :
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
    
    public :
    void complain(std::string level);
};
#endif