/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/25 20:05:05 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP
# include <cstdlib>
# include <iostream>

namespace Phone
{
class Contacts
{
  private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _darkestSecret;
	std::string _phoneNumber;
	static int _countOfContacts;

  public:
	std::string getPhoneNumber(void) const;
	std::string getNickName(void) const;
	std::string getLastName(void) const;
	std::string getFirstName(void) const;
	std::string getDarkestSecrete(void) const;
	void setPhoneNumber(std::string &str);
	void setNickName(std::string &name);
	void setLastName(std::string &name);
	void setFirstName(std::string &name);
	void setDarkestSecrete(std::string &name);
	Contacts();
	~Contacts();
};
} // namespace Phone
#endif