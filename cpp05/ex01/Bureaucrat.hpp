/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:14 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/24 06:50:15 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
// #include <stdexcept>
class Form;
class Bureaucrat
{
private:
    const std::string _name; // const after give it a value
    int _grade;

public:
    static const int HIGHEST = 1;
    static const int LOWEST = 150;
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    // exception classes nested classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    // now getters and increment and decrement
    const std::string &getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    // for ex01
    void signForm(Form &form); //call Form::beSigned() to attempt to sign the form
    //on suc print <bureaucrat> signed <form>
    //else print <bureaucrat> couldn’t sign <form> because <reason>

};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &other); // printing
#endif
