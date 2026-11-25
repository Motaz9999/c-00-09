/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 03:08:40 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 03:14:26 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

// copy const
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target; // deep copy
    }
    return *this;
}
// auto call parent des
RobotomyRequestForm::~RobotomyRequestForm()
{
} // cus it inheritnat from Abs class
//rand fun is print 0 - RAND_MAX	2147483647
//so i just use odd or even with it 
void RobotomyRequestForm::executeAction(Bureaucrat const &execute) const
{
    std::cout << "* BZZZZZZ... DRRRRRRR... VRRRRRR! *" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
}
