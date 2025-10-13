/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:09:07 by trpham            #+#    #+#             */
/*   Updated: 2025/10/13 12:26:18 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <ctime>
#include <sstream>
#include <iomanip>

#define BAD_INPUT_ERR "Error: bad input => "
#define BAD_DATA_ERR "Error: data file is in incorrect form."
#define INSERT_MAP_ERR "Error: insert data map failed."
#define NO_UPDATED_RATE "Error: there is no updated rate within 30 days"
#define NEG_INPUT_ERR "Error: not a positive number."
#define TOO_LARGE_ERR "Error: too large a number."
#define OPEN_FILE_ERR "Error: could not open file."
#define DATE_CONVERT_ERR "Error: fail to convert to date."


/* Map: key-value pair, sorted by key, no duplicates of key 
	Multimap allows duplicated key, map doesn't */
class BitcoinExchange
{
private:
	std::map<time_t, float> _dataMap;
	
public:
	BitcoinExchange() = default;
	~BitcoinExchange()= default;
	BitcoinExchange(const BitcoinExchange& other)= default;
	BitcoinExchange& operator= (const BitcoinExchange& other)= default;

	void		addPair( time_t& key, float& value);
	float		getExRate(tm& date);
};
