/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:16:04 by moodeh            #+#    #+#             */
/*   Updated: 2026/06/26 23:52:06 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
//	int				_accountIndex;
// int				_amount;
// int				_nbDeposits;
// int				_nbWithdrawals;

Account::Account(void)
{
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += this->_amount;
}
// when i create the account it must have amount
//[19920104_091532] index:0;amount:47;created
Account::Account(int initial_deposit)
{
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_accountIndex = _nbAccounts;
	if (initial_deposit < 0)
	{
		this->_amount = 0;
	}
	else
	{
		this->_amount = initial_deposit;
		_totalAmount += this->_amount;
	}
	Account::_displayTimestamp();
    _nbAccounts++;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}
void Account::_displayTimestamp(void)
{
	std::time_t rawTime = std::time(NULL);
	// take time from the system as raw secounds from 78 till today
	std::tm *timeInfo = std::localtime(&rawTime);
	// make it look like local time
	char buffer[20]; // to but the number in
	std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
	std::cout << "[" << buffer << "]" << std::flush;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void)
{
	Account::_totalAmount -= this->_amount;
	Account::_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

int Account::checkAmount(void) const
{
    return this->_amount;
}
// void	makeDeposit( int deposit );
// bool	makeWithdrawal( int withdrawal );
// int		checkAmount( void ) const;
// void	displayStatus( void ) const;
//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	if (deposit < 0)
		return ;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		- deposit << ";deposit:" << deposit << ";amount:" << this->_amount << ";nb_deposits:" << this->_nbDeposits << std::endl;
}
//[19920104_091532] index:0;p_amount:47;withdrawal:refused
//[19920104_091532] index:1;amount:819;deposits:1;withdrawals:0
//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std ::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_totalAmount -= withdrawal;
	this->_amount -= withdrawal;
	std ::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount
		+ withdrawal << ";withdrawal:" << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}

//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

//[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}
