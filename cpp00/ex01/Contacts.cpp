/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:05:38 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/25 20:06:59 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contacts.hpp"

namespace Phone
{
int Contacts::_countOfContacts = 0;

Contacts::Contacts(void)
{
	this->_darkestSecret.clear();
	this->_firstName.clear();
	this->_lastName.clear();
	this->_nickName.clear();
	this->_phoneNumber.clear();
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
	this->_firstName = name;
}

void Contacts::setLastName(std::string &name)
{
	this->_lastName = name;
}

void Contacts::setNickName(std::string &name)
{
	this->_nickName = name;
}

void Contacts::setPhoneNumber(std::string &str)
{
	this->_phoneNumber = str;
}

void Contacts::setDarkestSecrete(std::string &name)
{
	this->_darkestSecret = name;
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

std::string Contacts::getPhoneNumber(void) const
{
	return (this->_phoneNumber);
}

std::string Contacts::getDarkestSecrete(void) const
{
	return (this->_darkestSecret);
}

} // namespace Phone