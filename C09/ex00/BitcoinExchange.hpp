/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:09:07 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 15:20:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <bits/stdc++.h>

/* Map: key-value pair, sorted by key, no duplicates of key 
	Multimap allows duplicated key, map doesn't */
class BitcoinExchange
{
private:
	std::map<std::string, float> _dataMap;
	
public:
	BitcoinExchange() = default;
	~BitcoinExchange()= default;
	BitcoinExchange(const BitcoinExchange& other)= delete;
	BitcoinExchange& operator= (const BitcoinExchange& other)= delete;

	void		addPair( std::string& key, float& value);
	// std::string	getDate();
	float		getExRate(std::string date);
};

enum ErrorCode
{
	BAD_INPUT_ERR,
	NEG_INPUT_ERR,
	TOO_LARGE_ERR,
	UNKNOWN
};