/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 03:15:08 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 03:15:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
// class AForm;
class Bureaucrat;
class PresidentialPardonForm : public AForm
{
private:
    std::string _target;                                         // like name
    virtual void executeAction(Bureaucrat const &execute) const; // will be called by execute to do different things (depend on each class)
public:
//ocf
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    virtual ~PresidentialPardonForm();//cus it inheritnat from Abs class 
};

#endif