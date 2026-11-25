/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 02:25:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 04:18:06 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> //for file and i/o

// def constructor
// so this for makeing the form //and nothing to be checked
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

// copy const
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target; // deep copy
    }
    return *this;
}
// auto call parent des
ShrubberyCreationForm::~ShrubberyCreationForm()
{
} // cus it inheritnat from Abs class

// will be called by execute to do different things (depend on each class)
// so here we write the declaration
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees
// inside it.
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
     // this mean each time u run this fun it will make file an
    if (!file.is_open())
    {
        std::cout << "Error opening the file" << std::endl;
        return ;
    }
    file << "               ,@@@@@@@,                           *" << std::endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.              / \\" << std::endl;
    file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o            /   \\" << std::endl;
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'         /_____\\" << std::endl;
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'           /   \\" << std::endl;
    file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'          /     \\" << std::endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'           /_______\\" << std::endl;
    file << "       |o|        | |         | |              /     \\" << std::endl;
    file << "       |.|        | |         | |             /_______\\" << std::endl;
    file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_        | |" << std::endl;
    file.close();
}
