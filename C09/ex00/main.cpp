/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:30:25 by trpham            #+#    #+#             */
/*   Updated: 2025/10/13 15:42:25 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void trimString(std::string& str)
{
	const std::string whitespace = " \t\n\r\f\v";
	str.erase(0, str.find_first_not_of(whitespace));
	str.erase(str.find_last_not_of(whitespace) + 1);
}

std::string static validate(tm& inputDate)
{
	int day = inputDate.tm_mday;
	int month = inputDate.tm_mon + 1;
	int year = inputDate.tm_year + 1900;
	
	
	// check day negative?
	if (day < 1 || month < 1 || year < 1 || month > 12)
		return BAD_INPUT_ERR;
	// check leap year for Feb
	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0 ));
	if (month == 2)
	{
		if (isLeap && day > 29)
			return BAD_INPUT_ERR;
		else if (!isLeap && day > 28)
			return BAD_INPUT_ERR;
	}
	
	std::map<int, int> monthDays = {{1, 31}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, 
		{7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
	for (auto it = monthDays.begin(); it != monthDays.end(); it++)
	{
		if (it->first == month)
		{
			if (day > it->second)
				return BAD_INPUT_ERR;
		}
	}
	return "";
}

// read file line by line, check the input line and print to stdout
static void mappingInput(std::fstream& inputFile, BitcoinExchange& exRate)
{
	std::string line;

	while (getline(inputFile, line))
	{
		trimString(line);
		if (line == "date | value")
			continue;
		size_t index = line.find('|');
		if (index != std::string::npos)
		{
			std::string key = line.substr(0, index);
			trimString(key);
			std::string value = line.substr(index + 1, line.length() - index -1);
			trimString(value);
			// std::cout << "value: " << value << std::endl;
			if (value.empty() || key.empty())
			{
				std::cout << BAD_INPUT_ERR << "date or value is empty" << std::endl;
				continue;
			}
			
			float valueFloat;
			try
			{
				valueFloat = std::stof(value);
			}
			catch(const std::exception& e)
			{
				continue;
			}
			if (valueFloat <= 0)
			{
				std::cout << NEG_INPUT_ERR << std::endl;	
				continue;
			}
			else if (valueFloat >= 1000)
			{
				std::cout << TOO_LARGE_ERR << std::endl;	
				continue;
			}
			else
			{
				tm tm = {}; // initialize all value to 0 here
				std::istringstream ss(key);
				ss >> std::get_time(&tm, "%Y-%m-%d");
				if (ss.fail())
				{
					std::cout << BAD_INPUT_ERR << key << std::endl;
					continue;
				}
				std::string error = validate(tm);
				if (!error.empty())
				{
					std::cout << error << key << std::endl;
					continue;
				}
					
				float rate = exRate.getExRate(tm);
				if (rate == -1)
					std::cout << NO_UPDATED_RATE << std::endl;
				else
					std::cout << key << " => " << valueFloat << " = " 
						<< valueFloat * rate << std::endl;	
			}
		}
		else
		{
			std::cout << BAD_INPUT_ERR << line << std::endl;	
		}
	}
			
}

static void mappingData(BitcoinExchange& exRate)
{
	std::fstream dataFilePtr;

	dataFilePtr.open("data.csv", std::ios::in);
	if (dataFilePtr.is_open())
	{
		std::string line;
		while (getline(dataFilePtr, line))
		{
			trimString(line);
			if (line == "date,exchange_rate")
				continue;
			size_t splitPos = line.find(",");
			if (splitPos != std::string::npos)
			{
				std::string key = line.substr(0, splitPos);
				trimString(key);

				// Initialize a tm structure to hold the parsed date
				tm tm = {};
				// Create a string stream to parse the date string
				std::istringstream ss(key);
				// Parse the date string using std::get_time
				ss >> std::get_time(&tm, "%Y-%m-%d");
				// Check if parsing was successful
				if (ss.fail())
				{
					dataFilePtr.close();
					throw std::runtime_error(DATE_CONVERT_ERR);
				}
				// Convert the parsed date to a time_t value
				time_t date = mktime(&tm);
				std::string value = line.substr(splitPos + 1);
				trimString(value);
				float valueFloat = std::stof(value);
				try
				{
					exRate.addPair(date, valueFloat);
				}
				catch(const std::exception& e)
				{
					dataFilePtr.close();
					throw;
				}
			}
			else
			{
				dataFilePtr.close();
				throw std::runtime_error(BAD_INPUT_ERR);
			}
		}
		dataFilePtr.close();
	}
	else
		throw std::runtime_error(OPEN_FILE_ERR);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << OPEN_FILE_ERR << std::endl;
		return  EXIT_FAILURE;	
	}
	
	BitcoinExchange exRate;
	std::fstream inputFile;
	try
	{
		mappingData(exRate);
		inputFile.open(av[1], std::ios::in);		
		if (inputFile.is_open())
		{
			mappingInput(inputFile, exRate);
			inputFile.close();
		}
		else
			throw std::runtime_error(OPEN_FILE_ERR);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	return EXIT_SUCCESS;
}