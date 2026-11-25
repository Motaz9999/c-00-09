/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 02:06:21 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 02:40:21 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
// class AForm;
class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;                                         // like name
    virtual void executeAction(Bureaucrat const &execute) const; // will be called by execute to do different things (depend on each class)
public:
//ocf
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    virtual ~ShrubberyCreationForm();//cus it inheritnat from Abs class 
};

#endif