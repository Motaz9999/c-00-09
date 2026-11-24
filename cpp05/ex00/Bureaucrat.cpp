#include "Bureaucrat.hpp"
using std::cout;
using std::endl;
using std::string;
// no log needed here
//  public:
const int Bureaucrat::HIGHEST; // 1
const int Bureaucrat::LOWEST;  // must be written maybe they will be use with other fun //150

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
    // std::cout << "[Bureaucrat] " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
    // std::cout << "[Bureaucrat] " << _name << " created with grade " << _grade << std::endl;
    if (grade > LOWEST)
        throw GradeTooLowException();

    if (grade < HIGHEST)
        throw GradeTooHighException();
    _grade = grade;
}
Bureaucrat::~Bureaucrat()
{
    // std::cout << "[Bureaucrat] " << _name << " destroyed" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    // std::cout << "[Bureaucrat] Copy constructor called for " << _name << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    // std::cout << "[Bureaucrat] Copy assignment operator called" << std::endl;
    // name is const cant be changed
    if (this != &other)
        _grade = other._grade;
    return *this;
}

//     // exception classes nested classes

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high (must be 1 or greater)";
}

//         virtual const char *what() const throw();

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low (must be 150 or less)";
}

//     // now getters and increment and decrement
const std::string &Bureaucrat::getName() const
{
    return _name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}

// inc mean that the rank goes higher like from 3 to 2 (just by 1)
// so we need to -- it and check before if it error throw it if no dont throw and assign it
void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < HIGHEST)
        throw GradeTooHighException();
    _grade--;
}
// same but from 1 to 2 is ++ lower it
void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > LOWEST)
        throw GradeTooLowException();
    _grade++;
}
// print in this form <name>, bureaucrat grade <grade>
std::ostream &operator<<(std::ostream &o, const Bureaucrat &other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade()<<".";
    return o;
} // printing
