/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:30:25 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 15:13:51 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void trimString(std::string& str)
{
	const std::string whitespace = " \t\n\r\f\v";
	try
	{
		str.erase(0, str.find_first_not_of(whitespace));
		str.erase(str.find_last_not_of(whitespace) + 1);
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

static void mappingInput(std::fstream& inputFile, BitcoinExchange& exRate)
{
	std::string line;

	(void)exRate;
	// read file
	while (getline(inputFile, line))
	{
		// std::cout << line << std::endl;	
		if (line == "date | value")
			continue;
		size_t index = line.find('|');
		if (index != std::string::npos)
		{
			std::string key = line.substr(0, index);
			trimString(key);
			std::string value = line.substr(index + 1, line.length() - index -1);
			trimString(value);
			float valueFloat;
			try
			{
				valueFloat = std::stof(value);
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: " << e.what() << '\n';
			}
		std::cout << key << " => " << valueFloat << " = " << valueFloat << std::endl;	
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;	
		}
	}
			
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return  EXIT_FAILURE;	
	}
	BitcoinExchange exRate;
	try
	{
		std::fstream inputFile;
		inputFile.open(av[1], std::ios::in);		
		if (inputFile.is_open())
		{
			mappingInput(inputFile, exRate);
			inputFile.close();
		}
		else
			throw std::runtime_error("could not open file.");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return EXIT_SUCCESS;
}