/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:02 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/24 19:12:21 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP
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
	int _phoneNumber;
	const int _id;
	static int _countOfContacts;
	bool checkOnNumber(std::string &str);
	void setPhoneNumber(std::string &str);
	void setNickName(std::string &name);
	void setLastName(std::string &name);
	void setFirstName(std::string &name);

  public:
	int getPhoneNumber(void) const;
	std::string getNickName(void) const;
	std::string getLastName(void) const;
	std::string getFirstName(void) const;

	Contacts();
	~Contacts();
};
} // namespace Phone
#endif