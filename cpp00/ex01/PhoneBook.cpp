/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:56:43 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/24 19:17:02 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

// used for
// std::setw(n) sets the min field width for next output Reset after used once
// its like u have 10chars and how much u use of them (the word after it) put spaces
//(just in case the word is smaller that the n  i want)
// std::setfill sets the padding chars (default is ' ') stays until u change it

// std::right right-align content within thefield width //stays
// std::left ...

//  public :
//     bool add();
//     Contacts search();
//     void exit();
//     void printContacts(void);
//     private://helper fun and data i dont show it to randoms
//     Contacts arr[SIZE_OF_ARRAY];
//     int index;

namespace Phone
{
PhoneBook::PhoneBook(void)
{
	std ::cout << "Create PhoneBook" << std::endl;
}
bool	add(void)
{
}
// private fun
std::string FormatColumn(std::string &str)
{
	if (str.size() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
}
// private fun
void PhoneBook::printRow(const int &index,const std::string &firstName,
	const std::string &lastName, const std::string &nickName) const
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << index << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickName << std::endl;
}
//    index|  first name|   last name|   nickname
void PhoneBook::printContacts(void) const
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name"<< "|" << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < Phone::PhoneBook::_index; i++)
	{
        printRow( i, _arr[i].getFirstName() , _arr[i].getLastName(),_arr[i].getNickName() );
	}
}

int PhoneBook::search(int index)
{
}
} // namespace Phone
