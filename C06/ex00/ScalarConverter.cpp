/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/09/25 19:12:40 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static void	printChar(std::string str)
{
	std::cout << "char: " << str << std::endl;
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<float>(str[0]) << std::endl;
	
}

static void	printDigit(int num)
{
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: Non displayable" << static_cast<char>(num) << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << static_cast<float>(num) << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	
}

void ScalarConverter::convert (std::string str)
{
	// check what is the input string
	// std::cout << str << std::endl; //convert str to double
	// if (str.length() == 1)
	// {
	// 	// if (str.length() != 3)
	// 	// 	throw std::runtime_error("Only handle 1 character");
		
	// 	if (str[0] < 32 || str[0] > 126)
	// 		throw std::runtime_error("Non-displayable character");
	// 	if (str[0] > 48 && str[0] < 57)
	// 		printDigit(str);
	// 	else
	// 	{
	// 		printChar(str);
	// 	}
	// }
	// else
	// {
	// 	printDigit(str);
	// 	// std::cout << "no thing" << std::endl; //convert str to double
		
	// }
	// std::stof(str); //convert str to float
	int	num = 0;
	for (int i = 0; i < str.length(); i++)
	{
		num = num * 10 + str[i];
	}
	printDigit(num);
	
}