/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:27:40 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/24 20:01:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# define SIZE_OF_ARRAY 8
# include "Contacts.hpp"
namespace Phone
{
class PhoneBook
{
  public:
	bool add();
	void search(void);
	void printContacts(void) const;

  private: // helper fun and data i dont show it to randoms
	Contacts _arr[SIZE_OF_ARRAY];
	int _index;
	void PhoneBook::printRow(const int &index, const std::string &firstName,
		const std::string &lastName, const std::string &nickName) const;
	std::string FormatColumn(std::string &str);
};
} // namespace Phone
#endif
