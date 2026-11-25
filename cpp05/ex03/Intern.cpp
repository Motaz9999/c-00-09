/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 06:21:57 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 07:10:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>

const char *Intern::WrongFormException::what() const throw()
{
    return "Form Not Found";
}
Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

// helper fun put it private
std::string Intern::toLowerCase(std::string const &str)
{
    std::string result = str;
    for (size_t i = 0; i < result.length(); i++)
    {
        result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
    }
    return result;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
    // first i will make an array of what i want to compare or what i have already
    // i have like 3*2 = 6 all lower case so the name must be lower case ,, aw
    std::string names[6] = {"presidentialpardonform", "presidential pardon", "robotomyrequestform", "robotomy request", "shrubberycreationform", "shrubbery creation"};
    // now there is a loop that see them all and compare to name
    try
    {
        int i = 0;
        std::string lowerName = toLowerCase(name);
        while (i < 6 && names[i] != lowerName)
            i++; // if it found break
        AForm *createdForm = NULL;
        switch (i)
        {
        case 0:
        case 1:
            createdForm = new PresidentialPardonForm(target);
            break;
        case 2:
        case 3:
            createdForm = new RobotomyRequestForm(target);
            break;
        case 4:
        case 5:
            createdForm = new ShrubberyCreationForm(target);
            break;
        default:
            throw Intern::WrongFormException();
        }
        std::cout << "Intern creates " << name << std::endl;
        return createdForm;
    }
    catch (std::exception &e)
    {
        std::cout <<  "Error: " << e.what() << " \""<< name << "\" ."  << std::endl;
    }
    return NULL;
}
