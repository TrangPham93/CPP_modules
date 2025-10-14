/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:52:16 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 14:33:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void processInput(std::string input, PmergeMe sequence)
{
	for (size_t i = 0; input[i]; i++)
	{
		// int num = std::stoi
		sequence.addNumToVec(input[i]);
		std::cout << input << std::endl;
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
	std::cout << av << std::endl;
	std::string input = *av;
	PmergeMe sequence;
	try
	{
		processInput(input, sequence);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return EXIT_SUCCESS;
}