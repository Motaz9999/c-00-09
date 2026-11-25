/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 02:25:11 by moodeh            #+#    #+#             */
/*   Updated: 2026/11/25 03:05:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream> //for file and i/o
//     std::string _target;                                         // like name
// public:
// //ocf
const std::string RESET   = "\033[0m";
const std::string GREEN   = "\033[1;32m"; // أخضر فاتح للأوراق
const std::string D_GREEN = "\033[0;32m"; // أخضر غامق للعمق
const std::string BROWN   = "\033[0;33m"; // بني/ذهبي للجذع
const std::string PINK    = "\033[1;35m"; // وردي للأزهار
const std::string YELLOW  = "\033[1;33m"; // أصفر للثمار/النجوم
const std::string CYAN    = "\033[1;36m"; // سماوي للعشب/التفاصيل
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
void ShrubberyCreationForm::executeAction(Bureaucrat const &execute) const
{
    std::fstream file;
    file.open((_target + "_shrubbery").c_str()); // this mean each time u run this fun it will make file an
    if (!file.is_open())
    {
        std::cout << "Error opening the file" << std::endl;
    }
 file << GREEN   << "                  .        +          .      .          ." << RESET << std::endl;
    file << GREEN   << "             .            _        .                    ." << RESET << std::endl;
    file << GREEN   << "          ,              /;-._,-.____        ,-----.__" << RESET << std::endl;
    file << PINK    << "         ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << RESET << std::endl;
    file << GREEN   << "          `                 \\   _|`\"=:_::.`.);  \\ __/ /" << RESET << std::endl;
    file << YELLOW  << "                      ,    `./  \\:. `.   )==-'  .  `" << RESET << std::endl;
    file << GREEN   << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << RESET << std::endl;
    file << PINK    << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << RESET << std::endl;
    file << GREEN   << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << RESET << std::endl;
    file << D_GREEN << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << RESET << std::endl;
    file << GREEN   << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << RESET << std::endl;
    file << PINK    << "              \\:  `  X` _| _,\\/'   .-'" << RESET << std::endl;
    file << YELLOW  << ".               \":._:`\\____  /:'  /      .           ." << RESET << std::endl;
    file << BROWN   << "                    \\::.  :\\/:'  /              +" << RESET << std::endl;
    file << BROWN   << "   .                 `.:.  /:'  }      ." << RESET << std::endl;
    file << BROWN   << "           .           ):_(:;   \\           ." << RESET << std::endl;
    file << BROWN   << "                      /:. _/ ,  |" << RESET << std::endl;
    file << BROWN   << "                   . (|::.     ,`                  ." << RESET << std::endl;
    file << BROWN   << "     .                |::.    {\\" << RESET << std::endl;
    file << BROWN   << "                      |::.\\  \\ `." << RESET << std::endl;
    file << BROWN   << "                      |:::(\\    |" << RESET << std::endl;
    file << BROWN   << "              O       |:::/{ }  |                  (o" << RESET << std::endl;
    file << CYAN    << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << RESET << std::endl;
    file << GREEN   << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << RESET << std::endl;
    file << D_GREEN << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << RESET << std::endl;
    file.close();
}
