/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/24 07:05:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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
    printHeader("TEST 1: Valid Form Instantiation & Stream Operator");
    {
        try
        {
            Form f1("Tax Return", 50, 25);
            std::cout << GREEN << "[OK] " << RESET << f1 << std::endl;

            Form f2("Top Secret Dossier", 1, 1);
            std::cout << GREEN << "[OK] " << RESET << f2 << std::endl;

            Form f3("Coffee Request", 150, 150);
            std::cout << GREEN << "[OK] " << RESET << f3 << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[ERROR] Unexpected exception: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 2: Invalid Form Instantiations (Boundaries)");
    {
        std::cout << YELLOW << "-- Sign grade too high (0) --" << RESET << std::endl;
        try
        {
            Form invalid("InvalidSignHigh", 0, 50);
            std::cout << RED << "[FAIL] Exception not thrown!" << RESET << std::endl;
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooHighException: " << RESET << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[FAIL] Caught generic exception instead: " << e.what() << RESET << std::endl;
        }

        std::cout << YELLOW << "-- Sign grade too low (151) --" << RESET << std::endl;
        try
        {
            Form invalid("InvalidSignLow", 151, 50);
            std::cout << RED << "[FAIL] Exception not thrown!" << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooLowException: " << RESET << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[FAIL] Caught generic exception instead: " << e.what() << RESET << std::endl;
        }

        std::cout << YELLOW << "-- Execute grade too high (-5) --" << RESET << std::endl;
        try
        {
            Form invalid("InvalidExecHigh", 50, -5);
            std::cout << RED << "[FAIL] Exception not thrown!" << RESET << std::endl;
        }
        catch (const Form::GradeTooHighException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooHighException: " << RESET << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[FAIL] Caught generic exception instead: " << e.what() << RESET << std::endl;
        }

        std::cout << YELLOW << "-- Execute grade too low (999) --" << RESET << std::endl;
        try
        {
            Form invalid("InvalidExecLow", 50, 999);
            std::cout << RED << "[FAIL] Exception not thrown!" << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooLowException: " << RESET << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[FAIL] Caught generic exception instead: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 3: Orthodox Canonical Form for Form");
    {
        Form original("OriginalForm", 42, 21);
        std::cout << "Original before signing: " << original << std::endl;

        Bureaucrat signer("Signer", 30);
        signer.signForm(original);
        std::cout << "Original after signing:  " << original << std::endl;

        std::cout << YELLOW << "-- Copy Constructor --" << RESET << std::endl;
        Form copy(original);
        std::cout << "Copy: " << copy << std::endl;

        std::cout << YELLOW << "-- Copy Assignment Operator --" << RESET << std::endl;
        Form assigned("AssignedPlaceholder", 100, 100);
        std::cout << "Assigned before: " << assigned << std::endl;
        assigned = original;
        std::cout << "Assigned after:  " << assigned << " (signed state copied, consts preserved)" << std::endl;
    }

    printHeader("TEST 4: Direct Form::beSigned() Execution");
    {
        Bureaucrat boss("Boss", 5);
        Bureaucrat intern("Intern", 140);
        Form executiveOrder("Executive Order", 10, 5);

        std::cout << "Form initial state: " << executiveOrder << std::endl;

        std::cout << YELLOW << "-- Intern attempts beSigned() (grade 140 vs required 10) --" << RESET << std::endl;
        try
        {
            executiveOrder.beSigned(intern);
            std::cout << RED << "[FAIL] Intern signed without required grade!" << RESET << std::endl;
        }
        catch (const Form::GradeTooLowException &e)
        {
            std::cout << GREEN << "[OK] Caught GradeTooLowException: " << RESET << e.what() << std::endl;
        }

        std::cout << YELLOW << "-- Boss calls beSigned() (grade 5 vs required 10) --" << RESET << std::endl;
        try
        {
            executiveOrder.beSigned(boss);
            std::cout << GREEN << "[OK] Boss signed successfully! State: " << RESET << executiveOrder << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << RED << "[FAIL] Unexpected exception: " << e.what() << RESET << std::endl;
        }
    }

    printHeader("TEST 5: Bureaucrat::signForm() [Success & Failure cases]");
    {
        Bureaucrat alice("Alice", 20);
        Bureaucrat bob("Bob", 80);

        Form visa("Travel Visa", 40, 20);
        Form buildingPermit("Building Permit", 15, 10);

        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << visa << std::endl;
        std::cout << buildingPermit << std::endl;

        std::cout << YELLOW << "\n-- Alice attempts to sign Travel Visa (grade 20 vs 40) --" << RESET << std::endl;
        alice.signForm(visa);
        std::cout << visa << std::endl;

        std::cout << YELLOW << "\n-- Bob attempts to sign Travel Visa (grade 80 vs 40) --" << RESET << std::endl;
        bob.signForm(visa);

        std::cout << YELLOW << "\n-- Alice attempts to sign Building Permit (grade 20 vs 15) --" << RESET << std::endl;
        alice.signForm(buildingPermit);
        std::cout << buildingPermit << std::endl;

        std::cout << YELLOW << "\n-- Promoting Alice from grade 20 to grade 15 --" << RESET << std::endl;
        while (alice.getGrade() > buildingPermit.getGradeToSign())
        {
            alice.incrementGrade();
            std::cout << "Promoted Alice to grade " << alice.getGrade() << std::endl;
        }
        std::cout << "Alice now: " << alice << std::endl;

        std::cout << YELLOW << "-- Alice attempts to sign Building Permit again --" << RESET << std::endl;
        alice.signForm(buildingPermit);
        std::cout << buildingPermit << std::endl;
    }

    printHeader("TEST 6: Boundary Edge Cases (Grade 1 & Grade 150)");
    {
        Bureaucrat minister("Minister", 1);
        Bureaucrat trainee("Trainee", 150);

        Form constitution("New Constitution", 1, 1);
        Form garbageDuty("Garbage Duty Schedule", 150, 150);

        std::cout << YELLOW << "-- Grade 150 signing Grade 150 Form --" << RESET << std::endl;
        trainee.signForm(garbageDuty);
        std::cout << garbageDuty << std::endl;

        std::cout << YELLOW << "-- Grade 150 attempting Grade 1 Form --" << RESET << std::endl;
        trainee.signForm(constitution);

        std::cout << YELLOW << "-- Grade 1 signing Grade 1 Form --" << RESET << std::endl;
        minister.signForm(constitution);
        std::cout << constitution << std::endl;
    }

    printHeader("ALL TESTS COMPLETED SUCCESSFULLY");
    return 0;
}
