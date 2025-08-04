/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 12:04:12 by trpham            #+#    #+#             */
/*   Updated: 2025/08/04 23:33:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit)
{
	initial_deposit = 0; //recheck
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

}

bool	Account::makeWithdrawal( int withdrawal )
{
	
}

int		Account::checkAmount( void ) const
{
	
}

void	Account::displayStatus( void ) const
{
	
}