/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/09/30 23:35:15 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

static void	convertFromFloat(std::string str)
{
	str.pop_back();
	float	num = std::stof(str);
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< num << "f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void	convertFromDouble(std::string str)
{
	double num = std::stod(str);
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	
	if (num > INT_MAX || num < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	
	if (num > __FLT_MAX__ || num < __FLT_MIN__)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	
	std::cout << "double: " << num << std::endl;
	
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
	std::cout << "double: "  << std::fixed << std::setprecision(1)
		<< static_cast<double>(num) << std::endl;
}

static void	convertFromInt(std::string str)
{
	long long	num = 0;
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
	if (num > INT_MAX)
		throw std::range_error("Int: overflow");
	else if (num < INT_MIN)
		throw std::range_error("Int: underflow");	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

static void convertFromPseudo(std::string str)
{
	(void)str;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

static bool	isOnlyDigitInput(std::string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if ( i == 0 && (str[i] == '-' || str[i] == '+'))
				continue;
			else
				return false;
		}
	}
	return true;
}

static bool isDoulbe(std::string str)
{
	// if (str.back() == 'f' || str.back() == 'F')
	// 	str.pop_back();
	// else
	// 	return false;
	
	return true;
}

eType getInputType(std::string str)
{
	if (str.length() == 1)
	{
		if (isdigit(str[0]))
			return TYPE_INT;
		else
			return TYPE_CHAR;
	}
	else if ((str.length() == 3 && (str == "nan" || str == "inf")) 
		|| (str.length() == 4 && (str == "nanf" || str == "+inf" 
			|| str == "-inf"))
		|| (str.length() == 5 && (str == "+inff" || str == "-inff")))
		{
			std::cout << "special\n"; 
			return SPECIALS;
		}
	else if ((str.back() == 'f' || str.back() == 'F'))
	{
		str.pop_back();
		if (isDoulbe(str) == true)
		{
			std::cout << "float\n"; 
			return TYPE_FLOAT;
		}
		return UNKNOWN;
	}
	else if (str.find('.') != std::string::npos 
		|| str.find('e') != std::string::npos 
		|| str.find('E') != std::string::npos)
		{
			std::cout << "double\n"; 
			return TYPE_DOUBLE;
		}
	else if (isOnlyDigitInput(str))
		return TYPE_INT;
	
	return UNKNOWN;
}

void ScalarConverter::convert (std::string str)
{
	
	// std::cout << "str: " << str << std::endl;
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
		case SPECIALS:
			convertFromPseudo(str);
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