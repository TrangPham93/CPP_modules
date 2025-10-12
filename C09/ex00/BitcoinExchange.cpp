/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:39 by trpham            #+#    #+#             */
/*   Updated: 2025/10/10 17:09:37 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::addPair(time_t& key, float& value)
{
	_dataMap.insert({key, value});
}

float	BitcoinExchange::getExRate(time_t date)
{
	auto it =_dataMap.find(date);
	if (it != _dataMap.end())
	{
		return _dataMap[date];
		
	}
	while (condition)
	{
		time(&date);
		date.tm_date
	}
	
	return (-1);	
}
