/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:15:04 by trpham            #+#    #+#             */
/*   Updated: 2025/09/25 18:30:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: no input.\nUsage: ./converter [args: char in single quote, int, double, float with suffix .f]" << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string input = av[1];
	try
	{
		ScalarConverter::convert(input);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	return EXIT_SUCCESS;
}