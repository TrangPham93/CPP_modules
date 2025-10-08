/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:30:25 by trpham            #+#    #+#             */
/*   Updated: 2025/10/08 12:09:16 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void trimString(std::string& str)
{
	str.remove()	
}

static void checkInputFileFormat(std::fstream& inputFile, BitcoinExchange& exRate)
{
	std::string line;

	(void)exRate;
	// read file
	while (getline(inputFile, line))
	{
		std::cout << line << std::endl;	
		if (line == "date | value")
			continue;
		size_t index = line.find('|');
		if (index != std::string::npos)
		{
			std::string key = line.substr(0, index);
			std::string value = line.substr(index + 1, line.length() - index -1);
			std::cout << key << std::endl;	

			std::cout << value << std::endl;	

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
			checkInputFileFormat(inputFile, exRate);
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