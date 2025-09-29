/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/09/29 15:51:47 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static void	convertFromFloat(std::string str)
{
	int	num = 0;
	int sign = 1;
	
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			sign = -1;
			continue;
		}
		num = num * 10 + str[i] - '0';
	}
	num = num * sign;
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	
}

static void	convertFromDouble(std::string str)
{
	int	num = 0;
	int sign = 1;
	
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			sign = -1;
			continue;
		}
		num = num * 10 + str[i] - '0';
	}
	num = num * sign;
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	
}

static void	convertFromChar(std::string str)
{
	char	num = str[0];
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << num << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	
}

static void	convertFromInt(std::string str)
{
	int	num = 0;
	int sign = 1;
	
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '-')
		{
			sign = -1;
			continue;
		}
		num = num * 10 + str[i] - '0';
	}
	num = num * sign;
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
	
}

static bool	isOnlyDigitInput(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if ( i == 0 && str[i] == '-')
				continue;
			else
				return false;
		}
	}
	return true;
}

eType getInputType(std::string str)
{
	if (str.length() == 1)
	{
		if (str[0] >= '0' && str[0] <= '9')
			return TYPE_INT;
		else
			return TYPE_CHAR;
	}
	
	if (isOnlyDigitInput(str))
		return TYPE_INT;
	
		// how to determine if it's double or float
	if ()
	
	
	return UNKNOWN;
}

void ScalarConverter::convert (std::string str)
{
	
	std::cout << "str: " << str << std::endl;
	
	try
	{
		switch (getInputType(str))
		{
		case TYPE_CHAR:
			convertFromChar(str);
			break;
		case TYPE_INT:
			convertFromInt(str);
			break;
		case TYPE_FLOAT:
			convertFromFloat(str);
			break;
		case TYPE_DOUBLE:
			convertFromDouble(str);
			break;
		default:
			throw std::runtime_error("Incorrect input");
			break;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}