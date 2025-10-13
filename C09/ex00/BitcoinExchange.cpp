/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:39 by trpham            #+#    #+#             */
/*   Updated: 2025/10/13 11:46:08 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::addPair(time_t& key, float& value)
{
	_dataMap.insert({key, value});
}

float	BitcoinExchange::getExRate(tm& tm)
{
	// Convert the parsed date to a time_t value
	time_t date = mktime(&tm);
	auto it =_dataMap.find(date);
	if (it != _dataMap.end())
	{
		return _dataMap[date];
	}

	for (int goBackUpTo = 30; goBackUpTo >= 0; goBackUpTo--)
	{
		tm.tm_mday = tm.tm_mday - 1;
		time_t newDate = mktime(&tm);
		auto it1 =_dataMap.find(newDate);
		if (it1 != _dataMap.end())
		{
			return _dataMap[newDate];
		}
	}
	
	return (-1);	
}
