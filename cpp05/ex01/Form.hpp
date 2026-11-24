/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:20 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/24 07:15:32 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
    const std::string _name;
    bool _isSigned;          // def false
    const int _gradeToSign;  // sign it must be some grade so he can sign the form (1 150) so the grade is required
    const int _gradeExecute; // grade that must have to let the employee execute the form 1-150
public:
    static const int HIGHEST = 1;
    static const int LOWEST = 150;
    // ocf
    Form();
    Form(const std::string &name, int gradeToSign, int gradeToExecute);
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    // exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual ~GradeTooHighException() throw();
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual ~GradeTooLowException() throw();
        virtual const char *what() const throw();
    };
    // getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    // fun
    void beSigned(const Bureaucrat &b); // change status to signed if the b grade is higher or = the grade of the form , if it lower throw exception
};
std::ostream &operator<<(std::ostream &o, const Form &other); // printing

#endif
