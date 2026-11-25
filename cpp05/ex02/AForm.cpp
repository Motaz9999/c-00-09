/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:05 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 01:54:56 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

const int AForm::HIGHEST;
const int AForm::LOWEST;
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be 1 or greater)";
}

AForm::GradeTooHighException::~GradeTooHighException() throw()
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low (to sign or execute) OR (grade must be 150 or lower)";
}
AForm::GradeTooLowException::~GradeTooLowException() throw()
{
}

AForm::FormNotSignedException::~FormNotSignedException() throw()
{}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed (must be sigend to execute)";
}

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeExecute(150)
{
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw AForm::GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeExecute(other._gradeExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{

    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}
AForm::~AForm()
{
}

const std::string &AForm::getName() const
{
    return _name;
}
bool AForm::getIsSigned() const
{
    return _isSigned;
}
int AForm::getGradeToSign() const
{
    return _gradeToSign;
}
int AForm::getGradeToExecute() const
{
    return _gradeExecute;
}

// //fun
// change status to signed if the b grade is higher or = the grade of the form ,
// if it lower throw exception
// so the scenario there is a person wanna sign the AForm
void AForm::beSigned(const Bureaucrat &b)
{
    // must check on the grade if it = or higher than it
    // so in reverse if the form grade higher is it error
    // 1 > 2 valid
    // if grade to sign is lower this mean error
    if (_gradeToSign < b.getGrade())
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true; // done
}

// ok this is for execute form (must be higher grade and signed)
// so how the subclasses while execute the action (special signature)
// easy just put here new pure fun for the son to implement
void AForm::execute(Bureaucrat const &execute) const
{
    if (_isSigned == false)
    {
        throw AForm::FormNotSignedException();
    }
    if(_gradeExecute < execute.getGrade())
    {
        throw AForm::GradeTooLowException();//this mean the person dont have the grade to execute
    }
    this->executeAction();//100% can be executed
}

std::ostream &operator<<(std::ostream &o, const AForm &other)
{
    o << "AForm: " << other.getName()
      << ", sign grade: " << other.getGradeToSign()
      << ", execute grade: " << other.getGradeToExecute()
      << ", signed: " << (other.getIsSigned() ? "yes" : "no") << ".";
    return o;
} // printing
