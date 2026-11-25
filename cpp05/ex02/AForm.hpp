/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:20 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 02:23:17 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"

//here i cant make an obj from abs class so there is virtual that is declare
class Bureaucrat;
class AForm
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
    AForm();
    AForm(const std::string &name, int gradeToSign, int gradeToExecute);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();
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
    //add new exception for signed or not 
    class FormNotSignedException : public std::exception
    {
        public :
        virtual ~FormNotSignedException() throw();
        virtual const char*what() const throw();
    };
    // getters
    const std::string &getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    // fun
    void beSigned(const Bureaucrat &b); // change status to signed if the b grade is higher or = the grade of the form , if it lower throw exception
    void execute(Bureaucrat const & execute) const;//ok this is for execute form (must be higher grade and signed)
    //so how the subclasses while execute the action (special signature)
    //easy just put here new pure fun for the son to implement
    protected:
    virtual  void executeAction(Bureaucrat const & execute) const = 0 ;//will be called by execute to do different things (depend on each class)
};
std::ostream &operator<<(std::ostream &o, const AForm &other); // printing

#endif
