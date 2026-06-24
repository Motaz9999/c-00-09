/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:56:43 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/24 20:04:50 by moodeh           ###   ########.fr       */
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
	this->_index = -1; // when added a new contact this add by 1
	std ::cout << "Created a PhoneBook" << std::endl;
}
// this is for adding a new contact
bool PhoneBook::add(void)
{
	this->_index++;
	if (this->_index > SIZE_OF_ARRAY)
		this->_index = 0; // start again from zero
    //so we start adding new contact so we need to take input from user and check on it and put inside the new contact i make 
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
void PhoneBook::printRow(const int &index, const std::string &firstName,
	const std::string &lastName, const std::string &nickName) const
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << index << "|" << std::setw(10) << firstName << "|" << std::setw(10) << lastName << "|" << std::setw(10) << nickName << std::endl;
}
//    index|  first name|   last name|   nickname
void PhoneBook::printContacts(void) const
{
	std::cout << std::right << std::setw(10) << std::setfill(' ') << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nick Name" << std::endl;
	for (int i = 0; i < Phone::PhoneBook::_index; i++)
	{
		printRow(i, _arr[i].getFirstName(), _arr[i].getLastName(),
			_arr[i].getNickName());
	}
}

void PhoneBook::search(void)
{
	int	index;

	std::string indexAsString;
	if (this->_index == -1) // no Added contact
	{
		std::cerr << "Error : there is no contacts in this book pleas add contact first ." << std::endl;
		return ;
	}
	this->printContacts();
	std ::cout << "Select index" << std::endl;
	if (!std::getline(std::cin, indexAsString))
	{
		std::cerr << "Error : Error or EOF reading input." << std::endl;
		return ;
	}
	if (!indexAsString.empty())
	{
		std::cerr << "Error : empty input." << std::endl;
		return ;
	}
	index = std::atoi(indexAsString.c_str());
	// the range must be from 0 to c
	if (index > 8 || index < 0)
	{
		std::cerr << "Error : there is no contact with this index pleas try again." << std::endl;
		return ;
	}
	std::cout << "\n";
	std::cout << std::setw(15) << "--- Contact Information ---" << std::endl;
	std::cout << std::setw(15) << "First Name: " << std::setw(15) << _arr[index].getFirstName() << std::endl;
	std::cout << std::setw(15) << "Last Name: " << std::setw(15) << _arr[index].getLastName() << std::endl;
	std::cout << std::setw(15) << "Nickname: " << std::setw(15) << _arr[index].getNickName() << std::endl;
	std::cout << std::setw(15) << "Phone Number: " << std::setw(15) << _arr[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(15) << "Darkest Secret: " << std::setw(15) << _arr[index].getDarkestSecrete() << std::endl;
}
} // namespace Phone
