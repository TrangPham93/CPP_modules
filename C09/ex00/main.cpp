/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:30:25 by trpham            #+#    #+#             */
/*   Updated: 2025/10/07 17:25:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// static void checkInputFileFormat(std::fstream& inputFile)
// {
	
// }

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: could not open file." << std::endl;
		return  EXIT_FAILURE;	
	}

	try
	{
		std::fstream inputFile;
		inputFile.open(av[1], std::ios::in);
		std::string line;
		// BitcoinExchange newBit;
		
		if (inputFile.is_open())
		{
			// read file
			while (getline(inputFile, line))
			{
				std::cout << line << std::endl;	
			}
			
			// checkInputFileFormat(inputFile);
			// newBit.addPair();
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