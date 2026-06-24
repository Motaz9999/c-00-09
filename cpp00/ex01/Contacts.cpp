/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:05:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/24 19:58:39 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

namespace Phone
{
int Contacts::_countOfContacts = 0;

Contacts::Contacts(void) : _id(_countOfContacts)
{
	this->_darkestSecret.clear();
	this->_firstName.clear();
	this->_lastName.clear();
	this->_nickName.clear();
	this->_phoneNumber = NULL;
	_countOfContacts++;
}

Contacts::~Contacts(void)
{
	_countOfContacts--;
}
// private:
// std::string _firstName;
// std::string _lastName;
// std::string _nickName;
// std::string _darkestSecret;
// int			_phoneNumber;
// const int	_id;
// static int	_countOfContacts;
void Contacts::setFirstName(std::string &name)
{
	if (!name.empty())
	{
		std ::cout << "Error : empty input" << std::endl;
		return ;
	}
	this->_firstName = name;
}

void Contacts::setLastName(std::string &name)
{
	if (!name.empty())
	{
		std ::cout << "Error : empty input" << std::endl;
		return ;
	}
	this->_lastName = name;
}

void Contacts::setNickName(std::string &name)
{
	if (!name.empty())
	{
		std ::cout << "Error : empty input" << std::endl;
		return ;
	}
	this->_nickName = name;
}

void Contacts::setPhoneNumber(std::string &str)
{
	int	number;

	if (!checkOnNumber(str))
	{
		return ;
	}
	number = std::atoi(str.c_str());
	this->_phoneNumber = number;
}

void Contacts::setDarkestSecrete(std::string &name)
{
	if (!name.empty())
	{
		std ::cout << "Error : empty input" << std::endl;
		return ;
	}
	this->_darkestSecret;
}

bool Contacts::checkOnNumber(std::string &str)
{
	if (str.empty())
	{
		std::cerr << "Error : empty input" << std ::endl;
		return (false);
	}
	for (size_t i = 0; i < str.length(); i++)
	{
		if (std::isdigit((char)str[i]))
		{
			std::cerr << "Error : input not valid" << std::endl;
			return (false);
		}
	}
	return (true);
}

std::string Contacts::getFirstName(void) const
{
	return (this->_firstName);
}

std::string Contacts::getLastName(void) const
{
	return (this->_lastName);
}

std::string Contacts::getNickName(void) const
{
	return (this->_nickName);
}

int Contacts::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contacts::getDarkestSecrete(void) const
{
	return (this->_darkestSecret);
}

} // namespace Phone