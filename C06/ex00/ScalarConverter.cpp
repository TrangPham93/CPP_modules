/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:51 by trpham            #+#    #+#             */
/*   Updated: 2025/09/25 11:09:01 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert (std::string str)
{
	// check what is the input string
	std::cout << std::stod(str) << std::endl; //convert str to double
	std::stof(str); //convert str to float
	
}