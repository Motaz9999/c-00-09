/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 06:11:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 07:06:59 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include <iostream>
#include <exception>

class AForm;

class Intern
{
private:
    static std::string toLowerCase(std::string const &str);

public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();
    class WrongFormException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    AForm *makeForm(const std::string &name, const std::string &target) const;
};
#endif
