#include "Bureaucrat.hpp"
#include <iostream>

const int Bureaucrat::GRADE_HIGHEST;
const int Bureaucrat::GRADE_LOWEST;

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be 1 or greater)";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low (must be 150 or less)";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < GRADE_HIGHEST)
        throw GradeTooHighException();
    if (grade > GRADE_LOWEST)
        throw GradeTooLowException();
    std::cout << "[Bureaucrat] " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "[Bureaucrat] Copy constructor called for " << _name << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
    if (this != &other)
        _grade = other._grade; // _name is const: it cannot be reassigned, by design
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] " << _name << " destroyed" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < GRADE_HIGHEST)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > GRADE_LOWEST)
        throw GradeTooLowException();
    _grade++;
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
