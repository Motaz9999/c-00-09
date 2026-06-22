/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BankAccount.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:20:09 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/22 15:14:05 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BankAccount.hpp"

// constructor its only job is to build the object
BankAccount::BankAccount(const std::string &owner, double initBalance)
{
    this->_owner = owner;
    if (initBalance < 0.0)
    {
        std::cerr << "Warning : u dont have enough amount to make a new account"<<std::endl;
        this->_balance = 0.0;
    }
    else
        this->_balance = initBalance;
    std::cout << "Account crated for : " << this->_owner << "\n| init amount : " << this->_balance << std::endl;
}

//helper to check on amount each time u withdraw or deposit
bool BankAccount::isValidAmount(double amount) const
{
    if (amount <= 0.0)
    {
        std :: cerr << "Error : amount must be greater than zero." << std::endl;
        return false;
    }
    return true;
}

//public 
void BankAccount::deposit(double amount)
{

    if (!isValidAmount(amount))
    return ;
    this->_balance += amount;
    std :: cout << "[DEPOSIT] +" << amount << "| new balance is " << this->_balance<< std::endl;
}

void BankAccount::withdraw(double amount)
{
    if (!isValidAmount(amount))
    return ;
    if (this->_balance - amount <= 0)
    {
        std ::cerr <<  "Error: insufficient funds. "
                  << "Balance: " << this->_balance
                  << " | Requested: " << amount << std::endl;
                  return ;
    }
    this->_balance -=amount;
        std :: cout << "[WITHDRAW] -" << amount << "| new balance is " << this->_balance<< std::endl;

}

void BankAccount::printStatement(void) const
{
    std::cout << "┌────────────────────────────┐" << std::endl;
    std::cout << "│  Account Owner : " << this->_owner   << std::endl;
    std::cout << "│  Balance       : " << this->_balance << std::endl;
    std::cout << "└────────────────────────────┘" << std::endl;
}

//getters used to access to private values of objs READ only
double BankAccount::getBalance(void) const
{
    return this->_balance;
}

std::string BankAccount::getOwner(void) const
{
    return this->_owner;
}
// void deposit(double amount);
// 	void withdraw(double amount);
//     void printStatement(void) const;//wont change anything in  the object READ ONLY
//     double getBalance(void) const;//getters READ only 
//     std::string getOwner(void) const;
//   private://private data dont want anyone to modification the data
//   std::string _owner;
//   double _balance;
//     bool isValidAmount(double amount) const;//return TRUE or FALSE //private