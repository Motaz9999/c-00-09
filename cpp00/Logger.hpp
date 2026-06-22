/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 18:50:22 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 19:00:09 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_HPP
# define LOGGER_HPP
# include <string>
#include <iostream>
class Logger
{
  public:
	Logger(void);
	Logger(const std::string &name);
	~Logger(void);
	void doSomething(void) const;
    private:
    std::string _name;
};
#endif