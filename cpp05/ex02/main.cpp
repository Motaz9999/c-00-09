/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 04:20:00 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 05:01:37 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
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
    std::srand(std::time(NULL));//so each time new values seed random( its to make abs random based on time )

    // AForm abstractCheck("test", 1, 1); // Must NOT compile: AForm is abstract

    printHeader("TEST 1: ShrubberyCreationForm (Sign 145, Exec 137)");
    {
        Bureaucrat intern("Intern", 146);
        Bureaucrat gardener("Gardener", 145);
        Bureaucrat supervisor("Supervisor", 138);
        Bureaucrat landscaper("Landscaper", 137);//4 people with diff grades ALL low
        ShrubberyCreationForm shrub("garden");//shrubbery form low grade required  sign 145 execute 137

        std::cout << shrub << std::endl;

        std::cout << YELLOW << "-- Execute before signing --" << RESET << std::endl;
        landscaper.executeForm(shrub);//cant

        std::cout << YELLOW << "-- Sign with grade 146 (too low) --" << RESET << std::endl;
        intern.signForm(shrub);//grade is lower than 

        std::cout << YELLOW << "-- Sign with exact grade 145 --" << RESET << std::endl;
        gardener.signForm(shrub);
        std::cout << shrub << std::endl;

        std::cout << YELLOW << "-- Execute with grade 138 (too low) --" << RESET << std::endl;
        supervisor.executeForm(shrub);

        std::cout << YELLOW << "-- Execute with exact grade 137 --" << RESET << std::endl;
        landscaper.executeForm(shrub);

        std::ifstream check("garden_shrubbery");
        if (check.is_open() && check.peek() != std::ifstream::traits_type::eof())
            std::cout << GREEN << "[OK] garden_shrubbery created and non-empty" << RESET << std::endl;
        else
            std::cout << RED << "[FAIL] garden_shrubbery missing or empty" << RESET << std::endl;
        check.close();
    }

    printHeader("TEST 2: RobotomyRequestForm (Sign 72, Exec 45)");
    {
        Bureaucrat lowSigner("LowSigner", 73);
        Bureaucrat signer("Signer", 72);
        Bureaucrat lowExec("LowExec", 46);
        Bureaucrat surgeon("Surgeon", 45);
        RobotomyRequestForm robo("Bender");//72 , 45

        std::cout << robo << std::endl;

        std::cout << YELLOW << "-- Execute before signing --" << RESET << std::endl;
        surgeon.executeForm(robo);

        std::cout << YELLOW << "-- Sign with grade 73 (too low) --" << RESET << std::endl;
        lowSigner.signForm(robo);

        std::cout << YELLOW << "-- Sign with exact grade 72 --" << RESET << std::endl;
        signer.signForm(robo);

        std::cout << YELLOW << "-- Execute with grade 46 (too low) --" << RESET << std::endl;
        lowExec.executeForm(robo);

        std::cout << YELLOW << "-- Execute 6 times with exact grade 45 (50% rate) --" << RESET << std::endl;
        for (int i = 0; i < 6; ++i)
            surgeon.executeForm(robo);
    }

    printHeader("TEST 3: PresidentialPardonForm (Sign 25, Exec 5)");
    {
        Bureaucrat lowSigner("Clerk", 26);
        Bureaucrat signer("Minister", 25);
        Bureaucrat lowExec("VicePresident", 6);
        const Bureaucrat president("Zaphod", 5);
        PresidentialPardonForm pardon("Arthur Dent");//25 5

        std::cout << pardon << std::endl;

        std::cout << YELLOW << "-- Execute before signing --" << RESET << std::endl;
        president.executeForm(pardon);

        std::cout << YELLOW << "-- Sign with grade 26 (too low) --" << RESET << std::endl;
        lowSigner.signForm(pardon);

        std::cout << YELLOW << "-- Sign with exact grade 25 --" << RESET << std::endl;
        signer.signForm(pardon);

        std::cout << YELLOW << "-- Execute with grade 6 (too low) --" << RESET << std::endl;
        lowExec.executeForm(pardon);

        std::cout << YELLOW << "-- Execute with const Bureaucrat (grade 5) --" << RESET << std::endl;
        president.executeForm(pardon);
    }

    printHeader("TEST 4: Direct AForm::execute() & Exception Types");
    {
        Bureaucrat boss("Boss", 1);
        Bureaucrat rookie("Rookie", 150);
        PresidentialPardonForm direct("Ford Prefect");

        try
        {
            direct.execute(boss);
            std::cout << RED << "[FAIL] Expected FormNotSignedException" << RESET << std::endl;
        }
        catch (const AForm::FormNotSignedException &e)
        {
            std::cout << GREEN << "[OK] Caught FormNotSignedException: " << RESET << e.what() << std::endl;
        }

        boss.signForm(direct);

        try
        {
            direct.execute(rookie);
            std::cout << RED << "[FAIL] Expected GradeTooLowException" << RESET << std::endl;
        }
        catch (const AForm::GradeTooLowException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooLowException: " << RESET << e.what() << std::endl;
        }
    }

    printHeader("TEST 5: Polymorphism (AForm *) & Virtual Destructors");
    {
        Bureaucrat boss("Director", 1);
        AForm *forms[3];
        forms[0] = new ShrubberyCreationForm("park");
        forms[1] = new RobotomyRequestForm("Marvin");
        forms[2] = new PresidentialPardonForm("Trillian");

        for (int i = 0; i < 3; ++i)
        {
            std::cout << *forms[i] << std::endl;
            boss.signForm(*forms[i]);
            boss.executeForm(*forms[i]);
            delete forms[i];
        }
    }

    printHeader("TEST 6: Orthodox Canonical Form (Default, Copy, Assign)");
    {
        Bureaucrat boss("Chief", 1);

        ShrubberyCreationForm sDef;
        ShrubberyCreationForm sOrig("home");
        boss.signForm(sOrig);
        ShrubberyCreationForm sCopy(sOrig);
        ShrubberyCreationForm sAssign;
        sAssign = sOrig;
        std::cout << sDef << " | copy: " << sCopy << " | assign: " << sAssign << std::endl;
        boss.executeForm(sDef);
        boss.executeForm(sCopy);
        boss.executeForm(sAssign);

        RobotomyRequestForm rDef;
        RobotomyRequestForm rOrig("TargetR");
        boss.signForm(rOrig);
        RobotomyRequestForm rCopy(rOrig);
        RobotomyRequestForm rAssign;
        rAssign = rOrig;
        boss.executeForm(rCopy);
        boss.executeForm(rAssign);

        PresidentialPardonForm pDef;
        PresidentialPardonForm pOrig("TargetP");
        boss.signForm(pOrig);
        PresidentialPardonForm pCopy(pOrig);
        PresidentialPardonForm pAssign;
        pAssign = pOrig;
        boss.executeForm(pDef);
        boss.executeForm(pCopy);
        boss.executeForm(pAssign);
    }

    return 0;
}
