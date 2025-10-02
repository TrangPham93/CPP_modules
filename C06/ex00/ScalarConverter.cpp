/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/10/02 10:48:17 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
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
	try
	{
		int num = std::stoi(str);
		
		// char
		if (num < 32 || num > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
			
		// int
		std::cout << "int: " << num << std::endl;
		
		// float
		float f = static_cast<float>(num);
		if (static_cast<int>(f) != num)
			std::cout << "float: impossible" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(1)
			<< f << "f" << std::endl;
			
		// double
		double d = static_cast<double>(num);
		if (static_cast<int>(d) != num)
			std::cout << "double: impossible" << std::endl;
		else
			std::cout << "double: " << std::fixed << std::setprecision(1)
			<< d << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Int conversion overflow: " << e.what() << '\n';
	}
}

static void	convertFromFloat(std::string str)
{
	str.pop_back();
	int	countDigit = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			break;
		countDigit++;
	}
	if (countDigit >= 7)
		throw std::runtime_error("Conversion may result in precision loss, only receive input less than 7 significant decimal digits.");
	try
	{
		float	num = std::stof(str);
		// char
		if (num < 32 || num > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
		// int
		if (num > static_cast<float>(std::numeric_limits<int>::max())
			|| num < static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(num) << std::endl;
		
		// float
		std::cout << "float: " << std::fixed << std::setprecision(1)
			<< num << "f" << std::endl;
		
		// double 
		std::cout << "double: " << std::fixed << std::setprecision(1)
			<< static_cast<double>(num) << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << "Float conversion overflowed: " << e.what() << '\n';
	}
}

static void	convertFromDouble(std::string str)
{
	int	countDigit = 0;
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			break;
		countDigit++;
	}
	if (countDigit >= 7)
		throw std::runtime_error("Conversion may result in precision loss, only receive input less than 7 significant decimal digits.");
	try
	{
		double num = std::stod(str);
		
		// char
		if (num < 32 || num > 126)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
			
		// int
		if (num > std::numeric_limits<int>::max() 
			|| num < std::numeric_limits<int>::min())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(num) << std::endl;
			
		// float
		float	f = static_cast<float>(num);
		std::cout << "float: " << std::fixed << std::setprecision(1)
			<< f << "f" << std::endl;

		// double
		std::cout << "double: " << std::fixed << std::setprecision(1)
			<< num << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Double conversion overflowed: " << e.what() << '\n';
	}	
}

static void convertFromPseudo(std::string str)
{
	if (str == "nan" || str == "nanf" )
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
	{
		if (str.back() == 'f' && str[str.length() - 2] == 'f')
			str.pop_back();
		
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << "f" << std::endl;
		std::cout << "double: " << str << std::endl;
	}
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

static bool isDouble(std::string str)
{
	unsigned int	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
	}

	bool hasDigit = false;
	bool hasDot = false;
	for (; i < str.length(); i++ )
	{
		if (isdigit(str[i]))
			hasDigit = true;
		else if (str[i] == '.' && !hasDot && hasDigit)
			hasDot = true;
		else
			return false;
	}

	return hasDot;
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
	else if ((str.length() == 3 && str == "nan") 
		|| (str.length() == 4 && (str == "nanf" || str == "+inf" 
			|| str == "-inf"))
		|| (str.length() == 5 && (str == "+inff" || str == "-inff")))
		return SPECIALS;
	else if ((str.back() == 'f' || str.back() == 'F'))
	{
		str.pop_back();
		if (isDouble(str) == true)
			return TYPE_FLOAT;
		return UNKNOWN;
	}
	else if (isDouble(str))
		return TYPE_DOUBLE;
	else if (isOnlyDigitInput(str))
		return TYPE_INT;
	
	return UNKNOWN;
}

void ScalarConverter::convert (std::string str)
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