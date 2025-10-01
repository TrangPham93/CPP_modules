/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/10/01 12:05:34 by trpham           ###   ########.fr       */
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
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		
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
	float	num = std::stof(str);
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	
	if (num > std::numeric_limits<int>::max() 
		|| num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	
	// test for precision lost
	std::cout << "float: " << std::fixed << std::setprecision(1)
		<< num << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< static_cast<double>(num) << std::endl;
}

static void	convertFromDouble(std::string str)
{
	double num = std::stod(str);
	std::cout << "number: "<< num << std::endl;
	
	if (num < 32 || num > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	
	if (num > std::numeric_limits<int>::max() 
		|| num < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
	// test for precision lost
	float	f = static_cast<float>(num);
	if (static_cast<double>(f) != num)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1)
		<< static_cast<float>(num) << "f" << std::endl;
	
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< num << std::endl;
	
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
		{
			std::cout << "char\n"; 
			return TYPE_CHAR;
		}
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
		if (isDouble(str) == true)
		{
			std::cout << "float\n"; 
			return TYPE_FLOAT;
		}
		return UNKNOWN;
	}
	else if (isDouble(str))
	{
		std::cout << "double\n"; 
		return TYPE_DOUBLE;
	}
	else if (isOnlyDigitInput(str))
	{
		std::cout << "int\n"; 
		return TYPE_INT;
	}
	
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