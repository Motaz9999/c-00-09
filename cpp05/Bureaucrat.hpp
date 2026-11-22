#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat
{
private:
    std::string _name;
    int _grade;

public: // nested classes
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
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    static const int GRADE_HIGHEST = 1;
    static const int GRADE_LOWEST = 150;
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif