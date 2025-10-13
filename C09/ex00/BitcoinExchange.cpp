/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:39 by trpham            #+#    #+#             */
/*   Updated: 2025/10/13 15:41:42 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* returns a pair, with its member pair::first set to an iterator pointing to either
 the newly inserted element or to the element that already had its same value in the 
 map. The pair::second element in the pair is set to true if a new element was 
 inserted or false if an element with the same value existed */
void BitcoinExchange::addPair(time_t& key, float& value)
{
	if (_dataMap.insert({key, value}).second == false)
		throw std::runtime_error(INSERT_MAP_ERR);
}

float	BitcoinExchange::getExRate(tm& tm)
{
	// Convert the parsed date to a time_t value
	time_t date = mktime(&tm);
	auto it =_dataMap.find(date);
	if (it != _dataMap.end())
		return _dataMap[date];

	for (int goBackUpTo = 30; goBackUpTo > 0; goBackUpTo--)
	{
		tm.tm_mday = tm.tm_mday - 1;
		time_t newDate = mktime(&tm);
		auto it1 =_dataMap.find(newDate);
		if (it1 != _dataMap.end())
			return _dataMap[newDate];
	}
	return (-1);	
}
