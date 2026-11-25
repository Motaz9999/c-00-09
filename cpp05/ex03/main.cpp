/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 06:40:00 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 06:40:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

static void printHeader(const std::string &title)
{
    std::cout << "\n" << BOLD << CYAN << "========================================" << RESET << std::endl;
    std::cout << BOLD << CYAN << "  " << title << RESET << std::endl;
    std::cout << BOLD << CYAN << "========================================" << RESET << std::endl;
}

int main()
{
    std::srand(std::time(NULL));

    printHeader("TEST 1: Subject Example (Intern creates robotomy request)");
    {
        Intern someRandomIntern;
        Bureaucrat boss("Boss", 1);
        AForm *rrf;

        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
        else
            std::cout << RED << "[FAIL] Expected RobotomyRequestForm" << RESET << std::endl;
    }

    printHeader("TEST 2: All Valid Form Names & Case Insensitivity");
    {
        Intern intern;
        Bureaucrat boss("Director", 1);
        const std::string validNames[6] = {
            "shrubbery creation",
            "ShrubberyCreationForm",
            "robotomy request",
            "ROBOTOMYREQUESTFORM",
            "presidential pardon",
            "PrEsIdEnTiAlPaRdOnFoRm"
        };
        const std::string targets[6] = {
            "office",
            "backyard",
            "Claptrap",
            "Wall-E",
            "Arthur Dent",
            "Ford Prefect"
        };

        for (int i = 0; i < 6; ++i)
        {
            std::cout << YELLOW << "-- Requesting: \"" << validNames[i] << "\" --" << RESET << std::endl;
            AForm *form = intern.makeForm(validNames[i], targets[i]);
            if (!form)
            {
                std::cout << RED << "[FAIL] Returned NULL for valid form: " << validNames[i] << RESET << std::endl;
                continue;
            }
            std::cout << GREEN << "[OK] Created: " << RESET << *form << std::endl;
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }

        std::ifstream f1("office_shrubbery");
        std::ifstream f2("backyard_shrubbery");
        if (f1.is_open() && f2.is_open())
            std::cout << GREEN << "[OK] Both shrubbery files created" << RESET << std::endl;
        else
            std::cout << RED << "[FAIL] Missing shrubbery output file" << RESET << std::endl;
    }

    printHeader("TEST 3: Unknown / Invalid Form Names");
    {
        Intern intern;
        const std::string invalidNames[4] = {
            "coffee making",
            "tax evasion",
            "presidential",
            ""
        };

        for (int i = 0; i < 4; ++i)
        {
            AForm *form = intern.makeForm(invalidNames[i], "Nobody");
            if (form == NULL)
                std::cout << GREEN << "[OK] Returned NULL for \"" << invalidNames[i] << "\"" << RESET << std::endl;
            else
            {
                std::cout << RED << "[FAIL] Should have returned NULL for \"" << invalidNames[i] << "\"" << RESET << std::endl;
                delete form;
            }
        }
    }

    printHeader("TEST 4: Intern OCF & const Intern");
    {
        Intern i1;
        Intern i2(i1);
        Intern i3;
        i3 = i2;
        const Intern constIntern(i3);

        AForm *f = constIntern.makeForm("presidential pardon", "Trillian");
        if (f)
        {
            Bureaucrat low("InternHelper", 150);
            Bureaucrat high("President", 1);

            std::cout << YELLOW << "-- Execute unsigned form --" << RESET << std::endl;
            high.executeForm(*f);

            std::cout << YELLOW << "-- Sign with too-low grade --" << RESET << std::endl;
            low.signForm(*f);

            std::cout << YELLOW << "-- Sign & execute with grade 1 --" << RESET << std::endl;
            high.signForm(*f);
            high.executeForm(*f);
            delete f;
        }
        else
            std::cout << RED << "[FAIL] const Intern failed to create form" << RESET << std::endl;
    }

    return 0;
}
