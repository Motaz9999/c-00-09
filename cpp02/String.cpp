/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   String.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 23:17:42 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/08 00:09:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "String.hpp"
#include <cstring>

// class String
// {
//     private:
//     char *_data;
//     int _length;
//     public:
//     String();
//       String(std::string const& content);
//     String(String const &other);//copy constructor
//     String &operator=(String const & other);
//     ~String();
// };

String::String() : _data(NULL), _length(0)
{
	std::cout << "[String] Default constructor" << std::endl;
	_data = new char[1];
	_data[0] = '\0';
}

//
String::String(std::string const &content) : _data(NULL),
	_length(static_cast<int>(content.size()))
{
	std::cout << "[String] Parameterized constructor: \"" << content << "\"" << std::endl;
	_data = new char[_length + 1];
	_data[_length] = '\0';
	std::strcpy(_data, content.c_str());
}

// copy constructor
String::String(String const &other) : _data(NULL), _length(other._length)
{
	std::cout << "[String] Copy constructor: deep-copying \"" << other._data << "\"" << std::endl;
	_data = new char[_length + 1];
	_data[_length] = '\0';
	std::strcpy(_data, other._data);
}

// copy assignment operator
// replace this obj content with other content independent
String &String::operator=(String const &other)
{
	std::cout << "[String] Copy assignment operator" << std::endl;
	if (this == &other)
	{
		std::cout << "  (self-assignment — no-op)" << std::endl;
		return (*this);
	}
	_length = other._length;
	delete[] _data;
	_data = NULL;
	_data = new char[_length + 1];
	_data[_length] = '\0';
	std::strcpy(_data, other._data);
	std::cout << "  Assigned: \"" << _data << "\"" << std::endl;
	return (*this); // return data not the address
}

String::~String()
{
	std::cout << "[String] Destructor: freeing \"" << (_data ? _data : "(null)") << "\"" << std::endl;
	delete[] _data;
	_data = NULL;
}

// std::string getContent() const;
// int getLength() const;
// void setContent(std::string const &s);
// void print(std::string const &label) const;
// make an obj string of _data if it exist
std::string String::getContent() const
{
	return (std::string(_data ? _data : ""));
}

int String::getLength() const
{
	return (_length);
}
void String::setContent(std::string const &s)
{
	delete[] _data;
	_data = NULL;
	_length = (static_cast<int>(s.size()));
	_data = new char[_length + 1];
	_data[_length] = '\0';
	std::strcpy(_data, s.c_str());
}
void String::print(std::string const &label) const
{
	std::cout << "  " << label << ": \"" << (_data ? _data : "(null)") << "\" (addr: " << static_cast<void const *>(_data) << ")" << std::endl;
}