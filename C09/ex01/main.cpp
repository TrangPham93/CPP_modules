/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:57:07 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 12:53:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*' );
}

/* add check for single input only */
static void processInput(std::string input, RPN& rpn)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (isdigit(input[i]))
		{
			int num = input[i] - '0';
			rpn.addNumber(num);
		}
		else if (isOperator(input[i]))
		{
			if (rpn.size() >= 2)
				rpn.calculate(input[i]);
			else
				throw std::runtime_error(INPUT_ERR);
		}
		else if (input[i] == ' ')
			continue;
		else
			throw std::runtime_error(OTHER_ERR);
	}
}


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << INPUT_ERR << std::endl;
		return EXIT_FAILURE;
	}
	
	std::string input = av[1];
	RPN rpn;
	try
	{
		processInput(input, rpn);
		rpn.printFL();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}