/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrokenString.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 18:00:29 by moodeh            #+#    #+#             */
/*   Updated: 2026/07/07 18:11:41 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BrokenString.hpp"
#include <cstring>

BrokenString::BrokenString(std::string const &content) : _data(NULL),
	_size(static_cast<int>(content.size()))
{
	std::cout << "[BrokenString] Constructor: \"" << content << "\"" << std::endl;
	_data = new char[_size + 1];
	std::strcpy(_data, content.c_str()); // copy the content
}
BrokenString::~BrokenString()
{
	std::cout << "[BrokenString] Destructor: freeing \"" << (_data ? _data : "(null)") << "\" at " << static_cast<void *>(_data) << std::endl;
	delete[] _data;
}

std::string BrokenString::getContent() const {
    return std::string(_data ? _data : "");
}

void BrokenString::overwriteFirstChar(char c) {
    // Writes directly into the buffer at index 0 without reallocating.
    // If two BrokenString objects share this buffer, both will see the change.
    if (_data && _size > 0)
        _data[0] = c;
}

void BrokenString::print(std::string const& label) const {
    std::cout << "  " << label << ": \""
              << (_data ? _data : "(null)")
              << "\" at " << static_cast<void const*>(_data) << std::endl;
}