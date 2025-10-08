/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:09:07 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 11:56:00 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>

/* Map: key-value pair, sorted by key, no duplicates of key */
class BitcoinExchange
{
private:
	std::map<std::string, float> _dataMap;
	
public:
	BitcoinExchange() = default;
	~BitcoinExchange()= default;
	BitcoinExchange(const BitcoinExchange& other)= delete;
	BitcoinExchange& operator= (const BitcoinExchange& other)= delete;

	void addPair(const std::string& key, const float& value);
	
};


