/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BankAccount.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:20:07 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 14:20:08 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANKACCOUNT_HPP
# define BANKACCOUNT_HPP
# include <iostream>
# include <string>
class BankAccount
{
  public:
	BankAccount(const std::string &owner, double initBalance); // constructor
	void deposit(double amount);
	void withdraw(double amount);
    void printStatement(void) const;//wont change anything in  the object READ ONLY
    double getBalance(void) const;//getters READ only 
    std::string getOwner(void) const;
  private://private data dont want anyone to modification the data
  std::string _owner;
  double _balance;
    bool isValidAmount(double amount) const;//return TRUE or FALSE
};

#endif