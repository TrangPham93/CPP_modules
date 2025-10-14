/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:57:38 by trpham            #+#    #+#             */
/*   Updated: 2025/10/14 12:53:02 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

size_t RPN::size()
{
	return _fl.size();
}

/* new element only be inserted on top of stack */
void RPN::addNumber(int num)
{
	_fl.push(num);
}

/* only the top element can be accessed by top() and deleted by pop() */
void RPN::calculate(char op)
{
	double after = _fl.top();
	_fl.pop();
	double before = _fl.top();
	_fl.pop();
	double result = 0;
	
	if (op == '+')
		result = before + after;
	else if (op == '-')
		result = before - after;
	else if (op == '*')
		result = before * after;
	else if (op == '/')
	{
		if (after == 0)
			throw std::runtime_error(DIV_0_ERR);
		else
			result = before / after;
	}
	else
		throw std::runtime_error(INPUT_ERR);
	// std::cout << before << op << after << " = " << result<< std::endl;
	_fl.push(result);
}


void RPN::printFL()
{
	if (_fl.empty())
		return ;
	if (_fl.size() > 1)
		throw std::runtime_error(INPUT_ERR);
	std::cout << _fl.top() << std::endl;
}