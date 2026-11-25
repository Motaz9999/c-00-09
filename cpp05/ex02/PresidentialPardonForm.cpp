/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 03:16:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 03:18:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

// copy const
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target; // deep copy
    }
    return *this;
}
// auto call parent des
PresidentialPardonForm::~PresidentialPardonForm()
{
} // cus it inheritnat from Abs class
// rand fun is print 0 - RAND_MAX	2147483647
// so i just use odd or even with it
void PresidentialPardonForm::executeAction(Bureaucrat const &execute) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
