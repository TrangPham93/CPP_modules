/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:09:07 by trpham            #+#    #+#             */
/*   Updated: 2025/10/10 17:03:30 by trpham           ###   ########.fr       */
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
	BitcoinExchange(const BitcoinExchange& other)= delete;
	BitcoinExchange& operator= (const BitcoinExchange& other)= delete;

	void		addPair( time_t& key, float& value);
	// std::string	getDate();
	float		getExRate(time_t date);
};
