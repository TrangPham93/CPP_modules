/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:52:16 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 15:33:08 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void processInput(char** av, PmergeMe& sequence)
{
	for (size_t i = 0; av[i]; i++)
	{
		size_t pos;
		std::string input = av[i];
		// check if input is integer with pos
		int num;
		try
		{
			num = std::stoi(input, &pos);
		}
		catch(const std::exception& e)
		{
			throw std::runtime_error(OVERFLOW_ERR);
		}

		if (pos != input.length())
			throw std::runtime_error(INPUT_ERR);
		if (num < 0)
			throw std::runtime_error(INPUT_ERR);
		sequence.addNumToVec(num);
	}
}

int main(int ac, char** av)
{
	if (ac < 2)
	{
		std::cerr << INPUT_ERR << std::endl;
		return EXIT_FAILURE;
	}
	
	av++;
	PmergeMe sequence;
	
	try
	{
		processInput(av, sequence);
		std::cout << "Before:	";
		sequence.printVec();
		sequence.sortVec();
		std::cout << "After:	";
		sequence.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// sequence.printVec();
	return EXIT_SUCCESS;
}