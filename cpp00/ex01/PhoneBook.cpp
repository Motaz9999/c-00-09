/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:56:43 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/25 20:34:28 by moodeh           ###   ########.fr       */
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
	std::cout << "Created a PhoneBook" << std::endl;
}

void PhoneBook::checkOnInput(std::string &input)
{
	bool	valid;

	valid = false;
	while (!valid)
	{
		if (!std::getline(std::cin, input))
		{
			std::cerr << "Error : error in input please enter again :" << std::flush;
			;
			continue ;
		}
		if (input.empty())
		{
			std::cerr << "Error : empty value please enter again :";
			continue ;
		}
		valid = true;
	}
}

bool	checkOnNumber(std::string &str)
{
	if (str.empty())
	{
		std::cerr << "Error : empty input please enter again : " << std::flush;
		return (false);
	}
	if (str.length() < 7 || str.length() > 15)
	{
		std::cerr << "Error : phone number should be 7-15 digits long please enter again :" << std::flush;
		return (false);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit((char)str[i]))
		{
			std::cerr << "Error : input not valid please enter again :" << std::flush;
			return (false);
		}
	}
	return (true);
}

void PhoneBook::validNumber(std::string &input)
{
	bool	valid;

	valid = false;
	while (!valid)
	{
		if (!std::getline(std::cin, input))
		{
			std::cerr << "Error : error in input please enter again : " << std::flush;
			continue ;
		}
		if (input.empty())
		{
			std::cerr << "Error : empty value please enter again :" << std::flush;
			continue ;
		}
		if (!checkOnNumber(input))
		{
			continue ;
		}
		valid = true;
	}
}

// this is for adding a new contact
void PhoneBook::add(void)
{
	this->_index++;
	// start again from zero
	// here i want to add new contact to the array or OverWrite it
	std::cout << "Createing new Contact" << std::endl;
	std::string input;
	std::cout << "Enter the First name : " << std::flush;
	checkOnInput(input);
	this->_arr[this->_index % SIZE_OF_ARRAY].setFirstName(input);
	input.clear();
	std::cout << "Enter the Last name : " << std::flush;
	checkOnInput(input);
	this->_arr[this->_index % SIZE_OF_ARRAY].setLastName(input);
	input.clear();
	std::cout << "Enter the Nick name : " << std::flush;
	checkOnInput(input);
	this->_arr[this->_index % SIZE_OF_ARRAY].setNickName(input);
	input.clear();
	std::cout << "Enter the Darkest secret  : " << std::flush;
	checkOnInput(input);
	this->_arr[this->_index % SIZE_OF_ARRAY].setDarkestSecrete(input);
	input.clear();
	std::cout << "Enter the Phone Number  : " << std::flush;
	validNumber(input);
	this->_arr[this->_index % SIZE_OF_ARRAY].setPhoneNumber(input);
}

// phone fun
std::string PhoneBook::FormatColumn(const std::string str) const
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
	std::cout << std::right << std::setw(10) << std::setfill(' ') << index << "|" << std::setw(10) << FormatColumn(firstName) << "|" << std::setw(10) << FormatColumn(lastName) << "|" << std::setw(10) << FormatColumn(nickName) << std::endl;
}

//    index|  first name|   last name|   nickname
void PhoneBook::printContacts(void) const
{
	int counter;
	std::cout << std::right << std::setw(10) << std::setfill(' ') << "Index"
				<< "|" << std::setw(10) << "First Name"
				<< "|" << std::setw(10) << "Last Name"
				<< "|" << std::setw(10) << "Nick Name" << std::endl;
	if (this->_index >= SIZE_OF_ARRAY)
		counter = SIZE_OF_ARRAY - 1;
	else
		counter = this->_index;
	for (int i = 0; i <= counter; i++)
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
		std::cerr << "Error : there is no contacts in this book please add contact first ." << std::endl;
		return ;
	}
	this->printContacts();
	std::cout << "Select index" << std::endl;
	if (!std::getline(std::cin, indexAsString))
	{
		std::cerr << "Error : Error or EOF reading input." << std::endl;
		return ;
	}
	if (indexAsString.empty())
	{
		std::cerr << "Error : empty input." << std::endl;
		return ;
	}
	index = std::atoi(indexAsString.c_str());
	// the range must be from 0 to SIZE_OF_ARRAY
	if (index >= SIZE_OF_ARRAY || index < 0)
	{
		std::cerr << "Error : there is no contact with this index please try again." << std::endl;
		return ;
	}
	int max_index = (this->_index >= SIZE_OF_ARRAY) ? SIZE_OF_ARRAY - 1 : this->_index;
	if (index > max_index)
	{
		std::cerr << "Error : Cant find contact ." << std::endl;
		return ;
	}
	std::cout << "\n";
	std::cout << std::setw(15) << "--- Contact Information ---" << std::endl;
	std::cout << std::setw(15) << "First Name: " << _arr[index].getFirstName() << std::endl;
	std::cout << std::setw(15) << "Last Name: " << _arr[index].getLastName() << std::endl;
	std::cout << std::setw(15) << "Nickname: " << _arr[index].getNickName() << std::endl;
	std::cout << std::setw(15) << "Phone Number: " << _arr[index].getPhoneNumber() << std::endl;
	std::cout << std::setw(15) << "Darkest Secret: " << _arr[index].getDarkestSecrete() << std::endl;
}
} // namespace Phone
