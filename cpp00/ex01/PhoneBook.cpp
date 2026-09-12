/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:56:43 by moodeh            #+#    #+#             */
/*   Updated: 2026/09/12 19:18:18 by moodeh           ###   ########.fr       */
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

bool PhoneBook::checkOnInput(std::string &input)
{
	while (!true)
	{
		if (!std::getline(std::cin, input))
			return (false);
		if (input.empty())
		{
			std::cerr << "Error : empty value please enter again :";
			continue ;
		}
		return (true);
	}
}

bool	checkOnNumber(std::string &str)
{
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

bool PhoneBook::validNumber(std::string &input)
{
	while (true)
	{
		if (!std::getline(std::cin, input))
			return (false);
		if (input.empty())
		{
			std::cerr << "Error : empty value please enter again :" << std::flush;
			continue ;
		}
		if (!checkOnNumber(input))
			continue ;
		return (false);
	}
}

// this is for adding a new contact
void PhoneBook::add(void)
{
	int	curr;

	this->_index++;
	// start again from zero
	// here i want to add new contact to the array or OverWrite it
	curr = this->_index % SIZE_OF_ARRAY;
	std::string input;
	std::cout << "Enter the First name : " << std::flush;
	if (!checkOnInput(input))
		return ;
	this->_arr[curr].setFirstName(input);
	std::cout << "Enter the Last name : " << std::flush;
	if (!checkOnInput(input))
		return ;
	this->_arr[curr].setLastName(input);
	std::cout << "Enter the Nick name : " << std::flush;
	if (!checkOnInput(input))
		return ;
	this->_arr[curr].setNickName(input);
	std::cout << "Enter the Darkest secret : " << std::flush;
	if (!checkOnInput(input))
		return ;
	this->_arr[curr].setDarkestSecrete(input);
	std::cout << "Enter the Phone Number : " << std::flush;
	if (!validNumber(input))
		return ;
	this->_arr[curr].setPhoneNumber(input);
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
	counter = (this->_index >= SIZE_OF_ARRAY) ? (SIZE_OF_ARRAY - 1) : this->_index;

	for (int i = 0; i <= counter; i++)
		printRow(i, _arr[i].getFirstName(), _arr[i].getLastName(), _arr[i].getNickName());
}

void PhoneBook::search(void)
{
	
    if (this->_index == -1)
        {
            std::cerr << "Error : no contacts in this book. Please add a contact first." << std::endl;
            return ;
        }
    this->printContacts();
        
    std::cout << "Select index: ";
    std::string input;
    if (!std::getline(std::cin, input))
            return ;

    if (input.empty() || input.length() > 1 || !std::isdigit(input[0]))
        {
            std::cerr << "Error : invalid index format." << std::endl;
            return ;
        }
        
    int index = input[0] - '0';
    int max_index = (this->_index >= SIZE_OF_ARRAY) ? SIZE_OF_ARRAY - 1 : this->_index;  
    if (index > max_index || index < 0)
        {
            std::cerr << "Error : Contact index out of range." << std::endl;
            return ;
        }
        
        std::cout << "\n" << std::setw(15) << "--- Contact Information ---" << std::endl;
        std::cout << std::setw(15) << "First Name: " << _arr[index].getFirstName() << std::endl;
        std::cout << std::setw(15) << "Last Name: " << _arr[index].getLastName() << std::endl;
        std::cout << std::setw(15) << "Nickname: " << _arr[index].getNickName() << std::endl;
        std::cout << std::setw(15) << "Phone Number: " << _arr[index].getPhoneNumber() << std::endl;
        std::cout << std::setw(15) << "Darkest Secret: " << _arr[index].getDarkestSecrete() << std::endl;
    }
} // namespace Phone
