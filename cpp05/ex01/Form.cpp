/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 06:50:05 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/24 07:15:53 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
const int Form::HIGHEST;
const int Form::LOWEST;
const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be 1 or greater)"; // same error
}

Form::GradeTooHighException::~GradeTooHighException() throw()
{
}

//         virtual const char *what() const throw();

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low (to sign or execute) OR (grade must be 150 or lower)";
}
Form::GradeTooLowException::~GradeTooLowException() throw()
{
}
// private:
//     const std::string _name;
//     bool _isSigned;//def false
//     const int _gradeToSign; // sign it must be some grade so he can sign the form (1 150) so the grade is required
//     const int _gradeExecute; // grade that must have to let the employee execute the form 1-150
// public:
// //ocf

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeExecute(150)
{
    // add log
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeExecute(gradeToExecute)
{
    if (gradeToSign < HIGHEST || gradeToExecute < HIGHEST)
        throw Form::GradeTooHighException();
    if (gradeToSign > LOWEST || gradeToExecute > LOWEST)
        throw Form::GradeTooLowException();
}

//
Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeExecute(other._gradeExecute)
{
    // add log
}

Form &Form::operator=(const Form &other)
{
    // log
    if (this != &other)
        this->_isSigned = other._isSigned; // the only one not const
    return *this;
}
Form::~Form()
{
    // log
}
// //getters
const std::string &Form::getName() const
{
    return _name;
}
bool Form::getIsSigned() const
{
    return _isSigned;
}
int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeExecute;
}

// //fun
// change status to signed if the b grade is higher or = the grade of the form ,
// if it lower throw exception
// so the scenario there is a person wanna sign the Form
void Form::beSigned(const Bureaucrat &b)
{
    // must check on the grade if it = or higher than it
    // so in reverse if the form grade higher is it error
    // 1 > 2 valid
    // if grade to sign is lower this mean error
    if (_gradeToSign < b.getGrade())
    {
        throw Form::GradeTooLowException();
    }
    _isSigned = true; // done
}
std::ostream &operator<<(std::ostream &o, const Form &other)
{
    o << "Form: " << other.getName()
      << ", sign grade: " << other.getGradeToSign()
      << ", execute grade: " << other.getGradeToExecute()
      << ", signed: " << (other.getIsSigned() ? "yes" : "no") << ".";
    return o;
} // printing
