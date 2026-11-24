#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
// #include <exception>
#include <stdexcept>
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
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &other); // printing
#endif