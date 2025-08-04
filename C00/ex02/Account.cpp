/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:04:12 by trpham            #+#    #+#             */
/*   Updated: 2025/08/05 00:00:04 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	initial_deposit = 0; //recheck
	this->_totalNbDeposits = 0;
}

Account::~Account(void){}

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
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	std::cout << getNbAccounts() << ";"
		<< getTotalAmount() << ";"
		<< getNbDeposits() << ";"
		<< getNbWithdrawals() << std::endl;
}
	
void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits = deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_nbWithdrawals = withdrawal;
	Account::_totalNbWithdrawals++;
}

int		Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{
	
}