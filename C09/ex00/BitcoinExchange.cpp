/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:10:39 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 16:52:20 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::addPair(std::string& key, float& value)
{
	_dataMap.insert({key, value});
}

float	BitcoinExchange::getExRate(std::string date)
{
	auto it =_dataMap.find(date);
	if (it != _dataMap.end())
		return _dataMap[date];
	// while (it == _dataMap.end())
	// {
		
	// 	it = _dataMap.find(date);
	// }
	return (-1);	
}
