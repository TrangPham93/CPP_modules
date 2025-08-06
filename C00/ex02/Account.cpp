/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:04:12 by trpham            #+#    #+#             */
/*   Updated: 2025/08/06 18:06:29 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0; // indexing
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
	
Account::Account(int initial_deposit)
	:	_accountIndex(_nbAccounts), 
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<<  "withdrawals:" << getNbWithdrawals() << std::endl;
}
	
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (deposit > 0)
	{
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		this->_amount += deposit;
		Account::_totalAmount += deposit;
	}
	std::cout << ";deposit:" << deposit << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal < 0 || withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	if (withdrawal > 0 && withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
	}
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return Account::_amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";" 
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << std::endl;
}

// std::cout << "[19920104_091532]";
// diff outfile log
void	Account::_displayTimestamp( void )
{
	char	output[20];
	time_t	timmestamp;
	struct tm *datetime;
	
	time(&timmestamp);
	datetime = localtime(&timmestamp);
	strftime(output, 20, "%Y%m%d_%H%M%S", datetime);
	std::cout << "[" << output << "] ";
}